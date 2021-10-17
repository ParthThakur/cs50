#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    // Get pyramid height from user.
    int height = get_height();

    for (int  i = 0; i < height; i++)
    {
        // Print leading spaces.
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }

        // Print left side "#"
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // Print right side "#"
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");

    }
}

int get_height(void)
{
    // Reject any input not in range 1 to 8; return height provided by user.
    int height = 0;

    while (height < 1 || height > 8)
    {
        height = get_int("Enter height: ");
    }

    return height;
}
