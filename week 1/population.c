#include <stdio.h>
#include <cs50.h>

int positive_integer(string);


int main(void)
{
    // Get start and end populations of llamas.
    int start_pop = positive_integer("Enter start population: ");

    // End population should be greater than or equal to start population.
    int end_pop;
    do
    {
        end_pop = positive_integer("Enter end population: ");
    }
    while (end_pop < start_pop);

    // Count numbers of years required to grow llamas.
    int current_pop = start_pop;
    int years = 0;
    while (current_pop < end_pop)
    {
        current_pop += (current_pop/3 - current_pop/4);
        years++;
    }

    printf("Years: %i\n", years);
}


int positive_integer(string prompt)
{
    // Get a number from user greater than 9.
    int i;
    do
    {
        i = get_int("%s", prompt);
    }
    while (i < 9);

    return i;
}
