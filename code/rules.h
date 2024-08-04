#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rules(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){

    //Variables definitions
    int backToMenu;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Affichage des regles
    gotoligcol(1, 60);
    SetConsoleTextAttribute(hConsole, 6);
    printf("///////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("R U L E S");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" /////////////////////////////");
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(5, 0);
    printf("Rule 1 - Each row must contain the numbers from 1 to 9, without repetitions\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("The player must focus on filling each row of the grid while ensuring there are\n"
           "no duplicated numbers. The placement order of the digits is irrelevant.\n"
           "Every puzzle, regardless of the difficulty level, begins with allocated numbers on the grid. \n"
           "The player should use these numbers as clues to find which digits are missing in each row.\n\n\n");

    SetConsoleTextAttribute(hConsole, 6);
    printf("Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("The Sudoku rules for the columns on the grid are exactly the same as for the rows. The player must \n"
           "also fill these with the numbers from 1 to 9, making sure each digit occurs only once per column.\n"
           "The numbers allocated at the beginning of the puzzle work as clues to find which digits are missing \n"
           "in each column and their position.\n\n\n");

    SetConsoleTextAttribute(hConsole, 6);
    printf("Rule 3 - The digits can only occur once per block (nonet)\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("A regular 9 x 9 grid is divided into 9 smaller blocks of 3 x 3, also known as nonets. The numbers \n"
           "from 1 to 9 can only occur once per nonet.\n"
           "In practice, this means that the process of filling the rows and columns without duplicated digits \n"
           "finds inside each block another restriction to the numbers’ positioning.\n\n\n");

    SetConsoleTextAttribute(hConsole, 6);
    printf("Rule 4 - The sum of every single row, column, and nonet must equal 45\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("To find out which numbers are missing from each row, column, or block or if there are any duplicates,\n"
           "the player can simply count or flex their math skills and sum the numbers. When the digits occur only once, \n"
           "the total of each row, column, and group must be 45.\n\n"
           "1+2+3+4+5+6+7+8+9= 45\n");

    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);
    sudokuascii();

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////