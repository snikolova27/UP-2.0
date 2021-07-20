#include <iostream>

int main()
{
    int num, shiftedNum;
    std::cin >> num;

    shiftedNum = num >> 1;

    if((num & shiftedNum) == 0)
    {
        std::cout << "True \n";
    }
    else
    {
        std::cout << "False \n";
    }

    return 0;
}