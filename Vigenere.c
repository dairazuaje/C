#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Determines if program should continue running or not
    if (argc != 2)
    {
        printf("Incorrect number of arguments found");
        return 1;
    }
    else
    {
        for(int i = 0; i < strlen(argv[1]); i++)
        {
            if(isdigit(argv[1][i]))
            {
                printf("Improper argument found");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");

    int spaceswap [strlen(plaintext)];

    //Loops through the second command line argument provided by the user to determine the number of swaps
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if(isupper(argv[1][i]))
        {
            spaceswap[i] = argv[1][i] - 65;
        }
        else if (islower(argv[1][i]))
        {
            spaceswap[i] = argv[1][i] - 97;
        }
    }
    printf("ciphertext: ");
    //Loops through the plaintext and swaps the letters based on what is provided in the command line
    for(int j = 0, k = strlen(plaintext), l = 0; j < k; j++)
    {
        //Ensures that the new character is a letter, not a special character, and uppercase
        if(isupper(plaintext[j]))
        {
            if(l > (strlen(argv[1]) - 1))
            {
                l = 0;
                plaintext[j] = (plaintext[j] + spaceswap[l] - 65) % 26;
                printf("%c", plaintext[j] + 65);
                l++;
            }
            else
            {
                plaintext[j] = (plaintext[j] + spaceswap[l] - 65) % 26;
                printf("%c", plaintext[j] + 65);
                l++;
            }
        }
        //Ensures that the new character is a letter, not a special character, and lowercase
        else if(islower(plaintext[j]))
        {
            if(l > (strlen(argv[1]) - 1))
            {
                l = 0;
                plaintext[j] = (plaintext[j] + spaceswap[l] - 97) % 26;
                printf("%c", plaintext[j] + 97);
                l++;
            }
            else
            {
                plaintext[j] = (plaintext[j] + spaceswap[l] - 97) % 26;
                printf("%c", plaintext[j] + 97);
                l++;
            }
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
