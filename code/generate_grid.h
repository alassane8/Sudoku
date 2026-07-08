#ifndef GENERATE_GRID_H
#define GENERATE_GRID_H

#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int grid_is_safe(unsigned char **mat, int row, int col, int num){
    for (int k = 0; k < 9; k++){
        if (mat[row][k] == num) return 0;
        if (mat[k][col] == num) return 0;
    }
    // Règle 3 : bloc 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (mat[startRow + i][startCol + j] == num) return 0;
        }
    }
    return 1;
}

static void grid_shuffle(int *array, int n){
    for (int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

static int grid_fill(unsigned char **mat, int pos){
    if (pos == 81) return 1;

    int row = pos / 9;
    int col = pos % 9;

    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    grid_shuffle(numbers, 9);

    for (int i = 0; i < 9; i++){
        int num = numbers[i];
        if (grid_is_safe(mat, row, col, num)){
            mat[row][col] = num;
            if (grid_fill(mat, pos + 1)) return 1;
            mat[row][col] = 0;
        }
    }
    return 0;
}

void generate_full_grid(unsigned char **mat){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            mat[i][j] = 0;
        }
    }
    grid_fill(mat, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int grid_count_solutions(unsigned char **mat, int pos, int limit){
    if (pos == 81) return 1;

    int row = pos / 9;
    int col = pos % 9;

    if (mat[row][col] != 0){
        return grid_count_solutions(mat, pos + 1, limit);
    }

    int count = 0;
    for (int num = 1; num <= 9; num++){
        if (grid_is_safe(mat, row, col, num)){
            mat[row][col] = num;
            count += grid_count_solutions(mat, pos + 1, limit);
            mat[row][col] = 0;
            if (count >= limit) break;
        }
    }
    return count;
}

void remove_numbers(unsigned char **mat, int cellsToRemove){
    int removed = 0;
    int attempts = 0;
    int maxAttempts = 81 * 30;

    while (removed < cellsToRemove && attempts < maxAttempts){
        attempts++;

        int row = rand() % 9;
        int col = rand() % 9;
        if (mat[row][col] == 0) continue;

        unsigned char backup = mat[row][col];
        mat[row][col] = 0;

        if (grid_count_solutions(mat, 0, 2) != 1){
            mat[row][col] = backup;
        } else {
            removed++;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
