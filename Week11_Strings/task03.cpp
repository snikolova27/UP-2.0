#include <iostream>

const int MAX_ARRAY_SIZE = 20;
const int NUMBER_OF_DIGITS = 10;

int strlen(const char string[])
{
    int len = 0;
    while (string[len])
    {
        len++;
    }

    return len;
}

void countDigits(const char num[], int len, int counter[])
{
    for (int i = 0; i < len; i++)
    {
        ++counter[num[i] - '0'];
    }
}

int main()
{
    char firstNum[MAX_ARRAY_SIZE] = {};
    char scndNum[MAX_ARRAY_SIZE] = {};
    char result[MAX_ARRAY_SIZE] = {};

    std::cout << "Enter first sequence of numbers: ";
    std::cin >> firstNum;
    std::cout << "Enter second sequence of numbers: ";
    std::cin >> scndNum;

    int lenFirst = strlen(firstNum);
    int lenScnd = strlen(scndNum);

    int counterOfDigits1[NUMBER_OF_DIGITS] = {};
    int counterOfDigits2[NUMBER_OF_DIGITS] = {};
    int counter[NUMBER_OF_DIGITS] = {};
    int countElements = 0;

    countDigits(firstNum, lenFirst, counterOfDigits1);
    countDigits(scndNum, lenScnd, counterOfDigits2);

    std::cout << counterOfDigits1 << std::endl;

    for (int i = 0; i < NUMBER_OF_DIGITS; ++i)
    {
        counter[i] = (counterOfDigits1[i] < counterOfDigits2[i]) ? counterOfDigits1[i] : counterOfDigits2[i];
    }

    for (int i = NUMBER_OF_DIGITS - 1; i >= 0; --i)
    {
        for (int j = 0; j < counter[i]; ++j)
        {
            result[countElements] = '0' + i;
            ++countElements;
        }
    }
    std::cout << result;

    return 0;
}