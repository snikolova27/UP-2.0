#include <iostream>

const int MAX_WORDS = 100;
const int MAX_LETTERS_WORD = 50;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

void strcopy(const char source[], char dest[])
{
    int len = strlen(source) + 1;
    for (int i = 0; i < len; i++)
    {
        dest[i] = source[i];
    }
    dest[len] = '\0';
}

int input(char str[][MAX_LETTERS_WORD])
{
    int cnt = 0;
    while (true)
    {
        std::cin >> str[cnt];
        if (str[cnt][0] == '.' && strlen(str[cnt]) == 1)
        {
            break;
        }
        cnt++;
    }

    return cnt;
}

int main()
{
    char sentence[MAX_WORDS][MAX_LETTERS_WORD] = {};
    int cntWords = input(sentence);

    int maxLen = strlen(sentence[0]);
    int maxWordIdx = 0;

    for (int i = 1; i < cntWords; i++)
    {
        int len = strlen(sentence[i]);
        if (len > maxLen)
        {
            maxLen = len;
            maxWordIdx = i;
        }
    }
    char result[MAX_LETTERS_WORD] = {};
    strcopy(sentence[maxWordIdx], result);
    std::cout << result << " - " << maxLen << " symbols" << std::endl;

    return 0;
}