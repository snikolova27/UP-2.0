#include <iostream>

int main()
{
    int cnt = 0;
    int num;

    std::cin >> num;
    while (num != 0)
    {
        cnt++;
        std::cin >> num;
    }
    std::cout << "Count of entered nums: " << cnt << std::endl;
    return 0;
}