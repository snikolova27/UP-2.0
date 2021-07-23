#include <iostream>

int main()
{
    int sum = 0;
    int num;

    std::cin >> num;
    while (num != 0)
    {
        sum += num;
        std::cin >> num;
    }
    std::cout << "Sum of entered nums is: " << sum << std::endl;
    return 0;
}