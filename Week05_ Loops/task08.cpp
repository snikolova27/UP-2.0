#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;
    int nums, sum = 0, cnt = 0;

    std::cin >> nums;
    while (sum <= num)
    {
        sum += nums;
        cnt++;
        std::cin >> nums;
    }
    std::cout << cnt << std::endl;
    
    return 0;
}