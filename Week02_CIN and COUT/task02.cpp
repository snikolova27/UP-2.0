#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    if (num > 10000)
    {
        std::cout << "Number should be lesser than 10 000" << std::endl;
    }
    else
    {
        int turns = num / 12;
        int hour = (12 + num) / 12;
        std::cout << "Turns: " << turns << std::endl;
        std::cout << hour << " o'clock" << std::endl;
    }
    return 0;
}