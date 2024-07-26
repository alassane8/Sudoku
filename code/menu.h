#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(){
    
    //Variables definition 
    int difficulty = 0;
    int menu_options = 0;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Acceuil du joueur 1
    gotoligcol(8, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("M A I N   M E N U");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);

    //Copyrights
    gotoligcol(44, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");

    gotoligcol(10, 70);
    printf("1. Play");
    gotoligcol(11, 70);
    printf("2. Load game");
    gotoligcol(12, 70);
    printf("3. Rules");
    gotoligcol(13, 70);
    printf("4. Exit ");
    gotoligcol(14, 70);
    fflush(stdin);
    scanf("%d", &menu_options);

    // Erreur de saisie
    while (menu_options != 1 && menu_options != 2 && menu_options != 3 && menu_options != 4)
    {
        gotoligcol(25, 140);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error.");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(14, 70);
        printf("  ");
        gotoligcol(14, 70);
        fflush(stdin);
        scanf("%d", menu_options);
    }

    // Jouer 
    if (menu_options == 1)
    {
        // Choix du niveau de l'ia
        gotoligcol(15, 70);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Choose Sudoku difficulty:");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(16, 70);
        printf("1. Easy");
        gotoligcol(17, 70);
        printf("2. Medium");
        gotoligcol(18, 70);
        printf("3. Hard");
        gotoligcol(19, 70);
        fflush(stdin);
        scanf("%d", &difficulty);

        while (difficulty != 1 && difficulty != 2 && difficulty != 3)
        {
            gotoligcol(25, 140);
            SetConsoleTextAttribute(hConsole, 12);
            printf("Error.");
            SetConsoleTextAttribute(hConsole, 15);
            gotoligcol(19, 70);
            printf("  ");
            gotoligcol(19, 70);
            fflush(stdin);
            scanf("%d", &difficulty);
        }
    }

    // Rules
    if (menu_options == 3)
    {
        system("cls");
        rules();
    }
        // Quitter
    else if (menu_options == 4)
    {
        system("cls");
        gotoligcol(4, 45);
        SetConsoleTextAttribute(hConsole, 11);
        printf("///////////////////////////// ");
        SetConsoleTextAttribute(hConsole, 15);
        printf("T H A N K  Y O U !");
        SetConsoleTextAttribute(hConsole, 11);
        printf(" /////////////////////////////");
        gotoligcol(6, 73);
        SetConsoleTextAttribute(hConsole, 15);
        printf("We hope to see you soon");
        gotoligcol(44, 70);
        printf("Copyright 2024 Sudoku Alassane Wade");
        sleep(4);
        system("cls");
        exit(0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
