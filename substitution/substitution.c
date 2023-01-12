#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool uniqueCharacters(string str);

int main(int argc, string argv[])
{
    //we expect exactly 2 arguments
    if (argc == 2)
    {
        //calculation of length
        int n = strlen(argv[1]);

        //case of more or less chars then expected
        if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            string key = argv[1];
            //looping through the key
            for (int i = 0; i < n; i++)
            {
                //case of not alphabetic chars in the key
                if (!(isalpha(key[i])))
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }
                //at this point we are almost sure about validity but need to change lower case (if any) to upper case in key string
                else
                {
                    if (key[i] >= 'a' && key[i] <= 'z')
                    {
                        key[i] -= 32;
                    }
                }
            }
            printf("%s\n", key);
            //calling check of possible doubling of chars in the key
            if (!(uniqueCharacters(key)))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
            //user input of plaintext
            string word1 = get_string("plaintext: ");
            //looping through entered text and changing each char based on given key
            for (int x = 0, y = strlen(word1); x < y; x++)
            {
                //case of lower calling standart tolower function
                if (islower(word1[x]))
                {
                    word1[x] = tolower(key[word1[x] - 97]);
                }
                else if (isupper(word1[x]))
                {
                    word1[x] = key[word1[x] - 65];
                }
            }
            //finaly printing out changed text
            printf("ciphertext: %s\n", word1);

            return 0;
        }

    }
    //case of too many/few arguments passed
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

//bool function checks if there are any 2 chars the same
bool uniqueCharacters(string str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}