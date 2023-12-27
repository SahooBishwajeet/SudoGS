#include "sudoku_generator.h"
#include "fill_grid.h"

/**
 * Generates a Sudoku puzzle with the specified difficulty level.
 * The generated puzzle is stored in the given 2D array.
 *
 * @param sudoku The 2D array to store the generated Sudoku puzzle.
 * @param difficulty The difficulty level of the Sudoku puzzle.
 *                   The higher the difficulty level, the fewer empty cells in the puzzle.
 */
void generateSudoku(int sudoku[][SUDOKU_SIZE], int difficulty) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            sudoku[i][j] = EMPTY_CELL;
        }
    }

    fillGrid(sudoku);

    // Referred To Stackoverflow (Random Device In C++) : https://stackoverflow.com/questions/39288595/why-not-just-use-random-device
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    // Naive way of choosing Difficulty of the Game through the number of empty cells
    // The more the number of empty cells, the easier the game
    int blanksNeeded = 55 - (difficulty * 5);

    while (blanksNeeded > 0) {
        int row = dis(gen) - 1;
        int col = dis(gen) - 1;

        if (sudoku[row][col] != EMPTY_CELL) {
            sudoku[row][col] = EMPTY_CELL;
            blanksNeeded--;
        }
    }
}