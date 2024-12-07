#include <iostream>

#include "backtracking.h"
#include "menu.h"
#include "utils.h"

int main()
{
    // set_text_color(15, 0);
    printTitle("title.txt");
    Grid grid;
    readGrid(&grid, "level2.txt");
    displayGrid(&grid, COMMAND_EXIT);
    memcpy(grid.auxMat, grid.mat, sizeof(grid.mat));
    bktkLevel1(&grid, 1, 1);
    std::cin.get();

    return 0;
}
