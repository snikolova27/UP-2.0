#include <iostream>

const int MAX_WORD_LEN = 100;

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool isLowerCase(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}
bool containsOnlyLetters(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!isLetter(str[i]))
        {
            return false;
        }
    }
    return true;
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
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

bool inputDict(char **dict, int size)
{
    int cnt = 0;
    while (cnt < size)
    {
        char buffer[MAX_WORD_LEN];

        std::cout << "Enter word #" << cnt + 1 << " : ";
        std::cin >> buffer;

        int len = strlen(buffer) + 1;
        bool valid = true;

        if (!containsOnlyLetters(buffer, len - 1))
        {
            valid = false;
            std::cout << "Words can contain only letters. Try again." << std::endl;
        }

        if (valid)
        {
            dict[cnt] = new (std::nothrow) char[len];
            if (!dict[cnt])
            {
                std::cout << "problem allocating memory for word" << std::endl;
                return false;
            }
            strcopy(buffer, dict[cnt]);
            cnt++;
        }
    }
    return true;
}
void printDict(char **dict, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Word # " << i + 1 << "  " << dict[i] << std::endl;
    }
}

void clearDynamic(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int strcomp(const char *str1, const char *str2)
{
    while (*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

bool areEqual(const char *str1, const char *str2)
{
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    if (len1 != len2)
    {
        return false;
    }
    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

int minFrom(char **dict, int from, int to)
{
    int min = from;
    for (int i = from + 1; i < to; i++)
    {
        if (strcomp(dict[i], dict[min]) < 0)
        {
            min = i;
        }
    }

    return min;
}

void selectionSort(char **dict, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = minFrom(dict, i, size);
        if (min != i)
        {
            char buffer[MAX_WORD_LEN];
            strcopy(dict[i], buffer);
            strcopy(dict[min], dict[i]);
            strcopy(buffer, dict[min]);
        }
    }
}

char **allocateMatrix(int size)
{
    char **result = new (std::nothrow) char *[size];
    if (!result)
    {
        return nullptr;
    }
    for (int i = 0; i < size; i++)
    {
        result[i] = new (std::nothrow) char[size];
        if (!result[i])
        {
            return nullptr;
        }
    }
    return result;
}

void inputMatrix(char **matrix, int size)
{
    std::cout << "Input matrix of characters" << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char c;
            do
            {
                std::cout << "Character: ";
                std::cin >> c;
                if (!isLowerCase(c))
                {
                    std::cout << "Character should be in lower case. Try again." << std::endl;
                }

            } while (!isLowerCase(c));
            matrix[i][j] = c;
        }
    }
}

bool isInDict(char **dict, int size, char *word)
{
    for (int i = 0; i < size; i++)
    {
        if (areEqual(dict[i], word))
        {
            return true;
        }
    }

    return false;
}
void findLongestWord(char **dict, int sizeDict, char **matrix, int sizeMatrix, int currentPosX, int currentPosY, int &longestWord, int &currentLen, char currentWord[], const int *dirX, const int *dirY, int *used)
{
    std::cout << currentPosX << " X  \n";
    std::cout << currentPosY << " Y  \n";

    if (currentPosX >= sizeMatrix || currentPosY >= sizeMatrix || currentPosX < 0 || currentPosY < 0) //out of bounds
    {
        std::cout << "LINE 208" << std::endl;
        return;
    }
    if (currentLen < longestWord)
    {
        longestWord = currentLen;
    }
    bool usedLetter = false;
    for (int k = 0; k < currentLen; k++)
    {
        for (int i = 0; i < sizeMatrix; i++)
        {
            for (int j = 0; j < sizeMatrix; j++)
            {
                if (i + j == used[k])
                {
                    usedLetter = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        findLongestWord(dict, sizeDict, matrix, sizeMatrix, currentPosX + dirX[i], currentPosY + dirY[i], longestWord, currentLen, currentWord, dirX, dirY);
    }
}
int main()
{
    int size;
    do
    {
        std::cout << "Enter size of dictionary: ";
        std::cin >> size;
        if (!std::cin)
        {
            std::cout << "Size can only be a number \n";
            std::cin.clear();
            std::cin.ignore(100000000000, '\n');
        }
        else if (size <= 0)
        {
            std::cout << "Size should be > 0 \n";
        }
    } while (!std::cin || size <= 0);

    char **dictionary = new (std::nothrow) char *[size];
    if (!dictionary)
    {
        std::cout << "Problem allocating memory for dictionary" << std::endl;
        return -1;
    }
    bool validDict = inputDict(dictionary, size);
    if (!validDict)
    {
        std::cout << "Dictonary is not valid" << std::endl;
        clearDynamic(dictionary, size);
        return -2;
    }
    selectionSort(dictionary, size);
    printDict(dictionary, size);

    int k;
    do
    {
        std::cout << "Enter number k: ";
        std::cin >> k;

        if (!std::cin)
        {
            std::cout << "Invalid input";
            std::cin.clear();
            std::cin.ignore(100000000000, '\n');
        }
        else if (k < 2 || k > 5)
        {
            std::cout << "Number k should be in the interval [2,5]" << std::endl;
        }
    } while (k < 2 || k > 5 || !std::cin);

    char **matrix = allocateMatrix(k);
    if (!matrix)
    {
        std::cout << "problem allocating memory for matrix" << std::endl;
        return -1;
    }
    inputMatrix(matrix, k);

    const int directionsX[] = {1, -1, 0, 0, 1, -1, -1, 1};
    const int directionY[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int longestWord = 0;
    int currentLen = 0;
    char currentWord[MAX_WORD_LEN] = {};
    findLongestWord(dictionary, size, matrix, k, 0, 0, longestWord, currentLen, currentWord, directionsX, directionY);
    std::cout << longestWord << " " << currentWord << std::endl;
    clearDynamic(dictionary, size);
    clearDynamic(matrix, k);
    return 0;
}