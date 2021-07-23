#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
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
        for(int j=0; j<size -1-i;j++)
        {
            if(array[j] > array [j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }
}
int main()
{

    int numbers[MAX_ARRAY_SIZE] = {};
    int size = insertElements(numbers);
    bubbleSort(numbers, size);
    printArray(numbers, size);

    return 0;
}