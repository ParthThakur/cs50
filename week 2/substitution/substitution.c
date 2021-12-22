#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool check_valid(string key)
{
    bool letters[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        letters[tolower(key[i]) - 97] = true;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!letters[i])
        {
            return false;
        }
    }
    return true;
}


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key \n");
        return 1;
    }

    string key = argv[1];
    if (strlen(key)  != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    if (! check_valid(key))
    {
        printf("Entered key is invalid. \n");
        return 1;
    }

    printf("%s\n", key);


}
