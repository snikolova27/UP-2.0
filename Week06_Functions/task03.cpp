#include <iostream>

bool isPalindrome(int num)
{
    int reversedNum = 0;

    int temp = num;

    while (temp)
    {
        reversedNum = ((10 * reversedNum) + (temp % 10));
        temp /= 10;
    }

    return num == reversedNum;
}

int main()
{
    int k, l; 
    std::cout << "Enter two numbers k and l for the interval [k,l]: ";
    std::cin >> k >> l;

    if( k < 0 || l > 1000)
    {
        std::cout <<"k and l should be in the interval [0,1000]" << std::endl;
        return -1;
    }

    std::cout << "Palindromes in given interval: ";
    
    for (int i = k; i <= l; i++)
    {
        if (isPalindrome(i))
        {
            std::cout << i << " ";
        }
    }

    return 0;
}