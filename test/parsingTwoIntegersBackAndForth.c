#include <stdio.h>

/* IMPROVED */
void Calculate(int x, int y, int* prod, int* quot)
{
    *prod = ++x;
    *quot = --y;
}

int main()
{
    int x = 5,y = 5, prod, quot;
    Calculate(x, y, &prod, &quot);
    x = prod;
    y = quot;
    printf("%d %d\n", prod, quot);
    printf("%d %d\n", x, y);


    return 0;
}

/* WORKS
void Calculate(int x, int y, int* prod, int* quot)
{
    *prod = x*y;
    *quot = x/y;
}

int main()
{
    int x = 10,y = 2, prod, quot;
    Calculate(x, y, &prod, &quot);
    printf("%d %d\n", prod, quot);


    return 0;
}
*/

/* USING STRUCT - DOES NOT WORK!
struct player
{
    int x;
    int y;
};

void plusFunc(struct currentplayer)
{
    currentplayer.x = currentplayer.x + 1;
    currentplayer.y = currentplayer.y + 1;


}

int main(void)
{
    struct player currentplayer;
        currentplayer.x = 5;
        currentplayer.y = 5;

    printf("%d %d\n", currentplayer.x, currentplayer.y);

    return 0;
}

*/
