#include <iostream>

int main()
{
    int num, pos1, pos2;
    std::cout << "Enter number and two positions: ";
    std::cin >> num >> pos1 >> pos2;

    int numPos1 = 1 << pos1;
    int numPos2 = 1 << pos2;

    int shiftedPositions = (numPos1 | numPos2);

    std::cout << "Number with switched bits in the given postions: " << (num ^ shiftedPositions) << std::endl;
    // num =  28 = 11100
    // pos1 = 0, pos2 = 3
    //       00001 ---> 00001
    //       00001 ---> 01000
    // 00001 | 01000 -> 01001
    // 11100 ^ 01001 -> 10101 = 21

    return 0;
}