// hellodllheader
#pragma once
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" void ShowMessage();

// main program
#include "pch.h"
#include<iostream>
#include<windows.h>
#include "hellodll.h"

void ShowMessage()
{
	MessageBoxA(NULL, "Hi! I'm a DLL", "Message", 0);
}
