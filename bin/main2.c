#include <stdio.h>
#include <stdlib.h>


#define holeChance 3

int rng(int possible)
{
    return possible = rand() % possible;
}

int map(int playPosX, int playPosY, int gameState) /*OUTPUT on screen*/
{
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

}

void clearScr() /* CLEARS THE SCREEN */
{
    system("@cls||clear");
}

int move(int playPosX, int playPosY) /* HANDLING PLAYER MOVEMENT/INPUT int playPosX, int playPosY*/
{
    int playPos[2] = {playPosX,playPosY};
    int c = getche();
    switch(c)
    {
        case 'w' : printf("w\n");
            break;
        case 'a' : playPos[0]--; /* x- */
            break;
        case 's' : printf("s\n");
            break;
        case 'd' : printf("d\n");
            break;
        default : printf("Something went wrong!\n");
    }
    return playPos;
}



int main(void)
{
    int gameState = 1; /* 1 = running, 0 = game has ended */
    srand(time(NULL));
    int i, x;
    int playX = 5, playY = 5;
    int playPos[2] = {playX, playY};

    /* int playerPosX = 5, playerPosY = 5; */

    while(gameState)
    {
        //map(playerPosX,playerPosY,gameState);
        //printf("%d %d", playerPosX, playerPosY);
        map(playPos[0],playPos[1],gameState);
        printf("%d %d", playPos[0], playPos[1]);
        playPos = move(playPos);
        clearScr();

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
