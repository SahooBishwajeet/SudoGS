#include "cli.h"

void cli(const char **argv) {
    if(strcmp(argv[1], "--help") == 0) {
        std::cout << "Usages: sudogs, sudogs --help, sudogs --gen [difficulty]\n\n"
            "Commands:\n"
            "help   prints informations about sudogs\n"
            "gen    generates sudoku with given difficulty [Note, you won't get the solution for this Sudoku]\n\n"
            "Instructions:\n"
            "Difficulty = A positive number from 1 to 5\n"
            "Solve = Provide your sudoku to be solved. [Put 0 for blank spaces]\n"
            "[Example : 1 2 3 4 5 6 7 8 9\n"
            "           2 3 4 5 6 7 8 9 1\n"
            "           3 4 5 6 7 8 9 1 2\n"
            "           4 5 6 7 8 9 1 2 3\n"
            "           5 6 7 8 9 1 2 3 4\n"
            "           6 7 8 9 1 2 3 4 5\n" 
            "           7 8 9 1 2 3 4 5 6\n"
            "           8 9 1 2 3 4 5 6 7\n"
            "           9 1 2 3 4 5 6 7 8 ]" << std::endl;
    }
    else if(strcmp(argv[1], "--gen") == 0) {
        int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
        int difficulty = std::stoi(argv[2]);
        generateSudoku(sudoku, difficulty);
        std::cout << "<==============SOLVE THIS==============>" << std::endl;
        printSudoku(sudoku, false);
    }
    else {
        std::cout << "Unknown Usage, Use \"--help\" Argument\n" << std::endl;
    }
}