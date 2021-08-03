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

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void findLongestRow(int *array, int size, int &maxLenght, int &maxElement, int &currentLength, int &currentIndex)
{
    if (currentLength == size)
    {
        if (currentLength > maxLenght)
        {
            maxLenght = currentLength;
            maxElement = array[currentIndex - 1];
        }
        return;
    }

    if (array[currentIndex] == array[currentIndex - 1])
    {
        currentLength++;
    }
    else
    {
        if (currentLength > maxLenght)
        {
            maxLenght = currentLength;
            maxElement = array[currentIndex - 1];
        }
        currentLength = 1;
    }

    findLongestRow(array, size, maxLenght, maxElement, currentLength, ++currentIndex);
}

int *getLongestRow(int *array, int size, int &maxLen)
{
    int maxLen = 1, maxEl = array[0], currentIdx = 1, currentLen = 1;

    findLongestRow(array, size, maxLen, maxEl, currentLen, currentIdx);

    int *row = new (std::nothrow) int[maxLen];
    if (!row)
    {
        return nullptr;
    }
    for (int i = 0; i < maxLen; ++i)
    {
        row[i] = maxEl;
    }

    return row;
}
int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (!size)
    {
        return -1;
    }
    int *numbers = createArray(size);
    if (!numbers)
    {
        return -2;
    };

    int maxLen;
    input(numbers, size);

    int *longestRow = getLongestRow(numbers, size, maxLen);
    print(longestRow, maxLen);

    clean(numbers);
    clean(longestRow);

    return 0;
}