#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minFrom(int *array, int size, int pos)
{
    int minIdx = pos;
    int min = array[pos];

    for (int i = pos + 1; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
            minIdx = i;
        }
    }

    return minIdx;
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

void selectionSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = minFrom(array, size, i);
        swap(&array[i], &array[min]);
    }
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Size cannot be less than 1!" << std::endl;
    }
    else
    {
        int *numbers = new (std::nothrow) int[size];
        if (!numbers)
        {
            std::cout << "Problem allocating memory :(" << std::endl;
            return -1;
        }

        else
        {
            input(numbers, size);
            selectionSort(numbers, size);
            print(numbers, size);
        }

        delete[] numbers;
    }
    return 0;
}