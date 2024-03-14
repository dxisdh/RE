#include<iostream>
#include<string>
#include<windows.h>
#include<TlHelp32.h>
using namespace std;

bool TerminateProcessByName(const wstring& processName)
{
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		cout << "Error.\n";
		return false;
	}
	
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	if(!Process32First(hProcessSnap, &pe32))
	{
		cout << "Error.\n";
		CloseHandle(hProcessSnap);
		return false;
	}

	bool foundProcess = false;
	do
	{
		wstring currentProcessName = pe32.szExeFile;
		if(currentProcessName == processName)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
			if(hProcess != NULL)
			{
				if(TerminateProcess(hProcess, 0))
				{
					wcout << "Process '" << processName << "' terminated.\n";
					foundProcess = true;
				}
				else
				{
					wcout << "Can't terminate process '" << processName << "'.\n";
					return false;
				}
				CloseHandle(hProcess);
			}
		}
	} while (Process32Next(hProcessSnap, &pe32));

	CloseHandle(hProcessSnap);

	if(!foundProcess)
	{
		wcout << "Can't find process '" << processName << "'.\n";
	}
	return foundProcess;
}

bool TerminateProcessByID(DWORD processID)
{
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
	if(hProcess != NULL)
	{
		if(TerminateProcess(hProcess, 0))
		{
			cout << "Process with process ID " << processID << " terminated.\n";
			CloseHandle(hProcess);
			return true;
		}
		else
		{
			cout << "Can't terminate process with process ID " << processID << ".\n";
			return false;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "taskkill <method> <parameter>\n";
		cout << "Method:\n";
		cout << " -name <process name>\n";
		cout << " -id <process ID>\n";
		return 1;
	}

	string method = argv[1];
	string parameter = argv[2];

	if (method == "-name")
	{
		wstring processName(parameter.begin(), parameter.end());
		TerminateProcessByName(processName);
	}
	else if (method == "-id")
	{
		DWORD processID = stoi(parameter);
		TerminateProcessByID(processID);
	}
	return 0;
}
