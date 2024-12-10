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

    finalTitleSeq(); // TITLE
    finalLevel1(&gridLv1); // LEVEL 1
    finalLevel2(&gridLv2); // LEVEL 2
    finalLevel3(&gridLv3); // LEVEL 3

    return 0;
}
