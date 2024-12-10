//
// Created by afra-laptop on 07/12/2024.
//

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_SOLUTIONS 16
#define MAX_STEPS 324
#define MAX_COINS 10

typedef struct
{
    int previousCell = 0; // for remembering what to place back
    int x;
    int y;
    const int pillar_x;
    const int pillar_y;
} Goomba;

typedef struct
{
    int rows;
    int cols;
    int solutionSize = 0;
    int mat[MAX_ROWS][MAX_COLS];
    int originalMat[MAX_ROWS][MAX_COLS];
    int solutions[MAX_SOLUTIONS][MAX_ROWS][MAX_COLS];
    int steps[MAX_STEPS] = {0};
    int coins[MAX_COINS] = {0};
    int coinsCurr = 0;
    int stepsCurr = 0;
    bool marioDied = false;
    bool powerup = false;
    Goomba goombas[3] = {
    {0, 2, 2, 3, 3},
    {0, 4, 7, 5, 7},
    {0, 7, 5, 6, 4}
    };
} Grid;

void bktkLevel1(Grid* grid, int x, int y);
bool bktkLevel2(Grid* grid, int x, int y);
bool bktkLevel3(Grid* grid, int x, int y, int currentStep = 0, int step = 4);

#endif //BACKTRACKING_H
