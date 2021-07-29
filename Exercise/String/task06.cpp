#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

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

int find(const char *str, int len, char toFind)
{
    for (int i = 0; i < len; i++)
    {
        if (toFind == str[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char buffer[MAX_ARRAY_SIZE] = {};
    std::cout << "Enter string: ";
    std::cin >> buffer;

    int len = strlen(buffer);

    char result[MAX_ARRAY_SIZE] = {};
    strcopy(buffer, result);

    char ch;
    std::cout << "Enter character to find: ";
    std::cin >> ch;

    int pos = find(result, len, ch);
    if (pos >= 0)
    {
        std::cout << "Character " << ch << " is in position " << pos + 1 << " ";
        for (int i = pos + 1; i < len; i++)
        {
            std::cout << result[i];
        }
    }
    return 0;
}