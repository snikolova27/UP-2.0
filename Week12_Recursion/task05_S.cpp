#include <iostream>

int productInInterval(int n, int k, int product, int current)
{
    if (current == n || current > n)
    {
        return product;
    }
    return productInInterval(n, k, product * current, current + k);
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

    std::cout << "Product of nums in interval 1 to n with step k is: " << productInInterval(n, k, 1, 1) << std::endl;
    
    return 0;
}