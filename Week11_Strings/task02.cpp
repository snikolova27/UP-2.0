#include <iostream>

const int MAX_WORD_LENGHT = 20;

void print(char str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

int strlenS(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

void strcopy(char dest[], const char src[])
{
    int pos = 0;
    while (src[pos])
    {
        dest[pos] = src[pos];
        pos++;
    }
    dest[pos] = '\0';
}

int main()
{
    char string[20] = {};
    char maxLenght[20] = {};

    int currentLen = 0;
    int maxLen = 0;
    bool end = 1;

    do
    {
        std::cin >> string;
        currentLen = strlenS(string);

        if (string[currentLen - 1] == '.')
        {
            string[currentLen - 1] = '\0';
            end = 0;
            currentLen--;
        }

        if (currentLen > maxLen)
        {
            maxLen = currentLen;
            strcopy(maxLenght, string);
        }
    } while (end);

    std::cout << maxLenght << std::endl;

    return 0;
}