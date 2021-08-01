#include <iostream>

int sumInInterval(int n, int k, int sum, int current)
{
    if (current == n || current > n)
    {
        return sum;
    }
    return sumInInterval(n, k, sum + current, current + k);
}

int main()
{
    int n, k;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter k: ";
    std::cin >> k;

    if (!(k >= 1 && k <= n))
    {
        return -1;
    }

    std::cout << "Sum of nums in interval 1 to n with step k is: " << sumInInterval(n, k, 0, 1) << std::endl;
    return 0;
}