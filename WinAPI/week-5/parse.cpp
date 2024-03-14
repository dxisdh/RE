#include "Windows.h"
#include<iostream>

int main(int argc, char* argv[])
{
    const int MAX_FILEPATH = 255;
    char fileName[MAX_FILEPATH] = {0};
    memcpy_s(&fileName, MAX_FILEPATH, argv[1], MAX_FILEPATH);
    HANDLE file = NULL;
    DWORD fileSize = NULL;
    DWORD bytesRead = NULL;
    LPVOID fileData = NULL;
    PIMAGE_DOS_HEADER dosHeader = {};
    PIMAGE_NT_HEADERS imageNTHeaders = {};
    PIMAGE_SECTION_HEADER sectionHeader = {};
    PIMAGE_SECTION_HEADER importSection = {};
    IMAGE_IMPORT_DESCRIPTOR* importDescriptor = {};
    PIMAGE_THUNK_DATA thunkData = {};
    DWORD thunk = NULL;
    DWORD rawOffset = NULL;

    // open file
    file = CreateFileA(fileName, GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(file == INVALID_HANDLE_VALUE)
    printf("Could not read file");

    // allocate heap
    fileSize = GetFileSize(file, NULL);
    fileData = HeapAlloc(GetProcessHeap(), 0, fileSize);

    // read file bytes to memory
    ReadFile(file, fileData, fileSize, &bytesRead, NULL);

    // IMAGE_DOS_HEADER
    dosHeader = (PIMAGE_DOS_HEADER)fileData;
    printf("DOS HEADER\n");
    printf("0x%x\t\tMagic number\n", dosHeader->e_magic);
    printf("0x%x\t\tBytes on last page of file\n", dosHeader->e_cblp);
    printf("0x%x\t\tPages in file\n", dosHeader->e_cp);
    printf("0x%x\t\tRelocations\n", dosHeader->e_crlc);
    printf("0x%x\t\tSize of header in paragraphs\n", dosHeader->e_cparhdr);
    printf("0x%x\t\tMinimum extra paragraphs needed\n", dosHeader->e_minalloc);
    printf("0x%x\t\tMaximum extra paragraphs needed\n", dosHeader->e_maxalloc);
    printf("0x%x\t\tInitial SS value\n", dosHeader->e_ss);
    printf("0x%x\t\tInitial SP value\n", dosHeader->e_sp);
    printf("0x%x\t\tChecksum\n", dosHeader->e_csum);
    printf("0x%x\t\tInitial IP value\n", dosHeader->e_ip);
    printf("0x%x\t\tInitial CS value\n", dosHeader->e_cs);
    printf("0x%x\t\tFile address of relocation table\n", dosHeader->e_lfarlc);
    printf("0x%x\t\tOverlay number\n", dosHeader->e_ovno);
    printf("0x%x\t\tOEM identifier\n", dosHeader->e_oemid);
    printf("0x%x\t\tFile address of new exe header\n", dosHeader->e_lfanew);

    // IMAGE_NT_HEADER
    imageNTHeaders = (PIMAGE_NT_HEADERS)((DWORD)fileData + dosHeader->e_lfanew);
    printf("NT HEADER\n");
    printf("%x\t\tSignature\n", imageNTHeaders->Signature);
    // FILE_HEADER
    printf("FILE HEADER\n");
    printf("%x\t\tMachine\n", imageNTHeaders->FileHeader.Machine);
    printf("%x\t\tNumberOfSections\n", imageNTHeaders->FileHeader.NumberOfSections);
    printf("%x\t\tTimeDateStamp\n", imageNTHeaders->FileHeader.TimeDateStamp);
    printf("%x\t\tPointerToSymbolTable\n", imageNTHeaders->FileHeader.PointerToSymbolTable);
    printf("%x\t\tNumberOfSymbols\n", imageNTHeaders->FileHeader.NumberOfSymbols);
    printf("%x\t\tSizeOfOptionalHeader\n", imageNTHeaders->FileHeader.SizeOfOptionalHeader);
    printf("%x\t\tCharacteristics\n", imageNTHeaders->FileHeader.Characteristics);
    // OPTIONAL HEADER
    printf("OPTIONAL HEADER\n");
    printf("%x\t\tMagic\n", imageNTHeaders->OptionalHeader.Magic);
    printf("%x\t\tMajorLinkerVersion\n", imageNTHeaders->OptionalHeader.MajorLinkerVersion);
    printf("%x\t\tMinorLinkerVersion\n", imageNTHeaders->OptionalHeader.MinorLinkerVersion);
    printf("%x\t\tSizeOfCode\n", imageNTHeaders->OptionalHeader.SizeOfCode);
    printf("%x\t\tSizeOfInitializedData\n", imageNTHeaders->OptionalHeader.SizeOfInitializedData);
    printf("%x\t\tSizeOfUninitializedData\n", imageNTHeaders->OptionalHeader.SizeOfUninitializedData);
    printf("%x\t\tAddressOfEntryPoint\n", imageNTHeaders->OptionalHeader.AddressOfEntryPoint);
    printf("%x\t\tBaseOfCode\n", imageNTHeaders->OptionalHeader.BaseOfCode);
    printf("%x\t\tImageBase\n", imageNTHeaders->OptionalHeader.ImageBase);
    printf("%x\t\tSectionAlignment\n", imageNTHeaders->OptionalHeader.SectionAlignment);
    printf("%x\t\tFileAlignment\n", imageNTHeaders->OptionalHeader.FileAlignment);
    printf("%x\t\tMajorOperatingSystemVersion\n", imageNTHeaders->OptionalHeader.MajorOperatingSystemVersion);
    printf("%x\t\tMinorOperatingSystemVersion\n", imageNTHeaders->OptionalHeader.MinorOperatingSystemVersion);
    printf("%x\t\tMajorImageVersion\n", imageNTHeaders->OptionalHeader.MajorImageVersion);
    printf("%x\t\tMinorImageVersion\n", imageNTHeaders->OptionalHeader.MinorImageVersion);
    printf("%x\t\tMajorSubsystemVersion\n", imageNTHeaders->OptionalHeader.MajorSubsystemVersion);
    printf("%x\t\tMinorSubsystemVersion\n", imageNTHeaders->OptionalHeader.MinorSubsystemVersion);
    printf("%x\t\tWin32VersionValue\n", imageNTHeaders->OptionalHeader.Win32VersionValue);
    printf("%x\t\tSizeOfImage\n", imageNTHeaders->OptionalHeader.SizeOfImage);
    printf("%x\t\tSizeOfHeaders\n", imageNTHeaders->OptionalHeader.SizeOfHeaders);
    printf("%x\t\tChecksum\n", imageNTHeaders->OptionalHeader.CheckSum);
    printf("%x\t\tSubsystem\n", imageNTHeaders->OptionalHeader.Subsystem);
    printf("%x\t\tDllCharacteristics\n", imageNTHeaders->OptionalHeader.DllCharacteristics);
    printf("%x\t\tSizeOfStackReverse\n", imageNTHeaders->OptionalHeader.SizeOfStackReserve);
    printf("%x\t\tSizeOfStackCommit\n", imageNTHeaders->OptionalHeader.SizeOfStackCommit);
    printf("%x\t\tSizeOfHeapReverse\n", imageNTHeaders->OptionalHeader.SizeOfHeapReserve);
    printf("%x\t\tSizeOfHeapCommit\n", imageNTHeaders->OptionalHeader.SizeOfHeapCommit);
    printf("%x\t\tLoaderFlags\n", imageNTHeaders->OptionalHeader.LoaderFlags);
    printf("%x\t\tNumberOfRvaAndSize\n", imageNTHeaders->OptionalHeader.NumberOfRvaAndSizes);
    // DATA_DIRECTORIES
    printf("DATA DIRECTORIES\n");
    printf("Export Directory Address: 0x%x, Size: 0x%x\n", imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress, imageNTHeaders->OptionalHeader.DataDirectory[0].Size);
    printf("Import Directory Address: 0x%x, Size: 0x%x\n", imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress, imageNTHeaders->OptionalHeader.DataDirectory[1].Size);

    // SECTION_HEADERS
    printf("SECTION HEADERS\n");
    DWORD sectionLocation = (DWORD)imageNTHeaders + sizeof(DWORD) + (DWORD)(sizeof(IMAGE_FILE_HEADER)) + (DWORD)imageNTHeaders->FileHeader.SizeOfOptionalHeader;
    DWORD sectionSize = (DWORD)sizeof(IMAGE_SECTION_HEADER);
    DWORD importDirectoryRVA = imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

    for(int i = 0; i < imageNTHeaders->FileHeader.NumberOfSections; i++)
    {
        sectionHeader = (PIMAGE_SECTION_HEADER)sectionLocation;
        printf("%s\n", sectionHeader->Name);
        printf("0x%x\t\tVirtualSize\n", sectionHeader->Misc.VirtualSize);
        printf("0x%x\t\tVirtualAddress\n", sectionHeader->VirtualAddress);
        printf("0x%x\t\tSizeOfRawData\n", sectionHeader->SizeOfRawData);
        printf("0x%x\t\tPointerToRawData\n", sectionHeader->PointerToRawData);
        printf("0x%x\t\tPointerToRelocations\n", sectionHeader->PointerToRelocations);
        printf("0x%x\t\tPointerToLinenumbers\n", sectionHeader->PointerToLinenumbers);
        printf("0x%x\t\tNumberOfRelocations\n", sectionHeader->NumberOfRelocations);
        printf("0x%x\t\tNumberOfLinenumbers\n", sectionHeader->NumberOfLinenumbers);
        printf("0x%x\t\tCharacteristics\n", sectionHeader->Characteristics);

        if(importDirectoryRVA >= sectionHeader->VirtualAddress && importDirectoryRVA < sectionHeader->VirtualAddress + sectionHeader->Misc.VirtualSize)
        {
            importSection = sectionHeader;
        }
        sectionLocation += sectionSize;
    }

    rawOffset = (DWORD)fileData + importSection->PointerToRawData;
    importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(rawOffset + (imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - importSection->VirtualAddress));
    printf("DLL IMPORTS\n");
    for(; importDescriptor->Name != 0; importDescriptor++)
    {
        printf("%s\n", rawOffset + (importDescriptor->Name - importSection->VirtualAddress));
        thunk = importDescriptor->OriginalFirstThunk == 0 ? importDescriptor->FirstThunk : importDescriptor->OriginalFirstThunk;
        thunkData = (PIMAGE_THUNK_DATA)(rawOffset + (thunk - importSection->VirtualAddress));

        for(; thunkData->u1.AddressOfData != 0; thunkData++)
        {
            if(thunkData->u1.AddressOfData > 0x80000000)
            {
                printf("Ordinal: %x\n", (WORD)thunkData->u1.AddressOfData);
            } else {
                printf("%s\n", (rawOffset + (thunkData->u1.AddressOfData - importSection->VirtualAddress + 2)));
            }
        }
    }
    return 0;
}
