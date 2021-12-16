#include <Windows.h>
#include <stdio.h>


VOID DumpListOfExport(VOID *lib);

VOID DumpListOfExport(VOID *lib) {
    DWORD dwIter = 0;
    CHAR* base = (CHAR*)lib;
    CHAR* PE = base + (unsigned char)*(base + 0x3c);
    DWORD ExportDirectoryOffset = *((DWORD*)PE + (0x8a / 4));
    CHAR* ExportDirectory = base + ExportDirectoryOffset;
    DWORD dwFunctionsCount = *((DWORD*)ExportDirectory + (0x14 / 4));
    DWORD OffsetNamesTableOffset = *((DWORD*)ExportDirectory + (0x20 / 4));
    CHAR* OffsetNamesTable = base + OffsetNamesTableOffset;

    for(dwIter; dwIter < dwFunctionsCount - 1; dwIter++) {
        DWORD64 offset = *((DWORD*)OffsetNamesTable + dwIter);
        CHAR* current = base + offset;
        printf("%s\n", current);
    }
}


int main (int argc, char **argv) {
    CHAR *dll = argv[1];
    HANDLE hDll = LoadLibrary(dll);
    printf("- START %s -----------------------------------------\n", dll);
    if(hDll == NULL) {
        ExitProcess(0);
    }
	
    DumpListOfExport(hDll);
    CloseHandle(hDll);
    printf("- ENDOF %s -----------------------------------------\n", dll);
    return 0;
}
