#include <iostream>

void input(int *array, int size, int pos)
{
    if (pos == size)
    {
        return;
    }
    std::cin >> array[pos];
    return input(array, size, pos + 1);
}

void printReversed(int *array, int pos)
{
    if (pos < 0)
    {
        return;
    }
    std::cout << array[pos] << " ";
    return printReversed(array, pos - 1);
}
int main()
{
    int size;
    std::cout << "Enter how many numbers you will enter:";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Should be >0" << std::endl;
    }
    int *array = new (std::nothrow) int[size];
    if (!array)
    {
        std::cout << "Memory problem" << std::endl;
    }
    input(array, size, 0);
    printReversed(array, size - 1);
    delete[] array;

    return 0;
}