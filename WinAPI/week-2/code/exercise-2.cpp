#include<iostream>
#include<windows.h>
using namespace std;

void ListExecutableMemoryRegions(DWORD processID)
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
	if(hProcess == NULL)
	{
		cout << "Failed to open process.\n";
	}

	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);

	MEMORY_BASIC_INFORMATION memoryInfo;
	LPVOID memoryAddress = systemInfo.lpMinimumApplicationAddress;
	while(memoryAddress < systemInfo.lpMaximumApplicationAddress)
	{
		if(VirtualQueryEx(hProcess, memoryAddress, &memoryInfo, sizeof(memoryInfo)))
		{
			if(memoryInfo.Protect == PAGE_EXECUTE_READWRITE)
			{
				cout << "Base Address: " << memoryInfo.BaseAddress << endl;
				cout << "Allocation Base: " << memoryInfo.AllocationBase << endl;
				cout << "Allocation Protect: " << memoryInfo.AllocationProtect << endl;
				cout << "State: " << memoryInfo.State << endl;
				cout << "Protect: " << memoryInfo.Protect << endl;
				cout << "Type: " << memoryInfo.Type << endl;
			}
			memoryAddress = static_cast<LPVOID>(static_cast<char*>(memoryAddress) + memoryInfo.RegionSize);
		} else {
			break;
		}
	}
	CloseHandle(hProcess);
}

int main()
{
	DWORD processID;
	cout << "Enter PID: ";
	cin >> processID;
	ListExecutableMemoryRegions(processID);
}
