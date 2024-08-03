#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void exitgame(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){

        //variables definition
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        sudokumain();
        gotoligcol(4, 45);
        SetConsoleTextAttribute(hConsole, 6);
        printf("///////////////////////////// ");
        SetConsoleTextAttribute(hConsole, 15);
        printf("T H A N K  Y O U !");
        SetConsoleTextAttribute(hConsole, 6);
        printf(" /////////////////////////////");
        gotoligcol(6, 73);
        SetConsoleTextAttribute(hConsole, 15);
        printf("We hope to see you soon");
        SetConsoleTextAttribute(hConsole, 6);
        gotoligcol(44, 70);
        printf("Copyright 2024 Sudoku Alassane Wade");
        SetConsoleTextAttribute(hConsole, 15);


        free(mat);
        free(mat_bis);

        sleep(4);

        system("cls");

        exit(0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////