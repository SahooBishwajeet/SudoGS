#include "print.h"
#include "sudoku_generator.h"
#include "sudoku_solver.h"

#define SUDOKU_SIZE 9
#define EMPTY_CELL 0

int main(int argc, char const *argv[]) {
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
    
    generateSudoku(sudoku, 3);
    
    std::cout << "<<<<<<SOLVE THIS>>>>>" << std::endl;
    printSudoku(sudoku);

    std::cout << "<<<<<<SOLUTION>>>>>>" << std::endl;
    sudokuSolver(sudoku);

    // std::cout << "<<<<<<ORIGINAL>>>>>>" << std::endl;
    // printSudoku(sudoku);

    return 0;
}
