//
// Created by afra-laptop on 07/12/2024.
//

#include "menu.h"

#include <fstream>
#include <iostream>

void printTitle(const char* filename)
{
    printf("\n");
    std::ifstream f(filename);

    if (f.is_open())
        std::cout << f.rdbuf();
}
