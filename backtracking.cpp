//
// Created by afra-laptop on 07/12/2024.
//

#include "backtracking.h"

#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <vector>

#include "menu.h"
#include "utils.h"

void resetCell(Grid* grid, int x, int y)
{
    grid->mat[x][y] = grid->originalMat[x][y];
}

bool isValid(int x, int y, Grid* grid)
{
    if (x >= 1 && x <= grid->rows - 1 && y >= 1 && y <= grid->cols - 1 && grid->mat[x][y] != 1 && grid->mat[x][y] != 32)
    {
        return true;
    }
    return false;
}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bktkLevel1(Grid* grid, int x, int y)
{
    grid->mat[x][y] = 4; // 4 is the mario
    system("cls");
    displayLevel1();
    displayGrid(grid);
    // delay(250); // usleep(1000000); // TODO: put it back
    if (x == grid->rows - 2 && y == grid->cols - 2)
    {
        system("cls");
        displayLevel1();
        displayGrid(grid);
        // printf("End reached!\n");
        // printf("Pasi: %d\n", grid->stepsCurr);
        // printf("Coins: %d\n", grid->coinsCurr);
        addSolution(grid);
        grid->coinsCurr = 0;
        resetCell(grid, x, y);
        // delay(1000); //TODO: put it back
        return;
    }
    grid->mat[x][y] = 32;

    for (int i = 0; i < 4; ++i)
    {
        int nextRow = x + dx[i];
        int nextCol = y + dy[i];

        if (isValid(nextRow, nextCol, grid))
        {
            if (grid->mat[nextRow][nextCol] == 8)
            {
                grid->coinsCurr++;
            }
            grid->stepsCurr++;
            bktkLevel1(grid, nextRow, nextCol);
            grid->stepsCurr--;
        }
    }
    resetCell(grid, x, y);
}
