#include <iostream>

// #include "backtracking.h"
#include "menu.h"
#include "utils.h"

int main()
{
    int choice = -1;

    Grid gridLv1, gridLv2, gridLv3;
    readGrid(&gridLv1, "level1.txt");
    readGrid(&gridLv2, "level2.txt");
    readGrid(&gridLv3, "level3.txt");

    memcpy(gridLv1.originalMat, gridLv1.mat, sizeof(gridLv1.mat));

    delay(500);
    displayTitle();
    printf("\n\nApasa orice tasta pentru a continua...");
    std::cin.get();
    system("cls");
    bktkLevel1(&gridLv1, 1, 1);
    do
    {
        system("cls");
        displayLevel1();
        printf("Alege optiunea care crezi ca il ajuta pe Mario:\n");
        displaySolutions(&gridLv1);
        printf("> ");
        std::cin >> choice;
        if (choice == 1 || choice == 3)
        {
            system("cls");
            printf("Acest drum nu este cel optim!\nMario nu poate merge pe aici!!\n");
            delay(5000);
            std::cin.get();
        }
        else if (choice != 2)
        {
            system("cls");
            printf("OH NO!\nAceasta optiune nu exista!\n");
            delay(5000);
            std::cin.get();
        }
    }
    while (choice != 2);
    system("cls");
    printf("BINE COAIEEE!!!!!!!\n");
    delay(5000);

    std::cin.get();

    return 0;
}
