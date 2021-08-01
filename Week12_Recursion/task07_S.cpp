#include <iostream>
#include <cmath>

bool isPrimeHelper(int num, int i)
{
    if (i > sqrt(num))
    {
        return true;
    }

    if (num < 2 || num % i == 0)
    {
        return false;
    }

    return isPrimeHelper(num, i + 1);
}

bool isPrime(int n, int i = 2)
{
    if (n <= 2)
    {
        return (n == 2) ? true : false;
    }
    if (n % i == 0)
    {
        return false;
    }
    if (i * i > n)
    {
        return true;
    }
    return isPrime(n, i + 1);
}

bool isPrimeRec(int num)
{
    return isPrimeHelper(num, 2);
}

int sumPrimesInInteval(int a, int b)
{
    if (a > b)
    {
        return 0;
    }

    if (isPrimeRec(a))
    {
        return a + sumPrimesInInteval(a + 1, b);
    }
    return sumPrimesInInteval(a + 1, b);
}

int main()
{
    int a, b;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Sum of primes in interval (a,b): " << sumPrimesInInteval(a, b) << std::endl;

    return 0;
}