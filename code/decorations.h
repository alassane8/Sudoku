#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors(){

    //Variables Definitions
    int i;
    int j;
    int k;
    int point = 249;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Grid setup
    for (i = 0; i < 3; i++){
        SetConsoleTextAttribute(hConsole, 12);
        printf("+----------------------------+----------------------------+----------------------------+\n");
        for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
                SetConsoleTextAttribute(hConsole, 12);
                printf("| ");
                SetConsoleTextAttribute(hConsole, 6);
                printf("      .      .      .      ");
            }
            SetConsoleTextAttribute(hConsole, 12);
            printf("|");
            printf("\n\n");
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    printf("+----------------------------+----------------------------+----------------------------+\n");
    SetConsoleTextAttribute(hConsole, 15);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////