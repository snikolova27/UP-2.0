#include <iostream>

const int MAX_NAMES = 100;
const int MAX_LETTERS_IN_NAME = 50;

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
    else
    {
        int len = strlen(str1);
        for (int i = 0; i < len; i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }
    }

    return true;
}

int input(char list[][MAX_LETTERS_IN_NAME])
{
    std::cout << "Enter names: ";

    int i = 0;
    while (true)
    {
        std::cin >> list[i];
        if (strlen(list[i]) == 2 && list[i][0] == '#' && list[i][1] == '#')
        {
            break;
        }
        i++;
    }

    return i;
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
    char listOfNames[MAX_NAMES][MAX_LETTERS_IN_NAME] = {};
    int cntOfNames = input(listOfNames);

    for (int i = 0; i < cntOfNames; i++)
    {
        int cnt = 1;

        if (listOfNames[i][0] != '#' && listOfNames[i][1] != '#')
        {
            for (int j = i + 1; j < cntOfNames; j++)
            {
                if (strcomp(listOfNames[i], listOfNames[j]))
                {
                    cnt++;
                    listOfNames[j][0] = '#'; //marks it as already counted
                    listOfNames[j][1] = '#';
                }
            }

            if (cnt > 1)
            {
                print(listOfNames[i], strlen(listOfNames[i]));
                std::cout << " " << cnt << " times" << std::endl;
            }
        }
    }

    return 0;
}