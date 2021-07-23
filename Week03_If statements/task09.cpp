#include <iostream>

int main()
{
    int sideA, sideB, sideC;
    std::cin >> sideA >> sideB >> sideC;

    if (sideA == 0 || sideB == 0 || sideC == 0)
    {
        std::cout << "A side cannot be equal to zero \n";
    }
    else if (sideA == sideB && sideB == sideC)
    {
        std::cout << "Equilateral triangle \n";
    }
    else if ((sideA == sideB && sideC != sideA) || (sideA == sideC && sideA != sideB) || (sideB == sideC && sideB != sideA))
    {
        std::cout << "Isoceles triangle \n";
    }
    else
    {
        std::cout << "Scalene triangle \n";
    }
    return 0;
}