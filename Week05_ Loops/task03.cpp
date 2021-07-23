#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    for (int i = 1; i < num; i++)
    {
        if (i * i < num)
        {
            std::cout << i * i << " ";
        }
    }
    std::cout << std::endl;

    int cnt = 1;
    while (cnt < num)
    {
        if (cnt * cnt < num)
        {
            std::cout << cnt * cnt << " ";
        }
        cnt++;
    }
    std::cout << std::endl;

    return 0;
}