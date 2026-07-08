#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void move_cursor(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void play(unsigned char **mat, unsigned char **mat_bis,  char *pseudo)
{
    // Variables definition
    char keypressed;
    int x = 5;
    int y = 2;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Reperer les cases FIXES (indices de depart) : celles qui sont non vides
    // au tout debut de la partie. Le joueur ne pourra PAS ecrire dessus.
    unsigned char given[9][9];
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            given[i][j] = (mat[i][j] != 0) ? 1 : 0;
        }
    }

    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);
    sudokuascii();

    gotoligcol(23, 0);
    printf("Press '");
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(23, 7);
    printf("t,f,g,h");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(23, 14);
    printf("' to move the cursor");
    gotoligcol(24, 0);
    printf("Press '");
    gotoligcol(24, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("m");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(24, 8);
    printf("' to go back to Menu\n");
    gotoligcol(25, 0);
    printf("Press '");
    gotoligcol(25, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("s");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(25, 8);
    printf("' to Save\n");
    gotoligcol(26, 0);
    printf("Press '");
    gotoligcol(26, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("q");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(26, 8);
    printf("' to Quit\n");

    // Set the cursor position to the top-left corner of the screen
    SetCursorPos(5, 2);
    move_cursor(x, y);


    while (1) {
        keypressed = _getch();
        if (keypressed >= '1' && keypressed <= '9'){
            int col = (x - 5) / 10;   // colonne 0..8 deduite de la position ecran
            int row = (y - 2) / 2;    // ligne   0..8 deduite de la position ecran

            // Saisie autorisee uniquement sur une case NON fixe
            // (donc une case vide, ou une case deja remplie par le joueur).
            if (given[row][col] == 0){
                mat[row][col] = keypressed - '0';        // on enregistre la valeur du joueur
                gotoligcol(y, x);
                SetConsoleTextAttribute(hConsole, 9);    // BLEU pour les chiffres du joueur
                printf("%c", keypressed);
                SetConsoleTextAttribute(hConsole, 15);
                move_cursor(x, y);                       // le curseur reste sur la case
            }
        }

        if (keypressed == 'q'){
            system("cls");
            exitgame(mat, mat_bis, pseudo);
        }

        if (keypressed == 's'){
            system("cls");
            choice_saving_game(mat, mat_bis, pseudo);
        }

        if (keypressed == 'm'){
            system("cls");
            menu(mat, mat_bis, pseudo);
        }
        if (keypressed == 't' && y > 2){//up
            y = y - 2;
            move_cursor(x, y);
        }
        if (keypressed == 'g' && y < 18){//down
            y = y + 2;
            move_cursor(x, y);
        }
        if (keypressed == 'f' && x > 5){//left
            x = x - 10;
            move_cursor(x, y);
        }
        if (keypressed == 'h' && x < 85){//right
            x = x + 10;
            move_cursor(x, y);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
