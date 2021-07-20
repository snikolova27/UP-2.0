#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    if(num < 1000 || num > 9999)
    {
        std::cout << "Number should be between 1000 and 9999 \n";
    }
    else
    {
        int firstDigit = num / 1000;
        int scndDigit = (num / 100) % 10;
        int thirdDigit = (num/10) % 10;
        int fourthDigit = num % 10;

        if(firstDigit == fourthDigit && scndDigit == thirdDigit)
        {
            std::cout << "Number is symetrical \n";
        }
        else
        {
            std::cout << "Number is not symetrical \n";
        }
    }
    return 0;
}