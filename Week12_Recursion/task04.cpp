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

int maxIdx(int *array, int size, int pos, int maxId)
{
    if (pos == size)
    {
        return maxId;
    }
    if (array[maxId] < array[pos])
    {
        maxId = pos;
    }
    return maxIdx(array, size, pos + 1, maxId);
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Size should be greater than zero" << std::endl;
        return -1;
    }

    int *array = new (std::nothrow) int[size];
    if (!array)
    {
        std::cout << "Memory problem" << std::endl;
        return -2;
    }

    input(array, size, 0);
    std::cout << "Max element: " << array[maxIdx(array, size, 0, 0)] << std::endl;
    
    delete[] array;

    return 0;
}