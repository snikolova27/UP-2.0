#include <iostream>

const int MAX_STR_LEN = 100;

typedef void (*funcPtr)(char *, int);

void toLowerCase(char *string, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 'a' - 'A';
        }
    }
}

void toUpperCase(char *string, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] += 'A' - 'a';
        }
    }
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

void transform(char *str, int size, funcPtr transformation)
{
    transformation(str, size);
}

int main()
{
    char buffer[MAX_STR_LEN] = {};
    std::cin.getline(buffer, MAX_STR_LEN);

    int len = strlen(buffer) + 1;

    char *string = new (std::nothrow) char[len];
    if (!string)
    {
        std::cout << "Memory problem" << std::endl;
        return -1;
    }
    strcopy(buffer, string);

    transform(string, len, toLowerCase);
    std::cout << string << std::endl;

    transform(string, len, toUpperCase);
    std::cout << string << std::endl;
    
    return 0;
}