#include <iostream>

int cntDividers(int num)
{
    int cnt = 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cnt++;
        }
    }

    return cnt;
}

bool isPrime(int num)
{
    return cntDividers(num) == 0 && (num != 0 && num != 1);
}

void printNumsWithPrimeCountOfDividersInInterval(int a, int b)
{
    for (int i = a + 1; i < b; i++)
    {
        int cntDvdrs = cntDividers(i);
        if (isPrime(cntDvdrs))
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
int main()
{
    int a, b;
    std::cout << "Enter two numbers for the interval (a,b) \n";
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    if (a > b)
    {
        std::cout << "a should be lesser than b! Try again. \n";
        std::cout << "Enter a: ";
        std::cin >> a;
        std::cout << "Enter b: ";
        std::cin >> b;
    }
    printNumsWithPrimeCountOfDividersInInterval(a, b);
    return 0;
}