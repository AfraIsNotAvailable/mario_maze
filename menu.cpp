//
// Created by afra-laptop on 07/12/2024.
//

#include "menu.h"

#include <fstream>
#include <iostream>

#include "utils.h"

void finalLevel1(Grid *grid)
{
    int choice = -1;
    system("cls");
    bktkLevel1(grid, 1, 1);
    do
    {
        system("cls");
        displayLevel1();
        printf("Alege optiunea care crezi ca il ajuta pe Mario:\n");
        displaySolutions(grid);
        printf("> ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 3)
        {
            system("cls");
            printf("Acest drum nu este cel optim!\nMario nu poate merge pe aici!!\n");
            // delay(3000);
            waitForEnter();
        }
        else if (choice != 2)
        {
            system("cls");
            printf("OH NO!\nAceasta optiune nu exista!\n");
            // delay(3000);
            waitForEnter();
        }
    }
    while (choice != 2);
    system("cls");
    printf("BINE COAIEEE!!!!!!!\n");
    // delay(3000);
    waitForEnter();
}

void finalTitleSeq()
{
    delay(500);
    displayTitle();
    printf("\n\nApasa orice tasta pentru a continua...");
    waitForEnter(1);
}


void displayMario()
{
    printf("\n");
    std::ifstream f("mario.txt");

    // set_text_color(6, 0);
    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void displayTitle()
{
    printf("\n");
    std::ifstream f("title.txt");

    // set_text_color(6, 0);
    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void displayLevel1()
{
    printf("\n");
    std::ifstream f("text_level1.txt");

    // set_text_color(6, 0);
    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
    printf("\nAjuta-l pe Mario sa aleaga drumul optim pentru a ajunge la urmatorul nivel!\n\n");
}

void displaySolutions(const Grid *grid)
{
    for (int i = 0; i < grid->solutionSize; i++)
    {
        printf("\nOptiunea %d:\n\n", i+1);
        displaySolution(grid, i);
        printf("\nPasi: %d\n", grid->steps[i]);
        printf("Coins: %d\n", grid->coins[i]);
        printf("-----------------------------\n");
    }
}
