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

int hammingDistance(const char *firstStr, const char *scndStr)
{
    int res = 0;
    int len1 = strlen(firstStr);
    int len2 = strlen(scndStr);
    int len = 0;
    int diff = 0;

    if (len1 == len2)
    {
        len = len1;
    }
    else
    {
        len = len1 < len2 ? len1 : len2;
        diff = abs(len1 - len2);
    }

    for (int i = 0; i < len; i++)
    {
        if (firstStr[i] != scndStr[i])
        {
            res++;
        }
    }
    res += diff;
    return res;
}

int main()
{
    char buffer[MAX_STRING_LEN] = {};

    std::cout << "enter first string: ";
    std::cin >> buffer;

    int str1len = strlen(buffer) + 1;
    char *first = new (std::nothrow) char[str1len];
    if (!first)
    {
        std::cout << "Couldn't allocate memory for string 1 " << std::endl;
        return -1;
    }
    else
    {
        strcopy(buffer, first);

        std::cout << "enter second string: ";
        std::cin >> buffer;

        int str2len = strlen(buffer);
        char *scnd = new (std::nothrow) char[str2len];
        if (!scnd)
        {
            std::cout << "Couldn't allocate memory for string 2 " << std::endl;
            return -1;
        }

        else
        {
            strcopy(buffer, scnd);
            std::cout << "Hamming distance between strings: " << hammingDistance(first, scnd) << std::endl;

            delete[] first;
            delete[] scnd;
        }
    }

    return 0;
}