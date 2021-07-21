#include <iostream>
const int MIN-DAY = 2;
const int MAX-DAY = 22;
const int DAYS-LEFT = 9;

int main()
{
    int n;
    std::cin >> n;

    if (n > MIN-DAY && n <MAX-DAY)
    {
        if (n <= DAYS-LEFT)
        {
            std::cout << "Students should return to school on " << MAX-DAY + n << " January 2006 \n";
        }
        else
        {
            std::cout << "Students should return to school on " << n - DAYS-LEFT << " February 2006 \n";
        }
    }
    return 0;
}
