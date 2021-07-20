#include <iostream>

int main()
{
    int num1, num2;
    std::cin >> num1 >> num2;

    if ((num1 ^ num2) > 0)
    {
        std::cout << "True \n";
    }
    else
    {
        std::cout << "False \n";
    }
    return 0;
}