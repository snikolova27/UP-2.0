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

void printStrings(const char *str1, int len1, const char *str2, int len2)
{
    int indexFirst = -1;
    int indexScnd = -1;
    bool found = false;

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                indexFirst = i;
                indexScnd = j;
                found = true;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }

    // std::cout << indexFirst << indexScnd << std::endl;
    if (indexFirst >= 0 && indexScnd >= 0)
    {
        for (int i = 0; i < indexFirst; i++)
        {
            for (int j = 0; j < indexScnd; j++)
            {
                std::cout << " ";
            }
            std::cout << str1[i] << " ";

            for (int k = indexScnd + 1; k < len2; k++)
            {
                std::cout << " ";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < len2; i++)
        {
            std::cout << str2[i];
        }
        std::cout << std::endl;

        for (int i = indexFirst + 1; i < len1; i++)
        {
            for (int j = 0; j < indexScnd; j++)
            {
                std::cout << " ";
            }
            std::cout << str1[i] << " ";
            for (int k = indexScnd + 1; k < len2; k++)
            {
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No shared characters!" << std::endl;
    }
}
int main()
{
    char buffer[MAX_STRING_LEN] = {};
    std::cout << "Enter first string: ";
    std::cin >> buffer;

    int len1 = strlen(buffer) + 1;
    char *string1 = new (std::nothrow) char[len1];
    if (!string1)
    {
        std::cout << "Problem allocating memory for first string :(" << std::endl;
        return -1;
    }

    strcopy(buffer, string1);

    std::cout << "Enter second string: ";
    std::cin >> buffer;

    int len2 = strlen(buffer) + 1;
    char *string2 = new (std::nothrow) char[len2];
    if (!string2)
    {
        std::cout << "Problem allocating memory for second string :(" << std::endl;
        return -2;
    }

    strcopy(buffer, string2);
    printStrings(string1, len1, string2, len2);

    delete[] string1;
    delete[] string2;

    return 0;
}