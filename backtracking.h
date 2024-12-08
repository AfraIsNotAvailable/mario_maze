//
// Created by afra-laptop on 07/12/2024.
//

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_SOLUTIONS 4
#define MAX_STEPS 324
#define MAX_COINS 10

#define MASK_WALL   0x01 // 1
#define MASK_END    0x02 // 2
#define MASK_MARIO  0x04 // 4
#define MASK_COIN   0x08 // 8
#define MASK_FILL   0x20 // 32
#define MASK_PARENT 0xF00// 384
#define MASK_UP     0x100// 256
#define MASK_DOWN   0x200// 512
#define MASK_LEFT   0x400// 1024
#define MASK_RIGHT  0x800// 2048

typedef struct _node
{
    int color;
    int dist;
    struct _node* parent;
} Node;

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
} Grid;

void bktkLevel1(Grid* grid, int x, int y);

#endif //BACKTRACKING_H
