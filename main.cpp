#include <iostream>

// #include "backtracking.h"
#include "menu.h"
#include "utils.h"

int main()
{
    // char c;
    // int choice = -1;

    Grid gridLv1, gridLv2, gridLv3;
    initGrid(&gridLv1, "level1.txt");
    initGrid(&gridLv2, "level2.txt");
    initGrid(&gridLv3, "level3.txt");
    // readGrid(&gridLv1, "level1.txt");
    // readGrid(&gridLv2, "level2.txt");
    // readGrid(&gridLv3, "level3.txt");
    //
    // memcpy(gridLv1.originalMat, gridLv1.mat, sizeof(gridLv1.mat));
    // memcpy(gridLv2.originalMat, gridLv2.mat, sizeof(gridLv2.mat));

    // finalTitleSeq(); // TITLE
    // finalLevel1(&gridLv1); // LEVEL 1

    displayGrid(&gridLv2);
    if (bktkLevel2(&gridLv2, 1, 1))
    {
        system("cls");
        printf("Level 2 completed!\n");
    }
    waitForEnter(1);

    return 0;
}
