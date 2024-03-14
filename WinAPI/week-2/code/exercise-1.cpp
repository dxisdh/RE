// basic systeminfo
#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;

wstring QueryRegistryValue(HKEY hKey, const wstring& subKey, const wstring& valueName)
{
	HKEY hSubKey;
    if (RegOpenKeyExW(hKey, subKey.c_str(), 0, KEY_QUERY_VALUE, &hSubKey) == ERROR_SUCCESS) 
    {
        DWORD dataType;
        DWORD dataSize = 0;

        if (RegQueryValueExW(hSubKey, valueName.c_str(), NULL, &dataType, NULL, &dataSize) == ERROR_SUCCESS) 
        {
            if(dataType == REG_SZ || dataType == REG_EXPAND_SZ)
            {
                vector<wchar_t> buffer(dataSize / sizeof(wchar_t));
                if(RegQueryValueExW(hSubKey, valueName.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(buffer.data()), &dataSize) == ERROR_SUCCESS)
                {
                    return wstring(buffer.data());
                }
            }
            else if(dataType == REG_DWORD)
            {
                DWORD data;
                if(RegQueryValueExW(hSubKey, valueName.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&data), &dataSize) == ERROR_SUCCESS)
                {
                    return to_wstring(data);
                }
            }
        }
        RegCloseKey(hSubKey);
    }
}

int main()
{
    wstring hostName = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName", L"ComputerName");
    wstring OSName = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"ProductName");
    wstring OSBType = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"CurrentType");
    wstring regOwner = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"RegisteredOwner");
    wstring productID = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", L"ProductId");
    wstring sysManu = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\SystemInformation", L"SystemManufacturer");
    wstring sysModel = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\SystemInformation", L"SystemProductName");
    wstring processorName = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", L"ProcessorNameString");
    wstring BIOSVersion = QueryRegistryValue(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\BIOS", L"BIOSVersion");

    wcout << L"Host Name: " << hostName << endl;
    wcout << L"OS Name: " << OSName << endl;
    wcout << L"OS Build Type: " << OSBType << endl;
    wcout << L"Registered Owner: " << regOwner << endl;
    wcout << L"Product ID: " << productID << endl;
    wcout << L"System Manufacturer: " << sysManu << endl;
    wcout << L"System Model: " << sysModel << endl;
    wcout << L"Processor Name: " << processorName << endl;
    wcout << L"BIOS Version: " << BIOSVersion << endl;
}
