//
// Created by afra-laptop on 07/12/2024.
//

#include "backtracking.h"

#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "utils.h"

void resetGrid(Grid* grid)
{
    for (int i = 0; i < grid->rows; ++i)
    {
        for (int j = 0; j < grid->cols; ++j)
        {
            if (grid->mat[i][j] == 4)
            {
                grid->mat[i][j] = 32;
            }
        }
    }
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
    displayGrid(grid, 0);
    sleep(1);
    if (x == grid->rows - 2 && y == grid->cols - 2)
    {
        printf("End reached!\n");
        printf("Pasi: %d\n", grid->steps);
        printf("Coins: %d\n", grid->coins);
        grid->coins = 0;
        memcpy(grid->mat, grid->auxMat, sizeof(grid->mat));
        std::cin.get();
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
                grid->coins++;
            }
            grid->steps++;
            bktkLevel1(grid, nextRow, nextCol);
            grid->steps--;
        }
    }
    grid->mat[x][y] = 0;

    // if (grid->mat[x - 1][y] == 0 || grid->mat[x - 1][y] == 32) // up
    // {
    //     // Grid grid2;
    //     // memcpy(&grid2, grid, sizeof(Grid));
    //     // grid2.mat[x][y] = 2;
    //     bktkLevel1(grid, x - 1, y);
    // }
    // if (grid->mat[x][y + 1] == 0 || grid->mat[x][y + 1] == 32) // right
    // {
    //     // Grid grid2;
    //     // memcpy(&grid2, grid, sizeof(Grid));
    //     // grid2.mat[x][y] = 2;
    //     bktkLevel1(grid, x, y + 1);
    // }
    // if (grid->mat[x + 1][y] == 0 || grid->mat[x + 1][y] == 32) // down
    // {
    //     // Grid grid2;
    //     // memcpy(&grid2, grid, sizeof(Grid));
    //     // grid2.mat[x][y] = 2;
    //     bktkLevel1(grid, x + 1, y);
    // }
    // if (grid->mat[x][y - 1] == 0 || grid->mat[x][y - 1] == 32) // left
    // {
    //     // Grid grid2;
    //     // memcpy(&grid2, grid, sizeof(Grid));
    //     // grid2.mat[x][y] = 2;
    //     bktkLevel1(grid, x, y - 1);
    // }
}
