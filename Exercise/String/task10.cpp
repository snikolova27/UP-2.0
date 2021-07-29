#include <iostream>

const int MAX_STRING_LEN = 100;

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

void sameCharaters(const char *str)
{
    int pos1 = 0;
    int pos2 = 0;
    int i = 0;

    while (str[i])
    {
        int j = i + 1;
        while (str[j])
        {
            if (str[i] == str[j])
            {
                pos1 = i;
                pos2 = j;
            }
            j++;
        }
        i++;
    }

    if (pos1 != pos2)
    {
        std::cout << str[pos1] << " in positions " << pos1 << " and " << pos2 << std::endl;
    }
    else
    {
        std::cout << "No letter occurs twice" << std::endl;
    }
}

int main()
{
    char buffer[MAX_STRING_LEN] = {};
    std::cout << "enter string: ";
    std::cin.getline(buffer, MAX_STRING_LEN);

    int len = strlen(buffer) + 1;
    std::cout << len << std::endl;

    char *string = new (std::nothrow) char[len];
    if (!string)
    {
        std::cout << "Memory allocation problem :( " << std::endl;
        return -1;
    }
    else
    {
        strcopy(buffer, string);
        sameCharaters(string);

        delete[] string;
    }
    return 0;
}