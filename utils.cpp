//
// Created by afra-laptop on 07/12/2024.
//

#include "utils.h"

#include <cstdio>
#include <unistd.h>

// #include "backtracking.h"

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

//order:                                black, blue, green, cyan, red, magenta, yellow, white, gray, lblue, lgreen, lcyan, lred, lmagenta, lyellow, bwhite
const unsigned char CONS_COLORS_FG[] = {30, 34, 32, 36, 31, 35, 33, 37, 90, 94, 92, 94, 91, 95, 93, 97};
const unsigned char CONS_COLORS_BG[] = {49, 44, 42, 46, 41, 45, 43, 47, 100, 104, 102, 106, 101, 105, 103, 107};

int set_text_color(unsigned char foreground, unsigned char background = 0)
{
    if (background >= 16 || foreground >= 16)
    {
        return -1;
    }
#ifdef _MSC_VER
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hConsole == NULL){
        return -2;
    }
    SetConsoleTextAttribute(hConsole, foreground+(background<<4));
#else
    if (!isatty(fileno(stdout))) return 0;
    printf("\e[%d;%dm", CONS_COLORS_FG[foreground], CONS_COLORS_BG[background]);
#endif
    return 0;
}

int reset_text_color()
{
#ifdef _MSC_VER
    set_text_color(7,0);
#else
    if (!isatty(fileno(stdout))) return 0;
    printf("\e[0m");
#endif
    return 0;
}

int readGrid(Grid* grid, const char* filename)
{
    int i, j;

    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d %d", &(grid->rows), &(grid->cols));
    if (grid->rows >= MAX_ROWS || grid->cols >= MAX_COLS)
    {
        return -1;
    }
    for (i = 0; i < grid->rows; ++i)
    {
        for (j = 0; j < grid->cols; ++j)
        {
            fscanf(fin, "%d", &(grid->mat[i][j]));
        }
    }
    return 0;
}

enum GridColor
{
    COLOR_WALL = 14, // Light gray background
    COLOR_EMPTY = 0, // Black
    COLOR_FILL = 6, // Cyan
    COLOR_COIN = 6, // Cyan (foreground)
    COLOR_MARIO = 15, // Red
    COLOR_MARIO_BG = 4, // White background
    COLOR_END = 15, // Green
    COLOR_END_BG = 10, // White background
};

void displayGridElement(int cellValue)
{
    int foreground = COLOR_EMPTY;
    int background = COLOR_EMPTY;
    const char* display = "  ";

    if (cellValue & MASK_WALL)
    {
        foreground = COLOR_EMPTY;
        background = COLOR_WALL;
        display = "  ";
    }

    else if (cellValue & MASK_MARIO)
    {
        foreground = COLOR_MARIO;
        background = COLOR_MARIO_BG;
        display = "SM";
    }

    else if (cellValue & MASK_END)
    {
        foreground = COLOR_END;
        background = COLOR_END_BG;
        display = " ]";
    }

    else if (cellValue & MASK_FILL)
    {
        foreground = COLOR_FILL;
        background = COLOR_FILL;
    }

    else if (cellValue & MASK_COIN)
    {
        foreground = COLOR_COIN;
        display = "()";
    }

    set_text_color(foreground, background);
    printf("%s", display);
    reset_text_color();
}

void displayGrid(const Grid* grid, int lastCommand)
{
    int i, j;
    // system("cls");
    for (i = 0; i < grid->rows; ++i)
    {
        if (i == 0)
        {
            //draw the upper line
            printf("  |");
            for (j = 0; j < grid->cols; ++j)
            {
                printf("%2d|", j);
            }
            printf("\n--+");
            for (j = 0; j < grid->cols; ++j)
            {
                printf("--+");
            }
            printf("\n");
        }
        printf("%2d|", i);

        for (int j = 0; j < grid->cols; ++j)
        {
            displayGridElement(grid->mat[i][j]);
            printf("|");
        }
        printf("\n--+");
        for (int j = 0; j < grid->cols; ++j)
        {
            printf("--+");
        }
        printf("\n");

        // if (i == 0)
        // {
        //     //draw the upper line
        //     printf("  |");
        //     for (j = 0; j < grid->cols; ++j)
        //     {
        //         printf("%2d|", j);
        //     }
        //     printf("\n--+");
        //     for (j = 0; j < grid->cols; ++j)
        //     {
        //         printf("--+");
        //     }
        //     printf("\n");
        // }
        // printf("%2d|", i);
        // for (j = 0; j < grid->cols; ++j)
        // {
        //     if (grid->mat[i][j] & MASK_END)
        //     {
        //         if (grid->mat[i][j] & MASK_WALL)
        //         {
        //             set_text_color(2, 15);
        //             printf("##");
        //         }
        //         else
        //         {
        //             set_text_color(2, 2);
        //             printf("  ");
        //         }
        //     }
        //     else if (grid->mat[i][j] & MASK_MARIO)
        //     {
        //         if (grid->mat[i][j] & MASK_WALL)
        //         {
        //             set_text_color(4, 15);
        //             printf("##");
        //         }
        //         else
        //         {
        //             set_text_color(15, 4);
        //             printf("SM");
        //         }
        //     }
        //     else if (grid->mat[i][j] & MASK_FILL)
        //     {
        //         if (grid->mat[i][j] & MASK_WALL)
        //         {
        //             set_text_color(1, 15);
        //             printf("##");
        //         }
        //         else
        //         {
        //             set_text_color(1, 6);
        //             printf("  ");
        //         }
        //     }
        //     else if (grid->mat[i][j] & MASK_WALL) // wall
        //     {
        //         set_text_color(0, 14);
        //         printf("  ");
        //     }
        //     // else if (grid->mat[i][j] & MASK_COIN)
        //     // {
        //     //     set_text_color(6, 0);
        //     //     printf("()"); // coin
        //     // }
        //     else if (grid->mat[i][j] & MASK_COIN)
        //     {
        //         set_text_color(6, 0);
        //         printf("()"); // coin
        //     }
        //     else
        //     {
        //         printf("  "); // empty
        //     }
        //     reset_text_color();
        //     printf("|");
        // }
        // printf("\n--+");
        // for (j = 0; j < grid->cols; ++j)
        // {
        //     printf("--+");
        // }
        // printf("\n");
    }
}
