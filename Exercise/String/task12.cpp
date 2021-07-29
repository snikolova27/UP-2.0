#include <iostream>

const int MAX_STRING_LEN = 100;
const int ALPHABET = 26;

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

void clearMatrix(char **matrix, int rows)
{

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isAnagram(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        return false;
    }

    char alphabet[ALPHABET] = {};
    for (int i = 0; i < ALPHABET; i++)
    {
        alphabet[i] = 'a' + i;
    }

    int countOfLetters1[ALPHABET] = {};
    int countOfLetters2[ALPHABET] = {};

    for (int i = 0; i < len1; i++)
    {
        countOfLetters1[str1[i] - 'a']++;
        countOfLetters2[str2[i] - 'a']++;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        if (countOfLetters1[i] != countOfLetters2[i])
        {
            return false;
        }
    }

    // for (int i = 0; i < len2; i++)
    // {

    //  for (int i = 0; i < len1; i++)
    // {
    //     bool occured = false;
    //     for (int j = 0; j < len1; j++)
    //     {
    //         if (str1[i] == str2[j])
    //         {
    //             occured = true;
    //             break;
    //         }
    //     }
    //     if (!occured)
    //     {
    //         return false;
    //     }
    // }

    return true;
}

// abca    abbc
void findAnagrams(char **strings, int cntOfStrings)
{
    for (int i = 0; i < cntOfStrings; i++)
    {
        bool first = true;
        if (strings[i][0] != '#')
        {
            for (int j = i + 1; j < cntOfStrings; j++)
            {
                if (isAnagram(strings[i], strings[j]))
                {
                    if (first)
                    {
                        std::cout << i + 1 << " ";
                    }
                    std::cout << j + 1 << " ";
                    first = false;
                    strings[j][0] = '#';
                }
            }
            if (!first)
            {
                std::cout << std::endl;
            }
        }
    }
}

int main()
{
    int cntStrings;
    std::cout << "enter how many strings you'll enter: ";
    std::cin >> cntStrings;
    std::cin.ignore();

    if (!cntStrings)
    {
        std::cout << "Strings should be more than 0!!!" << std::endl;
        return -1;
    }

    char buffer[MAX_STRING_LEN] = {};

    char **strings = new (std::nothrow) char *[cntStrings];
    if (!strings)
    {
        std::cout << "Memory allocation problem!" << std::endl;
        return -1;
    }

    for (int i = 0; i < cntStrings; i++)
    {
        std::cout << "Enter string: ";
        std::cin.getline(buffer, MAX_STRING_LEN);

        int len = strlen(buffer) + 1;
        strings[i] = new (std::nothrow) char[len];

        if (!strings[i])
        {
            std::cout << "Memory allocation problem!" << std::endl;
            return -1;
        }
        strcopy(buffer, strings[i]);
    }
    findAnagrams(strings, cntStrings);
    clearMatrix(strings, cntStrings);
    return 0;
}