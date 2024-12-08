//
// Created by afra-laptop on 07/12/2024.
//

#include "menu.h"

#include <fstream>
#include <iostream>

#include "utils.h"

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
