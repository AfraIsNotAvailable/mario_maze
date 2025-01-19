# Maze solver (Game)

![title image](/images/title.png)

## Description

This is a terminal-based C++ application (kind of a game) that uses backtracking to solve a 3-stage maze.
Everything is pure C++ so it's platform-agnostic (probably) (actually probably not BUT IT COULD BE). 
It's more of a showcase than an actual playable game

The Super Mario Bros. theme wasn't my choice :l

Note: croi if you're reading this kindly piss off :)

## Some screenshots

![level 1](/images/level1.png)
![level 2](/images/level2.png)
![level1 solutions](/images/level1_solutions.png)
![power-up](/images/powerup.png)
![game over](/images/game_over.png)

## Level 1
![level 1](/images/level1.png)

The first level is a simple maze with a single solution. The player **(SM)** can move in 4 directions: up, down, left, right.
The player can pick up coins too.
At the end there are 3 solutions. The correct one is the one with enough coins to pass but with not too many steps.

## Level 2

![level 2](/images/level2.png)

The second level is a bit more complex. The player has to avoid the goombas **(GG)** that are moving around the pillars 
**(/\\)** in a circular pattern. The point is to find a solution that avoids them.

## Level 3

![level 3](/images/level3.png)

The third level is the biggest one of them all. As such, it takes the longest time. In addition to that, there are 
certain items you can pick up and also certain enemies you have to avoid. 

The player can't go directly to the exit, it has to find the power-up first. It also can't navigate through the piranha 
plants **(^^)** so it has to find a way around them.

## Main algorithm used for solving

The backtracking algorithm utilised in this game is a naive recursive implementation.

```cpp
void bktkLevel1(Grid* grid, int x, int y)
{
    grid->mat[x][y] = 4; // 4 is the mario
    system("cls");
    displayLevel1();
    displayGrid(grid);
    delay(250); // usleep(1000000);
    if (x == grid->rows - 2 && y == grid->cols - 2)
    {
        system("cls");
        displayLevel1();
        displayGrid(grid);
        printf("End reached!\n");
        addSolution(grid);
        grid->coinsCurr = 0;
        resetCell(grid, x, y);
        delay(1000);
        return;
    }
    grid->mat[x][y] = 32;

    for (int i = 0; i < 4; ++i)
    {
        int nextRow = x + dx[i];
        int nextCol = y + dy[i];

        if (isValid(nextRow, nextCol, grid))
        {
            if (grid->mat[nextRow][nextCol] == 8)
            {
                grid->coinsCurr++;
            }
            grid->stepsCurr++;
            bktkLevel1(grid, nextRow, nextCol);
            grid->stepsCurr--;
        }
    }
    resetCell(grid, x, y);
}
```

`grid->mat[x][y] = 4` the position of the player (at each recursive call) is set to `4` **(SM)**

`if (x == grid->rows - 2 && y == grid->cols - 2)` end condition

`for (int i = 0; i < 4; ++i)` for each direction the player can go in

```
int nextRow = x + dx[i];
int nextCol = y + dy[i];
```
`dx` and `dy` are arrays that hold the directions the player can go in

`isValid(nextRow, nextCol, grid)` checks if the next position is valid

`bktkLevel1(grid, nextRow, nextCol);` recursive call

## Conclusions

This was a fun project to work on. I will NEVER EVER do something like this again. At least not in PURE C++. This was 
mad. 

If I ever have it in me, I'll probably remake this in **Godot** or any other game engine and make it more interactive. 
And fun. And less boring. And less frustrating. And less... you get the point.

