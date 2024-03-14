#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
using namespace std;

void printRunningProcesses()
{
    // take snapshot of the running process 
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        cout << "Error.\n";
        return;
    }

    // initialize PROCESSENTRY32 structure
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // get information about the first process
    if (!Process32First(hProcessSnap, &pe32))
    {
        cout << "Error.\n";
        CloseHandle(hProcessSnap);
        return;
    }

    cout << "Image Name\t\tPID\n";

    do
    {
        wstring processName = pe32.szExeFile;
        DWORD processID = pe32.th32ProcessID;

        // open handle of the process
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
        if (hProcess != NULL)
        {
            HMODULE hMod;
            DWORD cbNeeded;
            WCHAR szProcessName[MAX_PATH];

            //get module name of the process
            if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
            {
                GetModuleBaseNameW(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(WCHAR));

                wcout << szProcessName << L"\t\t" << processID << L"\n";
            }
        }

        // close handle of the process
        CloseHandle(hProcess);

    } while (Process32Next(hProcessSnap, &pe32));

    // close handle of the snapshot
    CloseHandle(hProcessSnap);
}

int main()
{
    printRunningProcesses();
    return 0;
}
