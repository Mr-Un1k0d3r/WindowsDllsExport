# ListOfDllsExport
A list of all the DLLs export in C:\windows\system32\

The idea is to find some interesting export that can be used to evade some detection.

# Generate The List By Yourself

dumpexport.c can be compiled and run locally

```
PS> foreach($dll in gci -Path C:\windows\system32\ -Filter *.dll) { .\dumpexport.exe $($dll.Name) | out-file -FilePath .\$($dll.Name).txt }
```

# Credit
Mr.Un1k0d3r RingZer0 Team
