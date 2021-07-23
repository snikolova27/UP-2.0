#include <iostream>

int main()
{
    double x, y;
    std::cout << "Enter (x,y) coordinates: ";
    std::cin >> x >> y;

    if (x == 0 && y == 0)
    {
        std::cout << "Point is in the centre of the coordinate system \n";
    }
    else if (x == 0 && y != 0)
    {
        std::cout << "Point is on the Y axis \n";
    }
    else if (y == 0 && x != 0)
    {
        std::cout << "Point is on the X axis \n";
    }
    else if (x > 0 && y > 0)
    {
        std::cout << "Point is in first quandrant \n";
    }
    else if (x < 0 && y > 0)
    {
        std::cout << "Point is in second quandrant \n";
    }
    else if (x < 0 && y < 0)
    {
        std::cout << "Point is in third quandrant \n";
    }
    else if (x > 0 && y < 0)
    {
        std::cout << "Point is in fourth quandrant \n";
    }
    return 0;
}