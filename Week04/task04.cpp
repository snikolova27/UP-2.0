#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    if ((num & (num - 1)) == 0)
    {
        std::cout << "Number is a power of 2 \n";
    }
    else
    {
        std::cout << "Number is  not a power of 2  \n";
    }
    
    return 0;
}