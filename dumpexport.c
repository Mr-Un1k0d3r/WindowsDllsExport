#include <Windows.h>
#include <winnt.h>
#include <stdio.h>

VOID DumpListOfExport(VOID *lib);

VOID DumpListOfExport(VOID *lib) {
	PIMAGE_DOS_HEADER MZ = (PIMAGE_DOS_HEADER)lib;
	PIMAGE_NT_HEADERS PE = (PIMAGE_NT_HEADERS)((LPBYTE)MZ + MZ->e_lfanew);
	PIMAGE_EXPORT_DIRECTORY export = (PIMAGE_EXPORT_DIRECTORY)((LPBYTE)lib + PE->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
	
	DWORD *exportName = (DWORD*)((LPBYTE)lib + export->AddressOfNames);

	DWORD i = 0;
	for(i; i < export->NumberOfNames; i++) {
		printf("%s\n", lib + exportName[i]);
	}	
}

int main (int argc, char **argv) {
    CHAR *dll = argv[1];
    HANDLE hDll = LoadLibrary(dll);
    if(hDll == NULL) {
        ExitProcess(0);
    }
	
    DumpListOfExport(hDll);
    CloseHandle(hDll);
    return 0;
}
