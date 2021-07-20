#include <iostream>

int main()
{
    double a, b;

    std::cout << "Enter a and b for the equation ax = b \n";
    std::cin >> a >> b;
    if (a == 0 && b != 0)
    {
        std::cout << "No solution! \n";
    }
    else if (a == 0 && b == 0)
    {
        std::cout << "Each x is a solution \n";
    }
    else if (b == 0 && a != 0)
    {
        std::cout << "x = 0 \n";
    }
    else
    {
        std::cout << "x = " << b / a;
    }
    return 0;
}