#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void decors(unsigned char ** mat){

    //Variables Definitions
    int i;
    int j;
    int point = 249;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Grid setup
    SetConsoleTextAttribute(hConsole, 6);
    printf("+-----------------------------+-----------------------------+-----------------------------+\n");
    SetConsoleTextAttribute(hConsole, 15);
        for (i = 0; i < 9; i++){
            if (i == 3 || i == 6){
                SetConsoleTextAttribute(hConsole, 6);
                printf("+-----------------------------+-----------------------------+-----------------------------+\n");
                SetConsoleTextAttribute(hConsole, 15);
            }
            for (j = 0; j < 9; j++){
                if (j == 0 || j == 3 || j == 6 || j == 9){
                    SetConsoleTextAttribute(hConsole, 6);
                    printf("|    ");
                    SetConsoleTextAttribute(hConsole, 8);
                }
                else{
                    SetConsoleTextAttribute(hConsole, 8);
                    printf("|    ");
                }
                printf("%d", mat[i][j]);
                printf("    ");
                SetConsoleTextAttribute(hConsole, 6);
            }
        printf("|");
        printf("\n\n");
        }
    SetConsoleTextAttribute(hConsole, 6);
    printf("+-----------------------------+-----------------------------+-----------------------------+\n");
    SetConsoleTextAttribute(hConsole, 15);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////