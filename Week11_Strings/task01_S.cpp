#include <iostream>

const int MAX_STR_LEN = 1000;
const int SYMBOLS = 256;

void input(char str[])
{
    int i = 0;
    char ch;
    std::cin >> ch;

    while (ch != '!')
    {
        str[i] = ch;
        std::cin >> ch;
        i++;
    }
}

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

int main()
{
    char string[MAX_STR_LEN] = {};
    std::cout << "Enter string: ";
    input(string);
    int len = strlen(string);

    int symbols[SYMBOLS] = {};

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < SYMBOLS; j++)
        {
            if ((int)string[i] == j)
            {
                symbols[j]++;
            }
        }
    }

    std::cout << string << std::endl;

    for (int i = 0; i < SYMBOLS; i++)
    {
        if (symbols[i])
        {
            std::cout << char(i) << " - " << symbols[i] << " times" << std::endl;
        }
    }

    return 0;
}