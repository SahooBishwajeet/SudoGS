#include "print.h"

/**
 * @brief Prints the Sudoku grid.
 * 
 * This function takes a 2D array representing a Sudoku grid and prints it in a formatted manner.
 * The grid is printed with horizontal and vertical lines separating the cells, and the numbers
 * are displayed within each cell. Empty cells are represented by a space character.
 * 
 * @param sudoku The Sudoku grid to be printed.
 */
void printSudoku(int sudoku[][SUDOKU_SIZE]) {
    std::string hLine = "", vLine = "", textLine = "";

    for(int i  = 0; i < SUDOKU_SIZE; i++) {
        hLine = " -";
        vLine = "|";
        textLine = "|";

        for(int j = 0; j < SUDOKU_SIZE; j++) {
            std::string number = sudoku[i][j] == EMPTY_CELL ? " " : std::to_string(sudoku[i][j]);

            textLine += "   " + number + "  |";
            hLine += "-------";
            vLine += "      |";

            if(j != SUDOKU_SIZE - 1 && j % 3 == 2) {
                vLine += "|";
                textLine += "|";
            }
        }

        if(i % 3 == 0 && i != 0) {
            std::replace(hLine.begin(), hLine.end(), '-', '=');
        }

        std::cout << hLine << std::endl;
        std::cout << vLine << std::endl;
        std::cout << textLine << std::endl;
        std::cout << vLine << std::endl;
    }
    std::cout << hLine << std::endl;
}

/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<Grid Output>>>>>>>>>>>>>>>>>>>>>>>>>>>
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ================================================================
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ================================================================
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
|      |      |      ||      |      |      ||      |      |      |
 ----------------------------------------------------------------
*/