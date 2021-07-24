#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void input(int *array, int size)
{
    std::cout << "Enter elemenrs of array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

void switchNums(int *array, int size)
{
    int mid = size / 2;

    for (int i = 0; i < mid; i++)
    {
        if (array[i] > array[size - i - 1])
        {
            swap(&array[i], &array[size - i - 1]);
        }
    }
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Size should be more than 0!" << std::endl;
    }

    else
    {
        int *numbers = new (std::nothrow) int[size];
        if (!numbers)
        {
            std::cout << "Problem allocating memory :(" << std::endl;
        }

        else
        {
            input(numbers, size);
            switchNums(numbers, size);
            print(numbers, size);
        }

        delete[] numbers;
    }
    
    return 0;
}