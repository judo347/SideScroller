#include <stdio.h>

#define wide 20
#define hight 6

int initializeMap() /* initializes / updating the map */
{
    int x, y;
    for(x=0; x<wide; x++)
    {
        printf("%d", x);
        for(y=0; y<hight; y++)
            printf("%d", y);
        printf("\n");
    }
    return 0;
}

int main()
{
    initializeMap();
    return 0;
}
