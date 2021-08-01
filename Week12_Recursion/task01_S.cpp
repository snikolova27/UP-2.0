#include <iostream>

const int MAX_STRING_SIZE = 2000;

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

void printRescursive(const char *str, int len, int pos)
{
    if (pos == len)
    {
        return;
    }
    std::cout << str[pos];
    return printRescursive(str, len, pos + 1);
}

int main()
{
    char buffer[MAX_STRING_SIZE] = {};
    std::cout << "Enter string: ";
    std::cin.getline(buffer, MAX_STRING_SIZE);

    int len = strlen(buffer) + 1;
    char *string = new (std::nothrow) char[len];
    if (!string)
    {
        std::cout << "Memory problem" << std::endl;
        return -1;
    }

    strcopy(buffer, string);
    std::cout << std::endl;
    int pos = 0;
    printRescursive(string, len, pos);

    delete[] string;

    return 0;
}