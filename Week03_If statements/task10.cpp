#include <iostream>

int main()
{
    int num1, num2;
    char operation;

    std::cout << "Enter 2 numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter operation (+,-,/,%): ";
    std::cin >> operation;

    switch (operation)
    {
    case '+':
    {
        std::cout << num1 + num2 << std::endl;
        break;
    }
    case '-':
    {
        std::cout << num1 - num2 << std::endl;
        break;
    }
    case '/':
    {
        if (num2 == 0)
        {
            std::cout << "Cannot divide by 0! \n";
            break;
        }
        else
        {
            std::cout << num1 / num2 << std::endl;
            break;
        }
    }
    case '%':
    {
        if (num2 == 0)
        {
            std::cout << "Cannot divide by 0! \n";
            break;
        }
        else
        {
            std::cout << num1 % num2 << std::endl;
            break;
        }
    }
    default:
    {
        std::cout << "Invalid command! \n";
    }
    }
    
    return 0;
}