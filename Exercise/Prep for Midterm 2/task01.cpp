#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

int *createArray(int size)
{
    int *res = new (std::nothrow) int[size];
    if (!res)
    {
        return nullptr;
    }

    return res;
}

void clean(int *arr)
{
    delete[] arr;
}

void input(int *array, int size)
{
    std::cout << "enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

bool isPermutation(int *array1, int *array2, int size)
{
    int cntFirst[MAX_ARRAY_SIZE] = {};
    int cntSecond[MAX_ARRAY_SIZE] = {};

    for (int i = 0; i < size; i++)
    {
        ++cntFirst[array1[i]];
        ++cntSecond[array2[i]];
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (cntFirst[i] != cntSecond[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int size;
    std::cout << "enter size of arrays: ";
    std::cin >> size;
    if (!size)
    {
        return -1;
    }

    int *array1 = createArray(size);
    if (!array1)
    {
        std::cout << "Memory problem " << std::endl;
        return -2;
    }
    int *array2 = createArray(size);
    if (!array2)
    {
        std::cout << "Memory problem " << std::endl;
        return -2;
    }

    input(array1, size);
    input(array2, size);
    std::cout << std::boolalpha << isPermutation(array1, array2, size) << std::endl;
    clean(array1);
    clean(array2);

    return 0;
}