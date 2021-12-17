# WindowsDllsExport
A list of all the DLLs export in C:\windows\system32\

The idea is to find some interesting export that can be used to evade some detection.

The list was extracted from the following build

```
PS> [Environment]::OSVersion.Version

Major  Minor  Build  Revision
-----  -----  -----  --------
10     0      19043  0
```

# Generate The List By Yourself

dumpexport.c can be compiled and run locally

```
PS> foreach($dll in gci -Path C:\windows\system32\ -Filter *.dll) { .\dumpexport.exe $($dll.Name) | out-file -FilePath .\$($dll.Name).txt }
```

# Sqlite Database 
the database contains the dll name and the export name in a table defined as following

`table|exports|exports|2|CREATE TABLE exports (dllname text, exportname text)`


# Credit
Mr.Un1k0d3r RingZer0 Team
