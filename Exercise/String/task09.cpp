#include <iostream>

const int MAX_STRING_LEN = 1000;

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
    int pos = 0;
    while (src[pos])
    {
        dest[pos] = src[pos];
        pos++;
    }
    dest[pos] = '\0';
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isLowerCase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void change(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (isLetter(str[i]))
        {
            if (isLowerCase(str[i]))
            {
                str[i] -= ('a' - 'A');
            }
            else
            {
                str[i] += ('a' - 'A');
            }
        }
    }
}

int main()
{
    char buffer[MAX_STRING_LEN] = {};
    std::cout << "enter string: ";
    std::cin >> buffer;

    int len = strlen(buffer) + 1;

    char *string = new (std::nothrow) char[len];
    if (!string)
    {
        std::cout << "Memory allocation problem :( " << std::endl;
        return -1;
    }
    else
    {
        strcopy(buffer, string);
        change(string, len);
        std::cout << string << std::endl;
        delete[] string;
    }
    return 0;
}