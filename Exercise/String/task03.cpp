#include <iostream>

const int MAX_WORDS = 100;
const int MAX_LETTERS = 50;

bool isSeperator(char ch)
{
    return ch == ' ' || ch == ',' || ch == '.';
}

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

int input(char words[][MAX_LETTERS])
{
    int cnt = 0;

    while (true)
    {
        std::cin >> words[cnt];
        if (words[cnt][0] == '#' && strlen(words[cnt]) == 1)
        {
            break;
        }
        if (isSeperator(words[cnt][]))
            cnt++;
    }

    return cnt;
}

int main()
{
    char words[MAX_WORDS][MAX_LETTERS] = {};
    int cntOfWords = input(words);

    std::cout << cntOfWords << std::endl;

    return 0;
}