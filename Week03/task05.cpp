#include <iostream>

int main()
{

    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;

    int max = 0, min = 0;

    if (num1 == num2 && num2 == num3)
    {
        std::cout << "All numbers are equal \n";
        return 0;
    }
    else if (num1 > num2 && num1 > num3)
    {
        max = num1;
        min = num2 > num3 ? num3 : num2;
    }
    else if (num2 > num1 && num2 > num3)
    {
        max = num2;
        min = num1 > num3 ? num3 : num1;
    }
    else if (num3 > num1 && num3 > num2)
    {
        max = num3;
        min = num1 > num2 ? num2 : num1;
    }
    else if (num1 == num2 && num1 > num3)
    {
        min = num3;
        max = num1;
    }
    else if (num1 == num2 && num1 < num3)
    {
        min = num1;
        max = num3;
    }
    else if (num1 == num3 && num2 < num1)
    {
        min = num2;
        max = num1;
    }
    else if (num1 == num3 && num2 > num1)
    {
        min = num1;
        max = num2;
    }
    else if (num2 == num3 && num1 > num3)
    {
        max = num1;
        min = num2;
    }
    else if (num2 == num3 && num1 < num3)
    {
        max = num3;
        min = num1;
    }

    std::cout << "Max num is: " << max << std::endl;
    std::cout << "Min num is: " << min << std::endl;
    return 0;
}