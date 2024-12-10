//
// Created by afra-laptop on 07/12/2024.
//

#ifndef MENU_H
#define MENU_H
#include <string>

#include "backtracking.h"

void startMenu();
void displayTitle();
void displayMario();
void displayCompletedLevel1();
void displayCompletedLevel2();
void displayLevel1();
void displayLevel2();
void displayLevel3();
void displaySolutions(const Grid* grid);
void finalLevel1(Grid* grid);
void finalLevel2(Grid* grid);
void finalLevel3(Grid* grid);
void finalTitleSeq();
void displayGameOver(std::string message = "");
void displayPowerUp();
void displayYouWon();

#endif //MENU_H
