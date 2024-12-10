//
// Created by afra-laptop on 07/12/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include "backtracking.h"
enum
{
    COMMAND_EXIT,
    COMMAND_CLEAR,
    COMMAND_NEIGHB,
    COMMAND_BFS,
    COMMAND_BFS_STEP,
    COMMAND_BFS_TREE,
    COMMAND_PATH,
    COMMAND_PERF
};

enum Direction
{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

Direction getNextDirection(int i);
void initGrid(Grid* grid, char* filename);
void waitForEnter(int times = 2);
int set_text_color(unsigned char foreground, unsigned char background = 0);
int readGrid(Grid* grid, const char* filename);
void displayGrid(const Grid* grid);
void displaySolution(const Grid* grid, int solutionIndex);
void delay(int milliseconds);
void simplePrintMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols);
void addSolution(Grid* grid);

#endif //UTILS_H
