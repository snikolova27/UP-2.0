#include <iostream>

const int MAX_STRING_LEN = 500;
const int MAX_WORD_LEN = 10;
const int ALPHABET = 26;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

int sameLetters(char string[], char word[])
{
    int strLen = strlen(string);
    int wordLen = strlen(word);

    char alphabet[ALPHABET] = {};
    int lettersInStr[ALPHABET] = {};
    int lettersInWord[ALPHABET] = {};

    int cnt = 0;

    for (int i = 0; i < ALPHABET; i++)
    {
        alphabet[i] = 'a' + i;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        for (int j = 0; j < strLen; j++)
        {
            if (alphabet[i] == string[j])
            {
                lettersInStr[i] += 1;
                break;
            }
        }
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        for (int j = 0; j < wordLen; j++)
        {
            if (alphabet[i] == word[j])
            {
                lettersInWord[i] += 1;
                break;
            }
        }
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        if (lettersInStr[i] == lettersInWord[i] && lettersInStr[i] != 0 && lettersInWord[i] != 0)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    char string[MAX_STRING_LEN] = {}, word[MAX_WORD_LEN] = {};
    std::cin >> string;
    std::cin >> word;

    std::cout << sameLetters(string, word) << std::endl;

    return 0;
}