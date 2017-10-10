#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#define holeChance 3
#define width 9
#define hight 6

char map[hight][width];

void moveMapOne()
{
    int x, y;
    for(x=0; x<hight; x++)
    {
        for(y=0; y<width; y++)
        {
            if(x != width-2)
                map[x][y] = map[x][y+1];
        }
    }
}

//shift array

int rng(int possible)
{
    return possible = rand() % possible;
}

/* MAP SECMENT */
int initializeMap(int playPosY, int playPosX, int gameState) /* initializes / updating the map */
{
    int x, y;
    gameState = 1;
    for(x=0; x<hight; x++)
    {
        for(y=0; y<width; y++)
        {
            if(x == playPosX && y == playPosY) /* The player */
                map[x][y] = 'x';
            else if(x == 0)
                map[x][y] = 95;
            else if(x == 2 && y == 5)
                map[x][y] = 'M';
            else if(x == 3 && y == 1)
                map[x][y] = 'M';
            else
                map[x][y] = ' ';

        }
    }
    return gameState;
}

void printMap()
{
    int x, y;
    clearScr();
    for(x=0; x<hight; x++)
    {
        for(y=0; y<width; y++)
        {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

/* MAP SECMENT END */

void clearScr() /* CLEARS THE SCREEN */
{
    system("@cls||clear");
}


int main(void)
{
    int gameState = 1; /* 1 = running, 0 = game has ended */
    srand(time(NULL));
    int i, x;
    int playPosX = 5, playPosY = 4, poiX = 5, poiY = 4;

    gameState = initializeMap(playPosX, playPosY, gameState);

    while(gameState)
    {
        //map[5][3] = '*';
        printMap();
        moveMapOne();
        Sleep(1000);
    }

	return 0;
}

