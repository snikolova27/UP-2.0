#include <iostream>
#include <cmath>

const int MAX_ARRAY_SIZE = 20;

void input(bool array[], int size)
{
    std::cout << "Enter bits: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

int binaryToDecimal(bool array[], int size)
{
    int decimal = 0;
    for (int i = size - 1, j = 0; i >= 0, j < size; i--, j++)
    {
        decimal += int(array[i]) * (pow(2.0, j));
    }
    return decimal;
}

int decimalToOctal(int num)
{
    double octal = 0;
    double exponent = 0;
    int temp = num;

    while (temp)
    {
        int remainder = temp % 8;

        octal += remainder * pow(10.0, exponent);
        exponent++;
        temp /= 8;
    }

    return octal;
}

int main()
{
    bool bits[MAX_ARRAY_SIZE] = {};
    int size;
    std::cout << "How many bits will you enter? ";
    std::cin >> size;

    if (size < 0 || size > MAX_ARRAY_SIZE)
    {
        std::cout << "Bits should be less than 100 and more than 0!" << std::endl;
    }
    else
    {
        input(bits, size);
        std::cout << decimalToOctal(binaryToDecimal(bits, size)) << std::endl;
    }
    return 0;
}