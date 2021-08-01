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

bool isPrimeRec(int num)
{
    return isPrimeHelper(num, 2);
}
int main()
{
    int num;
    std::cout << "Num: ";
    std::cin >> num;

    std::cout << "Is number prime: " << std::boolalpha << isPrimeRec(num) << std::endl;
    return 0;
}