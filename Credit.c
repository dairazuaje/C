#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card_number;
    int num_digits = 0;
    long long card_number_copy;

    //Prompt user for credit card number
    do
    {
        card_number = get_long_long("Enter credit card number: ");
    } while(card_number < 0);

    //creates a copy of cardnumber to use for mod 10
    card_number_copy = card_number;

    //Divides cardnumber by 10 until 0 to determine number of digits
    while (card_number != 0)
    {
        card_number /= 10;
        num_digits++;
    }

    //array to hold the cardnumbers
    long long card_nums [num_digits];

    //For loop to add credit card numbers to array
    for (int i = num_digits - 1; i >= 0; i--)
    {
        card_nums[i] = card_number_copy % 10;
        card_number_copy /= 10;
    }

    int second_from_totals = 0;

    int num1 = 0;
    int num2 = 0;
    int double_digit_num;

    //iterates through array, starting at the second number from the end and every other to multiply by two
    for (int j = num_digits - 2; j >= 0; j -= 2)
    {
        //if number * 2 is a double digit then number will be broken into two numbers using mod 10 to be added individually
        if ((card_nums[j] * 2) >= 10)
        {
            double_digit_num = (card_nums[j]*2);
            num1 = double_digit_num % 10;
            double_digit_num /= 10;
            num2 = double_digit_num % 10;
            second_from_totals = second_from_totals + num1 + num2;
        }
        //if number *2 isn't a double digit then number will be added to the total
        else
        {
            second_from_totals = second_from_totals + (card_nums[j]*2);
        }
    }

    int not_multiplied_totals = 0;

    //iterates through the numbers that weren't multiplied by two and sums them up

    for(int k = num_digits - 1; k >= 0; k -= 2)
    {
        not_multiplied_totals = not_multiplied_totals + card_nums[k];
    }

    /*-----------------------------------------------------------------------------------------------------------
     * Determines if card is American Express, MasterCard, or Visa
     *----------------------------------------------------------------------------------------------------------*/
    if((not_multiplied_totals + second_from_totals) % 10 == 0)
    {
        if(card_nums[0] == 4 && (num_digits == 13 || num_digits == 16))
        {
            printf("VISA\n");
        }
        else if(card_nums[0] == 3 && (card_nums[1] == 4 || card_nums[1] == 7) && num_digits == 15)
        {
            printf("AMEX\n");
        }
        else if(card_nums[0] == 5 && (card_nums[1] >= 1 && card_nums[1] <= 5) && num_digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
