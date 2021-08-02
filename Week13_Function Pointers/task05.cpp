#include <iostream>

typedef void (*sortFunc)(int *, int, bool);

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

int maxFrom(int *array, int size, int pos)
{

    int maxIdx = pos;
    int max = array[pos];

    for (int i = pos + 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
            maxIdx = i;
        }
    }

    return maxIdx;
}
void selectionSort(int *array, int size, bool ascending)
{
    if (ascending)
    {
        for (int i = 0; i < size; i++)
        {
            int pos = minFrom(array, size, i);
            swap(&array[i], &array[pos]);
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int pos = maxFrom(array, size, i);
            swap(&array[i], &array[pos]);
        }
    }
}

void sort(int *array, int size, bool wayToSort, sortFunc sorting)
{
    if (wayToSort)
    {
        sorting(array, size, true);
    }
    else
    {
        sorting(array, size, false);
    }
}

int *allocateArray(int size)
{
    int *array = new (std::nothrow) int[size];
    if (!array)
    {
        std::cout << "problem allocating memory" << std::endl;
        return nullptr;
    }
    return array;
}

void input(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void clear(const int *array)
{
    delete[] array;
}

void print(const int *array, int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int size;
    std::cin >> size;
    if (!size)
    {
        return -1;
    }
    int *numbers = allocateArray(size);
    if (!numbers)
    {
        return -2;
    }
    input(numbers, size);

    sort(numbers, size, true, selectionSort);
    print(numbers, size);
    sort(numbers, size, false, selectionSort);
    print(numbers, size);
    clear(numbers);
    return 0;
}