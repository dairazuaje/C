#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int coins;
    int cents;
    float change;
    do
    {
        change = get_float("Please enter the amount of change due: \n");
    }
    while (change < 0.00);

    change = round(change * 100); //Addresses floating point precision problems
    cents = change;

    //Loops through and determines number of coins needed for change depending on how much change is needed

    for (coins = 0; cents != 0; coins++)
    {
        if(cents >= 25)
        {
            cents -= 25;
        }
        else if(cents >= 10)
        {
            cents -= 10;
        }
        else if(cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
    }
    printf("%i\n", coins);


}
