#include <iostream>

const int MAX_ARRAY_SIZE = 20;
const int MAX_PASS_LEN = 10;

void input(char array[], int size)
{
    std::cout << "Enter password character by character: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void modifyPass(char array[], int size)
{
    int newSize = size * 2 - 1;
    char newPass[MAX_ARRAY_SIZE] = {};

    for (int i = 0, j = 0; i < newSize; i += 2, j++)
    {
        newPass[i] = array[j];
    }
    for (int i = 1, j = 0; i < newSize, j < 10; i += 2, j++)
    {
        newPass[i] = char(j + '0');
    }

    for (int i = 0; i < newSize; i++)
    {
        std::cout << newPass[i];
    }
    std::cout << std::endl;
}

int main()
{
    char pass[MAX_ARRAY_SIZE] = {};
    int size;
    std::cout << "Enter lenght of password: ";
    std::cin >> size;

    if (size < 0 || size > MAX_PASS_LEN)
    {
        std::cout << "Lenght should be greater than 0 and less than 10!" << std::endl;
    }

    else
    {
        input(pass, size);
        modifyPass(pass, size);
    }
    return 0;
}