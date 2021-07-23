#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void insertElements(int *array, int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        std::cin >> num;
        array[i] = num;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

void reverseArray(int *array, int size)
{

    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}
void reverseArray2(int *array, int size)
{
    int result[MAX_ARRAY_SIZE] = {};
    for (int i = 0; i < size; i++)
    {
        result[i] = array[size - i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = result[i];
    }
}
int main()
{
    int n;
    std::cout << "How many elements do you wish to enter? ";
    std::cin >> n;

    if (n)
    {
        int numbers[MAX_ARRAY_SIZE] = {};
        insertElements(numbers, n);
        reverseArray2(numbers, n);
        printArray(numbers, n);

        std::cout << std::endl;

        reverseArray(numbers, n);
        printArray(numbers, n);
    }
    return 0;
}