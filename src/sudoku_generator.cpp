#include "sudoku_generator.h"
#include "fill_grid.h"

void generateSudoku(int sudoku[][SUDOKU_SIZE]) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            sudoku[i][j] = EMPTY_CELL;
        }
    }

    fillGrid(sudoku);
}