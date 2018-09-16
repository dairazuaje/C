#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int space, hash, height;

    //prompt user for the height of the pyramid
    do
    {
        height = get_int("Please enter the height for the pyramid (0-23)\n");
    }
    while (height < 0 || height > 23);

    //loop for rows
    for(int row = 1; row <= height; row++)
    {
        //loop for spaces
        for(space = 0; space < height - row; space++)
        {
            printf(" ");
        }
        //loop for hashes
        for(hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}M
