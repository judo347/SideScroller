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
            map[x][y] = map[x][y+1];
            printf("WHAT");
        }
    }
}

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
            else
                map[x][y] = ' ';

        }
        //printf("\n");
    }
    return gameState;
}

void printMap()
{
    int x, y;
    int z = 0;
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

void move(int playPosX, int playPosY, int* poiX, int* poiY) /* HANDLING PLAYER MOVEMENT/INPUT int playPosX, int playPosY*/
{
    int c = getche();
    switch(c)
    {
        case 'w' :  playPosX = playPosX + 1; /* JUMP */
                    playPosY = playPosY - 1;
                    initializeMap(playPosX, playPosY, 1);
                    printMap();
                    Sleep(200);
                    playPosX = playPosX + 1;
                    initializeMap(playPosX, playPosY, 1);
                    printMap();
                    Sleep(200);
                    playPosX = playPosX +1;
                    playPosY = playPosY +1;
                    *poiX = playPosX;
                    *poiY = playPosY;
            break;
        case 'a' :  if(playPosX != 0)
                        *poiX = --playPosX; /* Move one step to the left */
            break;
        case 'd' : *poiX = ++playPosX; /* Moves one step to the right */
            break;
        default : printf("Something went wrong!\n");
    }
}


int main(void)
{
    int gameState = 1; /* 1 = running, 0 = game has ended */
    srand(time(NULL));
    int i, x;
    int playPosX = 5, playPosY = 4, poiX = 5, poiY = 4;

    while(gameState)
    {
        gameState = initializeMap(playPosX, playPosY, gameState);
        //map[5][3] = '*';
        printMap();
        printf("%d %d", playPosX, playPosY);
        move(playPosX, playPosY, &poiX, &poiY); /* Sending the x and y coord to move-function (and the pointers) */
        playPosX = poiX; /* Saving the pointer in the variable */
        playPosY = poiY; /* Saving the pointer in the variable  */
        //moveMapOne();

        Sleep(100);
    }

	return 0;
}


/*
int map(int playPosX, int playPosY, int gameState) /*OUTPUT on screen*
{
    clearScr(); /* Clears the screen!
    int i, x;
    int wide = 20;
    int high = 6;
    /* LINE ONE
    for(i=0;i<wide;i++)
        printf("S");
    printf("\n");
    /* LINE TW
    for(i=0;i<wide;i++)
        if(playPosX == i && playPosY == 2)
            printf("P");
        else
            printf(" ");
    printf("\n");
    /* LINE THREE

    printf("\n");
    /* LINE FOUR
    for(i=0;i<wide;i++)
        if(playPosX == i && playPosY == 4)
            printf("P");
        else
            printf(" ");

    printf("\n");
    /* LINE FIVE
    for(i=0;i<wide;i++)
    {
        if(playPosX == i && playPosY == 5)
            printf("P");
        else
            printf(" ");
    }

    printf("\n");
    /* LINE SIX - BASE LINE
    if(playPosY == 6) /* CHECK, is the player in a hole in the floor
        {
                printf("Player felt through the floor!\n");
                gameState = 0;
                return 0;
        }

    for(i=0;i<wide;i++) /* LOOP  chancing a line
    {
        int ranNum;
        for(x=0;x<holeChance;x++)
        {
            ranNum = rng(2);
            if(ranNum == 1)
                x = holeChance;
        }
        if(ranNum == 1)
            printf("\"");
        else
            printf(" ");
    }

    return 1;
}
*/
