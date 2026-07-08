#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void easy(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){

    //1) Grille COMPLETE et VALIDE (backtracking, voir generate_grid.h)
    srand(time(0));
    generate_full_grid(mat);

    //2) On garde la solution complete dans mat_bis (pour verifier le joueur)
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            mat_bis[i][j] = mat[i][j];
        }
    }

    //3) On retire des cases (mises a 0) en gardant UNE seule solution possible.
    //   EASY : on en retire peu -> beaucoup d'indices restent.
    remove_numbers(mat, 40);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
