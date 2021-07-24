#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int minFrom(int *array, int size, int pos)
{
    int minEl = array[pos];
    int minIdx = pos;

    for (int i = pos + 1; i < size; i++)
    {
        if (array[i] < minEl)
        {
            minEl = array[i];
            minIdx = i;
        }
    }

    return minIdx;
}

int insertElements(int *array)
{
    int size;
    std::cout << "How many elements do you wish to enter? ";
    std::cin >> size;

    if (size > 0)
    {

        for (int i = 0; i < size; i++)
        {
            std::cin >> array[i];
        }
    }

    return size;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}
void bubbleSort(int *array, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void bubbleOptimised(int *array, int size)
{
    bool changed = false;
    int sorted = 0;

    do
    {
        changed = false;
        for (int i = size - 1; i > sorted; i--)
        {
            if (array[i] < array[i - 1])
            {
                swap(array[i], array[i - 1]);
                changed = true;
            }
        }
        sorted++;
    } while (changed);

}
void selectionSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int pos = minFrom(array, size, i);
        swap(array[i], array[pos]);
    }
}

void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;

        while (j >= 0 && temp <= array[j])
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = temp;
    }
}
int main()
{

    int numbers[MAX_ARRAY_SIZE] = {};
    int size = insertElements(numbers);
    // bubbleSort(numbers, size);
    // printArray(numbers, size);
    // std::cout << std::endl;
    // selectionSort(numbers, size);
    // printArray(numbers, size);
    std::cout << std::endl;
    insertionSort(numbers, size);
    printArray(numbers, size);

    return 0;
}