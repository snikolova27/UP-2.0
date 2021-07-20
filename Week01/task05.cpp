#include <iostream>

int main()
{
    int num1, num2;

    std::cin >> num1 >> num2;

    int num = num2;
    num2 = num1;
    num1 = num;
    
    std::cout << num1 << " " << num2;

    return 0;
}