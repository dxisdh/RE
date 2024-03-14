#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]) {

    const char* dllPath = argv[1];
    const char* functionName = argv[2];

    HINSTANCE hDll = LoadLibraryA(dllPath);
    if (hDll == NULL) {
        cout << "Failed to load DLL: " << dllPath << endl;
        return 1;
    }

    FARPROC fnPtr = GetProcAddress(hDll, functionName);
    if (fnPtr == NULL) {
        cout << "Failed to find function: " << functionName << " in DLL: " << dllPath << endl;
        return 1;
    }

    typedef void (*FunctionType)();
    FunctionType function = reinterpret_cast<FunctionType>(fnPtr);

    function();

    FreeLibrary(hDll);

    return 0;
}
