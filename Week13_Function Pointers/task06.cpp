#include <iostream>
typedef void (*sortFunc)(int *, int);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void insertionSort(int *array, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
void merge(int *array, int left, int middle, int right)
{
    int nLeft = middle - left + 1;
    int nRight = right - middle;
    int L[nLeft], R[nRight];

    for (int i = 0; i < nLeft; i++)
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < nRight; j++)
    {
        R[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < nLeft && j < nRight)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nLeft)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < nRight)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = (left + right - 1) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}

void mergeSort(int *array, int size)
{
    mergeSort(array, 0, size - 1);
}

void sort(int *array, int size, sortFunc sorting)
{
    sorting(array, size);
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
    int *array = allocateArray(size);
    if (!array)
    {
        return -2;
    }
    input(array, size);

    std::cout << "Bubble: ";
    sort(array, size, bubbleSort);
    print(array, size);
    std::cout << "Insertion: ";
    sort(array, size, insertionSort);
    print(array, size);
    std::cout << "Merge: ";
    sort(array, size, mergeSort);
    print(array, size);
    clear(array);
    return 0;
}