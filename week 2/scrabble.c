#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}


int letterIndex(char letter)
{
    // Get index of a letter to access the POINTS array.
    letter = toupper(letter);
    int letterASCII = (int)letter;

    if (letterASCII > 64 && letterASCII < 91)
    {
        return letterASCII - 65;
    }

    // Return -1 if input is not a letter.
    return -1;

}

int compute_score(string word)
{
    // Compute score of input word.
    int score = 0;
    int wordLen = strlen(word);

    for (int i = 0; i < wordLen; i++)
    {
        int letter_index = letterIndex(word[i]);
        if (letter_index >= 0)
        {
            // Add to score only if input is a letter.
            score += POINTS[letter_index];
        }
    }

    return score;
}