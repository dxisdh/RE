#include<iostream>
#include<windows.h>
#include<vector>
#include<tlhelp32.h>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

FILETIME userTime[5];
void CountWords()
{
	FILETIME createTime, exitTime, kernelTime;

	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[1]);
	const char* filename = "1.txt";
	ifstream file(filename);
	int count = 0;
	string s;
	while(file >> s)
	{
		count++;
	}
	file.close();
	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[1]);
}

void CountFiles()
{
	FILETIME createTime, exitTime, kernelTime;

	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[2]);
	WIN32_FIND_DATA findData;
	HANDLE hFind;
	int count = 0;

	hFind = FindFirstFile(L".", &findData);
	if(hFind != INVALID_HANDLE_VALUE)
	{
		do {
			if(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				continue;
			}
			count++;
		}
		while (FindNextFileW(hFind, &findData));
		FindClose(hFind);
	}
	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[2]);
}

void CountThreads()
{
	FILETIME createTime, exitTime, kernelTime;

	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[3]);
	int cnt = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 pe32;
	THREADENTRY32 te32;
	pe32.dwSize = sizeof(pe32);
	te32.dwSize = sizeof(te32);
	if(Process32First(hSnapshot, &pe32))
	{
		do
		{
			if(strcmp((const char *)pe32.szExeFile, "explorer.exe") == 0 && Thread32First(hSnapshot, &te32))
			{
				do
				{
					cnt++;
				} while (Thread32Next(hSnapshot, &te32));
			} 
		} while (Process32Next(hSnapshot, &pe32));
	}
	GetThreadTimes(GetCurrentThread(), &createTime, &exitTime, &kernelTime, &userTime[3]);
}

int main() {
	HANDLE hThreads[3];
	DWORD threadIds[3];
	vector<pair<DWORD, string>> results;

	hThreads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CountWords, NULL, 0, &threadIds[0]);
	hThreads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CountFiles, NULL, 0, &threadIds[1]);
	hThreads[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CountThreads, NULL, 0, &threadIds[2]);

	WaitForMultipleObjects(3, hThreads, TRUE, INFINITE);

	for (int i = 0; i < 3; i++) {
		DWORD exitCode;
		GetExitCodeThread(hThreads[i], &exitCode);
		results.push_back(make_pair(exitCode, "Thread " + to_string(i + 1)));
	}

	sort(results.begin(), results.end());

	for (int i = 0; i < 3; i++) {
		cout << results[i].second << ": Giai " << (i + 1) << endl;
	}

	return 0;
}
