// exportfunctionheader
#pragma once
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" MYDLL_API void ShowMessage(const char* message);
extern "C" MYDLL_API void WriteToFile(const char* filename, const char* content);

// program
#include "pch.h"
#include<iostream>
#include<fstream>
#include "exportfunction.h"
using namespace std;

void ShowMessage(const char* message)
{
	cout << message;
}

void WriteToFile(const char* filename, const char* content)
{
	ofstream file;
	file.open(filename, ios::app);
	if(file.is_open())
	{
		file << content << endl;
		file.close();
	}
	else
	{
		cout << "Failed to open file: " << filename << endl;
	}
}

// exportfunctionclient
#include <iostream>
#include <windows.h>
#include "exportfunction.h"

int main()
{
        ShowMessage("Hello DLL!"); 
        WriteToFile("..\..\exportfunctionclient\exportfunctionclient\a.txt", "This is some content"); 
}
