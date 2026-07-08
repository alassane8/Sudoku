#ifndef GENERATE_GRID_H
#define GENERATE_GRID_H

#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Génération d'une grille de Sudoku COMPLÈTE et CORRECTE (remplie et valide).
//
// Principe : on remplit la grille case par case (indices 0..80). Pour chaque
// case, on essaie les chiffres 1..9 dans un ordre aléatoire. On ne pose un
// chiffre que s'il respecte les 3 règles (ligne, colonne, bloc 3x3). Si on se
// retrouve bloqué plus loin, on revient en arrière (backtracking) et on essaie
// un autre chiffre. L'ordre aléatoire garantit une grille différente à chaque
// partie.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Vérifie qu'on peut placer 'num' en mat[row][col] sans casser une règle.
static int grid_is_safe(unsigned char **mat, int row, int col, int num){
    // Règle 1 & 2 : ligne et colonne
    for (int k = 0; k < 9; k++){
        if (mat[row][k] == num) return 0;   // deja present sur la ligne
        if (mat[k][col] == num) return 0;   // deja present sur la colonne
    }
    // Règle 3 : bloc 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (mat[startRow + i][startCol + j] == num) return 0;
        }
    }
    return 1; // placement valide
}

// Mélange (Fisher-Yates) d'un tableau d'entiers, pour tester les chiffres
// dans un ordre aleatoire => grilles differentes a chaque appel.
static void grid_shuffle(int *array, int n){
    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

// Remplit la grille par backtracking a partir de la case lineaire 'pos' (0..80).
// Retourne 1 si la grille a pu etre entierement remplie, 0 sinon.
static int grid_fill(unsigned char **mat, int pos){
    if (pos == 81) return 1; // les 81 cases sont remplies : c'est fini

    int row = pos / 9;
    int col = pos % 9;

    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    grid_shuffle(numbers, 9);

    for (int i = 0; i < 9; i++){
        int num = numbers[i];
        if (grid_is_safe(mat, row, col, num)){
            mat[row][col] = num;              // on tente ce chiffre
            if (grid_fill(mat, pos + 1)) return 1; // on continue plus loin
            mat[row][col] = 0;                // echec plus loin : on annule
        }
    }
    return 0; // aucun chiffre ne convient ici : on revient en arriere
}

// FONCTION PUBLIQUE : remplit 'mat' avec une grille complete et valide.
void generate_full_grid(unsigned char **mat){
    // On vide d'abord la grille (0 = case vide pendant la generation).
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            mat[i][j] = 0;
        }
    }
    grid_fill(mat, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Retrait de chiffres avec garantie d'UNE SEULE solution.
//
// Une case vide est representee par 0. Pour rester "resoluble jusqu'au bout",
// on ne retire une case que si la grille garde EXACTEMENT une solution. Sinon
// on remet la case. Le joueur pourra donc toujours reconstituer la grille
// complete (= la solution gardee dans mat_bis).
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Compte le nombre de solutions de 'mat' (0 = case vide), en s'arretant des
// qu'on atteint 'limit' (on n'a jamais besoin de compter au-dela de 2).
static int grid_count_solutions(unsigned char **mat, int pos, int limit){
    if (pos == 81) return 1; // grille remplie : 1 solution trouvee

    int row = pos / 9;
    int col = pos % 9;

    // Case deja remplie : on passe a la suivante
    if (mat[row][col] != 0){
        return grid_count_solutions(mat, pos + 1, limit);
    }

    int count = 0;
    for (int num = 1; num <= 9; num++){
        if (grid_is_safe(mat, row, col, num)){
            mat[row][col] = num;
            count += grid_count_solutions(mat, pos + 1, limit);
            mat[row][col] = 0; // on annule (backtracking)
            if (count >= limit) break; // inutile de compter davantage
        }
    }
    return count;
}

// FONCTION PUBLIQUE : retire jusqu'a 'cellsToRemove' cases de 'mat' en gardant
// une solution unique. Les cases retirees valent 0. 'mat' doit contenir au
// depart une grille complete et valide.
void remove_numbers(unsigned char **mat, int cellsToRemove){
    int removed = 0;
    int attempts = 0;
    int maxAttempts = 81 * 30; // garde-fou contre une boucle infinie

    while (removed < cellsToRemove && attempts < maxAttempts){
        attempts++;

        int row = rand() % 9;
        int col = rand() % 9;
        if (mat[row][col] == 0) continue; // deja vide, on retente ailleurs

        unsigned char backup = mat[row][col];
        mat[row][col] = 0; // on tente de vider la case

        // Si ce retrait fait apparaitre 2 solutions (ou plus), on remet la case.
        if (grid_count_solutions(mat, 0, 2) != 1){
            mat[row][col] = backup;
        } else {
            removed++;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
