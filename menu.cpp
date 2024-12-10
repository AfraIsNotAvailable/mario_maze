//
// Created by afra-laptop on 07/12/2024.
//

#include "menu.h"

#include <fstream>
#include <iostream>

#include "utils.h"

void displayPowerUp()
{
    printf("\n");
    std::ifstream f("powerup.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}


void displayGameOver(std::string message)
{
    printf("\n");
    std::ifstream f("game_over.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
    printf("\n%s\n", message.c_str());
}


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
    displayCompletedLevel1();
    // delay(3000);
    waitForEnter();
}

void finalLevel2(Grid* grid)
{
    if (bktkLevel2(grid, 1, 1))
    {
        system("cls");
        displayCompletedLevel2();
        waitForEnter(1);
    }
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

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void displayCompletedLevel1()
{
    printf("\n");
    std::ifstream f("text_completed_level1.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void displayCompletedLevel2()
{
    printf("\n");
    std::ifstream f("text_completed_level2.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
}

void finalLevel3(Grid* grid)
{
    bktkLevel3(grid, 1, 1, 0, 2); // steps: 4 - default; schimba daca vrei sa vezi mai multi pasi deodata
    delay(500);
    system("cls");
    displayYouWon();
    delay(2000);
    printf("\n\nPress ENTER to exit...");
    waitForEnter(1);
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

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
    printf("\nAjuta-l pe Mario sa aleaga drumul optim pentru a ajunge la urmatorul nivel!\n\n");
}

void displayLevel2()
{
    printf("\n");
    std::ifstream f("text_level2.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
    printf("\n\n");
}

void displayLevel3()
{
    printf("\n");
    std::ifstream f("text_level3.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
    printf("\n\n");
}

void displayYouWon()
{
    printf("\n");
    std::ifstream f("you_won.txt");

    if (f.is_open())
    {
        std::cout << f.rdbuf();
    }
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
