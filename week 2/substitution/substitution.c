#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key \n");
        return 1;
    }

    if (strlen(argv[0])  != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }
}
