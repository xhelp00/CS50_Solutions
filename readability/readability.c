#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    float L = 0;
    float S = 0;
    float index = 0;

    //user input
    string text = get_string("Text: ");

    //todo calculate letters, words, sencentes in loop
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //because of last word without space
    words += 1;

    //printf("Letters %i\n", letters);
    //printf("Words %i\n", words);
    //printf("Sentences %i\n", sentences);

    //calculation of L and S
    //where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text
    L = ((float)letters / (float)words) * 100.0;
    S = ((float)sentences / (float)words) * 100.0;
    //printf("%f\n", L);
    //printf("%f\n", S);

    //calculation of index
    index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    //printf("%i\n", (int)grade);

    //printing final grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    return 0;
}