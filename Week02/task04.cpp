#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    if (num < 100 || num >= 1000)
    {
        std::cout << "Number should be between 100 and 999 \n";
    }
    else
    {
        int sum = 0;
        int firstDigit = num / 100;
        int scndDigit = (num / 10) % 10;
        int thirdDigit = num % 10;
        sum+= firstDigit + scndDigit + thirdDigit;
        std::cout << "Sum of digits: " << sum << std::endl;
    }
    return 0;
}