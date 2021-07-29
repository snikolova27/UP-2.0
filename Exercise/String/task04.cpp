#include <iostream>

const int MAX_ARRAY = 1000;

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

void strcopy(const char *src, char *dest)
{
    int len = strlen(src) + 1;
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void removeDuplicates(char str[], int len, char result[])
{
    int resLen = 0;
    int i = 0;

    result[resLen] = str[0];

    while (i < len)
    {
        bool occured = true;
        int cntOccurence = 1;

        for (int j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                occured = true;
                cntOccurence++;
            }

            else
            {
                occured = false;
                result[resLen] = str[i];
                resLen++;
                break;
            }
            //aaaaabbbooprrrr returns abop, needs fixing
        }
        i += cntOccurence;
    }
}

int main()
{
    char string[MAX_ARRAY] = {};
    char buffer[MAX_ARRAY] = {};
    std::cin.getline(buffer, MAX_ARRAY);

    int len = strlen(buffer);
    strcopy(buffer, string);

    char result[MAX_ARRAY] = {};
    removeDuplicates(string, len, result);

    std::cout << result << std::endl;
    return 0;
}