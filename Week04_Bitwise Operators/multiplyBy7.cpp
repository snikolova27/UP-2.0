#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number to be multiplied by 7: ";
    std::cin >> num;

    int result = (num << 3) - num ;
    std::cout << "Result: " << result << std::endl;

    return 0;
}