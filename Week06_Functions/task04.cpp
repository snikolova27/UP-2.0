#include <iostream>

bool hasAdjEqual(int num)
{
    int temp = num;
    while (temp > 9)
    {
        int firstDigit = temp % 10;
        int scndDigit = (temp / 10) % 10;

        if (firstDigit == scndDigit)
        {
            return true;
        }

        temp /= 10;
    }
    return false;
}

int main()
{
    int k, l;
    std::cout << "Enter two numbers k and l for the interval [k,l]: ";
    std::cin >> k >> l;

    if (k < 0 || l > 100000)
    {
        std::cout << "k and l should be in the interval [0,1000]" << std::endl;
        return -1;
    }
    for (int i = k; i <= l; i++)
    {
        if (hasAdjEqual(i))
        {
            std::cout << i << " ";
        }
    }

    return 0;
}