#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int letterCount(string s);
float wordCount(string s);
int sentenceCount(string s);


int main(void)
{
    string text = get_string("Text: ");

    // Calculate grade of input text.
    float W = wordCount(text);
    float index = 0.0588 * ((letterCount(text) / W) * 100) - 0.296 * ((sentenceCount(text) / W) * 100) - 15.8;
    int grade = round(index);

    // Print the grade.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int letterCount(string s)
{
    // Count letters in a given string.
    int letter_count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
        {
            letter_count += 1;
        }
    }

    return letter_count;
}


float wordCount(string s)
{
    // Count words in a given string.
    float word_count = 1.0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            word_count += 1;
        }
    }

    return word_count;
}


int sentenceCount(string s)
{
    // Count sentences in a given string.
    int sentence_count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence_count += 1;
        }
    }

    return sentence_count;
}
