#include "print.h"
#include "sudoku_generator.h"

#define SUDOKU_SIZE 9
#define EMPTY_CELL 0

int main(int argc, char const *argv[]) {
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
    
    generateSudoku(sudoku);
    printSudoku(sudoku);

    return 0;
}
