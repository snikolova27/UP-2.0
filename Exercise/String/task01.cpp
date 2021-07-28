#include <iostream>

const int MAX_ARRAY_SIZE = 20;
const int MAX_RESULT_SIZE = 40;
const int MAX_CHAR = 26;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        ++len;
    }

    return len;
}

void swap(char &a, char &b)
{
    if (a == b)
    {
        return;
    }
    else
    {
        char temp = a;
        a = b;
        b = temp;
    }
}

int minFrom(const char str[], int size, int pos)
{
    int min = str[pos];
    int minIdx = pos;

    for (int i = pos + 1; i < size; i++)
    {
        if (str[i] < min)
        {
            min = str[i];
            minIdx = i;
        }
    }
    return minIdx;
}

void selectionSort(char str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = minFrom(str, size, i);
        swap(str[i], str[min]);
    }
}

void concatenate(const char str1[], int size1, const char str2[], int size2, char result[], int sizeRes)
{
    for (int i = 0; i < size1; i++)
    {
        result[i] = str1[i];
    }
    for (int i = size1, j = 0; i < sizeRes, j < size2; i++, j++)
    {
        result[i] = str2[j];
    }
    result[sizeRes] = '\0';
}

void sortAlphabetical(char str[])
{
    int charCount[MAX_CHAR] = {};
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        charCount[str[i] - 'a']++;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        for (int k = 0; k < charCount[i]; k++)
        {
            std::cout << char('a' + i);
        }
    }
}
int main()
{
    char string1[MAX_ARRAY_SIZE] = {};
    char string2[MAX_ARRAY_SIZE] = {};

    std::cout << "Enter first string: ";
    std::cin >> string1;
    std::cout << "Enter second string: ";
    std::cin >> string2;

    int str1Len = strlen(string1);
    selectionSort(string1, str1Len);
    std::cout << string1 << std::endl;

    int str2Len = strlen(string2);
    selectionSort(string2, str2Len);
    std::cout << string2 << std::endl;

    int lenRes = str1Len + str2Len + 1;
    char concatenated[MAX_RESULT_SIZE] = {};

    concatenate(string1, str1Len, string2, str2Len, concatenated, lenRes);
    std::cout << concatenated << std::endl;
    sortAlphabetical(concatenated);

    //selectionSort(concatenated, lenRes);
    // std::cout << concatenated << std::endl; //sнещо се чупи на тази сортировка
    return 0;
}