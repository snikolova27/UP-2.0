#include <iostream>

const int MAX_WORDS = 100;
const int MAX_LETTERS = 50;

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

void strcopy(const char *src, char dest[])
{
    int len = strlen(src) + 1;
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int input(char string[][MAX_LETTERS])
{
    int cnt = 0;
    while (true)
    {
        std::cin >> string[cnt];
        if (string[cnt][0] == '#' && string[cnt][1] == '#' && strlen(string[cnt]) == 2)
        {
            break;
        }
        cnt++;
    }

    return cnt;
}
int main()
{
    char sentence[MAX_WORDS][MAX_LETTERS] = {};
    int cntWords = input(sentence);

    int maxLen = strlen(sentence[0]);
    int maxIdx = 0;

    for (int i = 1; i < cntWords; i++)
    {
        if (strlen(sentence[i]) > maxLen)
        {
            maxLen = strlen(sentence[i]);
            maxIdx = i;
        }
    }

    char maxWord[MAX_LETTERS] = {};
    strcopy(sentence[maxIdx], maxWord);

    std::cout << "Max len: " << maxLen << " - " << maxWord << std::endl;

    if (cntWords == 2)
    {
        if (maxIdx == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                maxWord[j] = sentence[1][j];
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                maxWord[j] = sentence[0][j];
            }
        }
    }

    std::cout << "Result of changing first 3 letters: " << maxWord << std::endl;

    return 0;
}