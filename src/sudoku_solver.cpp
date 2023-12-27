#include "sudoku_solver.h"
#include "fill_grid.h"
#include "print.h"

void sudokuSolver(int sudoku[][SUDOKU_SIZE], bool allVals) {
    int solved[SUDOKU_SIZE][SUDOKU_SIZE];
    for(int i = 0; i < SUDOKU_SIZE; i++) {
        for(int j = 0; j < SUDOKU_SIZE; j++) {
            solved[i][j] = sudoku[i][j];
        }
    }

    // To generate all possible solutions, set the 2nd parameter to true
    helper(solved, allVals);
}

void helper(int sudoku[][SUDOKU_SIZE], bool allVals) {
    static int solutionCount = 0;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(sudoku[i][j] == 0) {
                for(int k = 1; k <= 9; k++) {
                    if(isValid(sudoku, i, j, k)) {
                        sudoku[i][j] = k;
                        helper(sudoku, allVals);
                        sudoku[i][j] = 0;
                    }
                }
                return;
            }
        }
    }

    if (!allVals && solutionCount > 0) return;

    printSudoku(sudoku, true);
    solutionCount++;
}