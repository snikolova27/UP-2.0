#include <iostream>

int getCntDigits(int number, int counter)
{
    if (number == 0)
    {
        return counter;
    }
    return getCntDigits(number / 10, counter + 1);
}

bool checkResult(int longer, int shorter)
{
    if (shorter == 0)
    {
        return true;
    }
    if (longer == 0)
    {
        return false;
    }
    if (longer % 10 == shorter % 10)
    {
        shorter /= 10;
    }
    return checkResult(longer / 10, shorter);
}

int main()
{
    unsigned int num1, num2;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    bool isTrue;
    int size1 = getCntDigits(num1, 0);
    int size2 = getCntDigits(num2, 0);
    if (size1 > size2)
    {
        isTrue = checkResult(num1, num2);
    }
    else
    {
        isTrue = checkResult(num2, num1);
    }

    if (isTrue)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}