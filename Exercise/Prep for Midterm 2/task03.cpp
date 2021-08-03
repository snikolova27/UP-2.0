#include <iostream>

bool isTheSameWay(int longer, int shorter)
{
    if (shorter == 0)
    {
        return true;
    }
    if (longer == 0)
    {
        return false;
    }
    if (longer % 10 == shorter % 10)
    {
        shorter /= 10;
    }
    return isTheSameWay(longer / 10, shorter);
}
int main()
{
    int num1, num2;
    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;

      if (num1 > num2)
    {
        std::cout << std::boolalpha << isTheSameWay(num1, num2) << std::endl;
    }
    else 
    {
        std::cout << std::boolalpha << isTheSameWay(num2, num1) << std::endl;
    }


    return 0;
}