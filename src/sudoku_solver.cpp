#include "sudoku_solver.h"
#include "fill_grid.h"
#include "print.h"

/**
 * Solves the given Sudoku puzzle.
 * Supports finding all possible solutions of the given puzzle.
 * 
 * @param sudoku The Sudoku puzzle to be solved.
 * @param allVals Flag indicating whether to generate all possible solutions.
 */
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

/**
 * Recursive helper function to solve the Sudoku puzzle.
 * Uses backtracking to find the solution.
 * 
 * @param sudoku The Sudoku puzzle grid.
 * @param allVals Flag to indicate whether to find all solutions or stop after finding the first solution.
 */
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