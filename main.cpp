#include <iostream>
#include <Windows.h>

DWORD pid;
DWORD healthAdress = 0x007F55E4;


int main()
{
	SetConsoleTitleA("AC Infinite Health");
	if (!GetWindowThreadProcessId(FindWindowA(NULL, "AssaultCube"), &pid))
	{
		std::cout << "Failed to obtain Process ID, womp womp." << std::endl;
		Sleep(1000);
		return 1;
	}

	else
	{
		std::cout << "ProcessID: " << pid << std::endl;
		Sleep(1000);
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL)
	{
		std::cout << "Failed to Open Process, try running with administrator." << std::endl;
		Sleep(1000);
		return 1;
	}


	int newHealth = 2350;

	while (true)
	{

		if (WriteProcessMemory(hProcess, (LPVOID)healthAdress, &newHealth, sizeof(newHealth), NULL))
		{
			std::cout << "Health updated to 2350!" << std::endl;
		}
		else
		{
			std::cout << "Failed to write memory, exiting..." << GetLastError() << std::endl;
			Sleep(2000);
			return 1;
		}
		Sleep(1000);
	}

	CloseHandle(hProcess);
	return 0;
}
