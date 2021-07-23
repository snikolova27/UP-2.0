#include <iostream>

void printNumbers(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        std::cout << i << " ";
    }
}

int main()
{

    int num;
    std::cout << "Enter count of numbers to be printed: ";
    std::cin >> num;
    printNumbers(num);

    return 0;
}