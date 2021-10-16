#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask user their name and greet thme.
    string answer = get_string("What is your name? ");
    printf("hello, %s!\n", answer);
}