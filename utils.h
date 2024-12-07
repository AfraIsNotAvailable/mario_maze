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

// void set_text_color(unsigned char foreground, unsigned char background = 0);
int readGrid(Grid* grid, const char* filename);
void displayGrid(const Grid* grid, int lastCommand);

#endif //UTILS_H
