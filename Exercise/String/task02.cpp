#include <iostream>
#include <cmath>

const int MAX_ARRAY_SIZE = 100;

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

int main()
{
    char buffer[MAX_ARRAY_SIZE] = {}, num1[MAX_ARRAY_SIZE] = {}, num2[MAX_ARRAY_SIZE] = {};
    std::cout << "Enter first number: ";
    std::cin >> buffer;

    int lenNum1 = strlen(buffer);
    strcopy(buffer, num1);

    int firstNum = 0;

    for (int i = 0; i < lenNum1; i++)
    {
        firstNum += pow(10.0, lenNum1 - i - 1) * (num1[i] - '0');
    }

    std::cout << "Enter second number: ";
    std::cin >> buffer;

    int lenNum2 = strlen(buffer);
    strcopy(buffer, num2);

    int secondNum = 0;

    for (int i = 0; i < lenNum2; i++)
    {
        secondNum += pow(10.0, lenNum2 - i - 1) * (num2[i] - '0');
    }

    std::cout << "first number * second number = " << firstNum * secondNum << std::endl;
    return 0;
}