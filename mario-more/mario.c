#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
//this part declares variables
    int h = 0;
    int i = 0;
    int r = 1;
    int s = 0;
    int x = 0;
//this part is checking user input
    do
    {
        h = get_int("Height: ");
    }
    while (!(h > 0 && h < 9));
//next part is for building pyramids
    while (r <= h)
    {
//printing initial spaces
        s = h - r;
        while (s > 0)
        {
            printf(" ");
            s--;
        }
//printing first pyramid
        x = r;
        while (x > 0)
        {
            printf("#");
            x--;
            i++;
        }
//printing fixed 2 spaces
        printf("  ");
//printing second pyramid
        while (i > 0)
        {
            printf("#");
            i--;
        }
//printing new line
        printf("\n");
        r++;
    }
}