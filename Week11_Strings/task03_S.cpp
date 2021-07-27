#include <iostream>
const int MAX_WORDS = 1000;
const int MAX_LETTERS = 50;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

bool strcomp(const char str1[], const char str2[])
{
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }
    int len = strlen(str1);
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

int input(char str[][MAX_LETTERS])
{
    int cnt = 0;
    while (true)
    {
        std::cin >> str[cnt];
        if (str[cnt][0] == '#' &&  str[cnt][1] == '#' && strlen(str[cnt]) == 2 ) //when to stop reading
        {
            break;
        }
        cnt++;
    }

    return cnt;
}

void print(const char str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << str[i];
    }
}

int main()
{
    char string[MAX_WORDS][MAX_LETTERS] = {};
    int cntOfWords = input(string);

    for (int i = 0; i < cntOfWords; i++)
    {
        int cnt = 1;

        if (string[i][0] != '#' && string[i][1] != '#')
        {
            for (int j = i + 1; j < cntOfWords; j++)
            {
                if (strcomp(string[i], string[j]))
                {
                    cnt++;
                    string[j][0] = '#';
                    string[j][1] = '#';
                }
            }
        }

        if (cnt > 1)
        {
            print(string[i], strlen(string[i]));
            std::cout << " " << cnt << " times" << std::endl;
        }
    }

    return 0;
}