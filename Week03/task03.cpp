#include <iostream>

int main()
{
    int num;

    std::cout << "Enter number between 100 and 999: ";
    std::cin >> num;

    if (num < 100 || num > 999)
    {
        std::cout << "Number not in interval, sorry. \n";
    }
    else
    {
        int firstDigit = num / 100;
        int scndDigit = (num/10) % 10;
        int thirdDigit = num % 10;

        if(firstDigit == scndDigit || firstDigit == thirdDigit || scndDigit == thirdDigit)
        {
            std::cout << "True \n";
        }
        else
        {
            std::cout << "False \n";
        }
    }

    return 0;
}
