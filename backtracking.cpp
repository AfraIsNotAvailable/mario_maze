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

void stepGoomba(Grid* grid, int i)
{
    if (i >= 3)
    {
        throw std::invalid_argument("Invalid goomba index");
    }
    int next_x = grid->goombas[0].x;
    int next_y = grid->goombas[0].y;

    if (grid->goombas[i].x == 2 && grid->goombas[i].y < 4)
    {
        next_y++;
    }
    else if (grid->goombas[i].x < 4 && grid->goombas[i].y == 4)
    {
        next_x++;
    }
    else if (grid->goombas[i].x == 4 && grid->goombas[i].y > 2)
    {
        next_y--;
    }
    else if (grid->goombas[i].x > 2 && grid->goombas[i].y == 2)
    {
        next_x--;
    }
    // int nextPreviousCell = grid->mat[next_x][next_y];
    grid->mat[next_x][next_y] = 16;
    grid->mat[grid->goombas[i].x][grid->goombas[i].y] = grid->goombas[i].previousCell;
    // grid->goombas[i].previousCell = nextPreviousCell;
    grid->goombas[i].x = next_x;
    grid->goombas[i].y = next_y;
}

void resetCell(Grid* grid, int x, int y)
{
    grid->mat[x][y] = grid->originalMat[x][y];
}

bool isValid(int x, int y, Grid* grid)
{
    if (x >= 1 && x <= grid->rows - 1 && y >= 1 && y <= grid->cols - 1 && grid->mat[x][y] != 1 && grid->mat[x][y] != 32
        && grid->mat[x][y] != 24)
    {
        return true;
    }
    return false;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

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
        printf("End reached!\n");
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

void bktkLevel2(Grid* grid, int x, int y)
{
    grid->mat[x][y] = 4; // 4 is the mario
    displayGrid(grid);
    // TODO: check mario died
    stepGoomba(grid, 0); // TODO: THE PROBLEM IS HERE BUT WHEEEEREEEE
    displayGrid(grid);
    // stepGoomba(grid, 1);
    // stepGoomba(grid, 2);
    // system("cls");
    // displayLevel1();
    // displayGrid(grid);
    delay(2000); // TODO: put it back
    if (x == grid->rows - 2 && y == grid->cols - 2)
    {
        system("cls");
        // displayLevel1();
        displayGrid(grid);
        printf("End reached!\n");
        // printf("Pasi: %d\n", grid->stepsCurr);
        // printf("Coins: %d\n", grid->coinsCurr);
        // addSolution(grid);
        // grid->coinsCurr = 0;
        resetCell(grid, x, y);
        delay(1000); //TODO: put it back
        return;
    }
    if (grid->marioDied)
    {
        // system("cls");
        displayGrid(grid);
        printf("Oh no! Mario died!\n");
        resetCell(grid, x, y);
        grid->marioDied = false;
        delay(1000);
        return;
    }
    grid->mat[x][y] = 32;

    for (int i = 0; i < 4; ++i)
    {
        int nextRow = x + dx[i];
        int nextCol = y + dy[i];

        if (isValid(nextRow, nextCol, grid))
        {
            // if (grid->mat[nextRow][nextCol] == 8)
            // {
            //     grid->coinsCurr++;
            // }
            grid->stepsCurr++;
            // stepGoomba(grid, 0);
            bktkLevel2(grid, nextRow, nextCol);
            displayGrid(grid);
            grid->stepsCurr--;
        }
    }
    resetCell(grid, x, y);
}
