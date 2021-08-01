#include <iostream>

int sumDigits(int num, int sum)
{
    if (num == 0)
    {
        return sum;
    }
    return sumDigits(num / 10, sum + num % 10);
}
int main()
{
    int num;
    std::cout << "Enter num: ";
    std::cin >> num;

    std::cout << "Sum of digits: " << sumDigits(num, 0) << std::endl;
    return 0;
}