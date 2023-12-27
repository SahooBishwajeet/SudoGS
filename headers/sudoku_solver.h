#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#define SUDOKU_SIZE 9

void sudokuSolver(int sudoku[][SUDOKU_SIZE], bool allVals);
void helper(int sudoku[][SUDOKU_SIZE], bool allVals);

#endif // SUDOKU_SOLVER_H