#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void choice_loading_game(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){

    //Variables deifinition
    int choice;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Clean page
    system("cls");
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);

    // // Display files matrices
    // display_files();

    gotoligcol(20, 70);
    SetConsoleTextAttribute(hConsole, 6);
    printf("Which game do you want to load ?");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(21, 70);
    printf("1. Game 1");
    gotoligcol(22, 70);
    printf("2. Game 2");
    gotoligcol(23, 70);
    printf("3. Game 3");
    gotoligcol(24, 70);
    printf("4. Main menu");
    fflush(stdin);
    gotoligcol(25, 70);
    scanf("%d", &choice);

    while (choice != 4)
    {
        gotoligcol(25, 120);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(25, 70);
        printf("  ");
        gotoligcol(25, 70);
        fflush(stdin);
        scanf("%d", &choice);
    }
    if (choice == 4){
        system("cls");
        menu(mat, mat_bis, pseudo);
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////