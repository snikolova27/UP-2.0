#include <iostream>

int main()
{
    int m, n;
    std::cout << "Enter two numbers - n and m: ";
    std::cin >> n >> m;

    if (m > n)
    {
        while (n <= m)
        {
            if (n % 3 == 0)
            {
                std::cout << n << " ";
            }
            n++;
        }
    }
    return 0;
}