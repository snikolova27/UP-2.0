#include <iostream>

bool areOnSameLine(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double firstAnswer = y1 / x1;
    double secondAnswer = y2 / x2;
    double thirdAnswer = y3 / x3;

    if (firstAnswer == secondAnswer && firstAnswer == thirdAnswer)
    {
        return true;
    }

    return false;
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    std::cout << "Enter coordinates \n";
    std::cout << "First point: ";
    std::cin >> x1 >> y1;
    std::cout << "Second point: ";
    std::cin >> x2 >> y2;
    std::cout << "Third point: ";
    std::cin >> x3 >> y3;

    if (x1 == 0 || x2 == 0 || x3 == 0)
    {
        std::cout << "Invalid input" << std::endl;
    }

    else if (areOnSameLine(x1, y1, x2, y2, x3, y3))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}