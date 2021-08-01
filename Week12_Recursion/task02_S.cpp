#include <iostream>
const int MAX_ARRAY_SIZE = 1000;

int convertToBinary(int num, bool *binary, int pos, int size)
{
    if (num == 0)
    {
        return size;
    }
    bool bit = num % 2;
    binary[pos] = bit;
    return convertToBinary(num / 2, binary, pos + 1, size + 1);
}
void printReversed(bool *binary, int pos)
{
    if (pos < 0)
    {
        return;
    }
    std::cout << binary[pos];
    return printReversed(binary, pos - 1);
}
int main()
{
    int num;
    std::cout << "Enter num: ";
    std::cin >> num;

    bool numInBinary[MAX_ARRAY_SIZE] = {};
    int size = convertToBinary(num, numInBinary, 0, 0);
    printReversed(numInBinary, size);
    return 0;
}