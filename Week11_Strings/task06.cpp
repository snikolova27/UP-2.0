#include <iostream>

const int MAX_STR_LEN = 1000;
const int MAX_REPLACE_LEN = 100;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

void ifEqual(char *sentence, char *toReplace, char *replacement, int toReplaceLen)
{
    int i = 0;
    int j = 0;

    while (sentence[i] != '\0')
    {
        if (sentence[i] == toReplace[j])
        {
            j++;
        }
        else if (sentence[i] == toReplace[0])
        {
            j = 1;
        }
        else
        {
            j = 0;
        }

        if (j == toReplaceLen)
        {
            for (int k = 0; k < j; k++)
            {
                sentence[i - k] = replacement[j - k - 1];
            }
            j = 0;
        }

        i++;
    }
}

void ifLonger(char *sentence, int lenSentence, char *toReplace, int lenToReplace, char *replacement, int lenReplacement)
{
    int i = 0;
    int j = 0;

    while (sentence[i] != '\0')
    {
        if (sentence[i] == toReplace[j])
        {
            j++;
        }
        else if (sentence[i] == toReplace[0])
        {
            j = 1;
        }
        else
        {
            j = 0;
        }

        if (j == lenToReplace)
        {
            int difference = lenReplacement - lenToReplace;
            for (int k = lenSentence - 1; k > i; k--)
            {
                sentence[k + difference] = sentence[k];
            }
            sentence[lenSentence + difference] = '\0';

            for (int l = 0; l < lenReplacement; l++)
            {
                sentence[i - lenToReplace + l + 1] = replacement[l];
            }
            i += difference;
            j = 0;
        }
        i++;
    }
}

void ifShorter(char *sentence, int lenSentence, char *toReplace, int lenToReplace, char *replacement, int lenReplacement)
{
    int i = 0;
    int j = 0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] == toReplace[j])
        {
            j++;
        }
        else if (sentence[i] == toReplace[0])
        {
            j = 1;
        }
        else
        {
            j = 0;
        }

        if (j == lenToReplace)
        {
            int difference = lenToReplace - lenReplacement;
            int lastIndex = 0;
            for (int k = lenToReplace; k > difference; k--)
            {
                sentence[i - k + 1] = replacement[lenToReplace - k];
                lastIndex = i - k + 1;
            }

            for (int q = lastIndex + 1; q < strlen(sentence); q++)
            {
                sentence[q] = sentence[q + difference];
            }
            i -= difference;
            j = 0;
        }
        i++;
    }
}

int main()
{
    char sentence[MAX_STR_LEN] = {};
    std::cout << "Enter sentence: ";
    std::cin.getline(sentence, MAX_STR_LEN);

    char toReplace[MAX_REPLACE_LEN] = {};
    std::cout << "Enter sequence to be replaced: ";
    std::cin.getline(toReplace, MAX_REPLACE_LEN);

    char replacement[MAX_REPLACE_LEN] = {};
    std::cout << "Enter replacement: ";
    std::cin.getline(replacement, MAX_REPLACE_LEN);

    int sentenceLen = strlen(sentence);
    int toBeReplacedLen = strlen(toReplace);
    int replacementLen = strlen(replacement);

    if (toBeReplacedLen == replacementLen)
    {
        ifEqual(sentence, toReplace, replacement, toBeReplacedLen);
    }

    if (toBeReplacedLen > replacementLen)
    {
        ifShorter(sentence, sentenceLen, toReplace, toBeReplacedLen, replacement, replacementLen);
    }

    else
    {
        ifLonger(sentence, sentenceLen, toReplace, toBeReplacedLen, replacement, replacementLen);
    }

    std::cout << sentence << std::endl;

    return 0;
}