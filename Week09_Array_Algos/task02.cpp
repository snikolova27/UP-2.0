#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int minFrom(int array[], int size, int pos)
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

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int pos = minFrom(array, size, i);
        swap(array[pos], array[i]);
    }
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int array[MAX_ARRAY_SIZE] = {};
    int size = 0;
    char ch;
    std::cin >> ch;

    while (ch != '#')
    {
        array[size] = int(ch - '0');
        size++;
        std::cin >> ch;
    }
    selectionSort(array, size);
    print(array, size);
    return 0;
}