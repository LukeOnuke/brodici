#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "frontend.h"
#include "backend.h"

HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;


int main()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTitle("Potapanje Brodova");
    /*
    -- tasha i garca --
    backend.h
    backend.c

    -- kresoja i milic --
    forntend.h
    frontend.c
    */
    pokreniEkran();
    return 0;
}
