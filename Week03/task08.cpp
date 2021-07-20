#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    if (n > 2 && n < 22)
    {
        if (n <= 9)
        {
            std::cout << "Students should return to school on " << 22 + n << " January 2006 \n";
        }
        else
        {
            std::cout << "Students should return to school on " << n - 9 << " February 2006 \n";
        }
    }
    return 0;
}