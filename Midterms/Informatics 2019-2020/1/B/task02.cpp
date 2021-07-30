#include <iostream>

bool areDigitsDifferent(int num)
{
    int digit = num % 10;
    num /= 10;

    while (num)
    {
        if (digit == num % 10)
        {
            return false;
        }
        num /= 10;
    }
    return true;
}

void printCntNumsWithDifferentDigits(int a, int b)
{
    int cnt = 0;
    for (int i = a; i < b; i++)
    {
        if (areDigitsDifferent(i))
        {
            cnt++;
        }
    }
    std::cout << "Count of numbers in interval with different digits: " << cnt << std::endl;
}
int main()
{
    int a, b;
    std::cout << "Enter two numbers for the interval [a,b) \n";
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    printCntNumsWithDifferentDigits(a, b);
    return 0;
}