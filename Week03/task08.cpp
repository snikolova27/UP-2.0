#include <iostream>
const int MIN_DAY = 2;
const int MAX_DAY = 22;
const int DAYS_LEFT = 9;

int main()
{
    int n;
    std::cin >> n;

    if (n > MIN_DAY && n <MAX_DAY)
    {
        if (n <= DAYS_LEFT)
        {
            std::cout << "Students should return to school on " << MAX_DAY + n << " January 2006 \n";
        }
        else
        {
            std::cout << "Students should return to school on " << n - DAYS_LEFT << " February 2006 \n";
        }
    }
    return 0;
}
