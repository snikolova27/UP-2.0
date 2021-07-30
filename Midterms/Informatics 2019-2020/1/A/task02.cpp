#include <iostream>

int sumOfDigits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int productOfDigits(int num)
{
    int product = 1;
    while (num)
    {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

void printNums(int a, int b)
{
    int cnt = 0;
    for (int i = a; i < b; i++)
    {
        if (sumOfDigits(i) == productOfDigits(i))
        {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
int main()
{
    int a, b;
    std::cout << "Enter two numbers for the interval [a,b] \n";
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    printNums(a, b);
    return 0;
}