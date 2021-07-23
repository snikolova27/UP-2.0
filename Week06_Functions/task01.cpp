#include <iostream>

int main()
{
    int cntOfNums;
    std::cout << "Enter how many numbers you're going ot enter: ";
    std::cin >> cntOfNums;

    int maxNegativeNum = 0;

    int num;
    std::cin >> num;
    cntOfNums--;

    while (cntOfNums > 0)
    {
        std::cin >> num;
        if ((maxNegativeNum < num || maxNegativeNum == 0) && num < 0)
        {
            maxNegativeNum = num;
        }

        cntOfNums--;
    }

    std::cout << "Max negative number is: " << maxNegativeNum << std::endl;

    return 0;
}