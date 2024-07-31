#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void play(unsigned char **mat, unsigned char **mat_bis,  char *pseudo)
{
    // Variables definition
    int backToMenu;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(44, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");

    gotoligcol(37, 0);
    // Appel du menu
    SetConsoleTextAttribute(hConsole, 6);
    printf("Main menu: \n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("1. Yes\n");
    scanf("%d", &backToMenu);
    while (backToMenu != 1)
    {
        gotoligcol(42, 0);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(39, 0);
        printf("  ");
        gotoligcol(39, 0);
        fflush(stdin);
        scanf("%d", &backToMenu);
    }
    if (backToMenu == 1)
    {
        system("cls");
        menu(mat, mat_bis, pseudo);
    }
}