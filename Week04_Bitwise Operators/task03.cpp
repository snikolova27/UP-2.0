#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    int result = (num << 1) + num + (num >> 1);
    // num >> 1 = num * 0,5 (2^-1)
    // num << 1 = num * 2  

    std::cout << "Number miltiplied by 3.5: " << result << std::endl;

    return 0;
}