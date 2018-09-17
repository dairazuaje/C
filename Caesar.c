#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
   int k;

   //Checks to see if exactly two command line arguments were given
   if (argc == 2)
   {
      k = atoi(argv[1]);
   }
   else
   {
      printf("No command line arguments found or too many found\n");
      return 1;
   }

   string plaintext = get_string("plain text: ");

   printf("ciphertext: ");

   //Loops through string provided by user and uses caesar's cipher to encrypt
   for(int i = 0, n = strlen(plaintext); i < n; i++)
   {
      if(isupper(plaintext[i]))
      {
         plaintext[i] = (plaintext[i] + k - 65) % 26;
         printf("%c", plaintext[i] + 65);
      }

      else if (islower(plaintext[i]))
      {
         plaintext[i] = (plaintext[i] + k - 97) % 26;
         printf("%c", plaintext[i] + 97);
      }
      else
      {
         printf("%c", plaintext[i]);
      }
   }
   printf("\n");

   return 0;
}

