#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#define holeChance 3


int rng(int possible)
{
    return possible = rand() % possible;
}

int map(int playPosX, int playPosY, int gameState) /*OUTPUT on screen*/
{
    clearScr(); /* Clears the screen! */
    int i, x;
    int wide = 20;
    int high = 6;
    /* LINE ONE */
    for(i=0;i<wide;i++)
        printf("S");
    printf("\n");
    /* LINE TWO */

    printf("\n");
    /* LINE THREE */

    printf("\n");
    /* LINE FOUR */

    printf("\n");
    /* LINE FIVE */
    for(i=0;i<wide;i++)
    {
        if(playPosX == i)
        printf("P");
        else
        printf(" ");
    }

    printf("\n");
    /* LINE SIX - BASE LINE */
    if(playPosY == 6) /* CHECK, is the player in a hole in the floor? */
        {
                printf("Player felt through the floor!\n");
                gameState = 0;
                return 0;
        }

    for(i=0;i<wide;i++) /* LOOP ofr chancing a line*/
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

int jump() /* PLAYER JUMPING */
{
    return 0;
}

void clearScr() /* CLEARS THE SCREEN */
{
    system("@cls||clear");
}

void move(int playPosX, int playPosY, int* poiX, int* poiY) /* HANDLING PLAYER MOVEMENT/INPUT int playPosX, int playPosY*/
{
    /* int playPos[2] = {playPosX,playPosY}; */
    int c = getche();
    switch(c)
    {
        case 'w' : printf("w\n"); /* JUMP */
                   playPosX = playPosX + 1;
                   playPosY = playPosY - 1;
                   map(playPosX, playPosY, 1);
                   Sleep(500);
                   playPosX = playPosX + 1;
                   map(playPosX, playPosY, 1);
                   Sleep(500);
                   *poiX = playPosX + 1;
                   *poiY = playPosY + 1;

            break;
        case 'a' : *poiX = --playPosX; /* x--  playPos[0]--*/
            break;
        case 's' : printf("s\n");
            break;
        case 'd' : *poiX = ++playPosX; /* x++ */
            break;
        default : printf("Something went wrong!\n");
    }
    /* return playPos; */
}



int main(void)
{
    int gameState = 1; /* 1 = running, 0 = game has ended */
    srand(time(NULL));
    int i, x;
    int playPosX = 5, playPosY = 5, poiX = 5, poiY = 5;
    /* int playPos[2] = {playX, playY}; */

    /* int playerPosX = 5, playerPosY = 5; */

    while(gameState)
    {
        /* printf("%d %d", playPosX, playPosY); /* TEST */
        map(playPosX, playPosY, gameState);
        printf("%d %d", playPosX, playPosY); /* TEST */

        move(playPosX, playPosY, &poiX, &poiY); /* Sending the x and y coord to move-function (and the pointers) */
        playPosX = poiX; /* Saving the pointer in the variable */
        playPosY = poiY; /* Saving the pointer in the variable  */



    }
    /*
	if(map(playerPosX,playerPosY,gameState) == 0)  /* CHECK THE GAME STATUS. END THE GAME IF 0 IS RETURNED
    {
        printf("Game has ended!");
        return 0;
    }


    /*TEST AREA BELOW
    for(i=0;i<10;i++) /*LOOP ofr chancing a line
    {
        int ranNum;
        for(x=0;x<holeChance;x++)
        {
            ranNum = rng(2);
            if(ranNum == 1)
                x = holeChance;
        }
        if(ranNum == 1)
            printf("-");
        else
            printf(" ");
    }


	int i;
	for(i=0;i>10;i++)*/

	return 0;
}
