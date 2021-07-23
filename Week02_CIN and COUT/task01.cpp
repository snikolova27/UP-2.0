#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    if (number < 100 || number >= 1000)
    {
        std::cout << "Number must be between 100 and 999" << std::endl;
    }
    else
    {
        int first_digit = number % 10;
        int scnd_digit = (number / 10) % 10;
        int third_digit = number / 100;

        int rev_num = first_digit * 100 + scnd_digit * 10 + third_digit;
        std::cout << rev_num;
    }

    return 0;
}