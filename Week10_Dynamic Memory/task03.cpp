#include <iostream>

void input(int *array, int size)
{
    std::cout << "Enter elemenrs of array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

int min(int *array, int size)
{
    int min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

int max(int *array, int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}

int sum(int *array, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size)
    {
        int *array = new (std::nothrow) int[size];
        if (array)
        {
            input(array, size);
            std::cout << "Sum of elements: " << sum(array, size) << std::endl;
            std::cout << "Min element: " << min(array, size) << std::endl;
            std::cout << "Max element: " << max(array, size) << std::endl;

            delete[] array;
        }
        else
        {
            std::cout << "Memory allocation problem :(" << std::endl;
        }
    }
    return 0;
}