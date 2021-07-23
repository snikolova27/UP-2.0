#include <iostream>

int main()
{
    int num, pos;
    std::cout << "Enter number and position: ";
    std::cin >> num >> pos;

    int shiftedNum = 1 << pos;  
    shiftedNum = ~(shiftedNum);

    std::cout << "Number with a null in the given position: " << (num & shiftedNum) << std::endl;


// num = 15, pos = 0
// 1111 ---> 1110
//shiftedNum = 0001 << 0 ---> 0001
//shiftedNum = ~0001 ---> 1110
//num & shiftedNum = 1111 & 1110 ---> 1110

    return 0;
}