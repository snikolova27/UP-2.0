#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

int getSize()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size < 1 || size > MAX_ARRAY_SIZE)
    {
        std::cout << "Array size should be in the interval [1,999] \n";
        do
        {
            std::cout << "Enter size of array:";
            std::cin >> size;

        } while (size >= 1 && size < MAX_ARRAY_SIZE);
    }

    return size;
}

void input(double array[], int size)
{
    std::cout << "Enter elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void print(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

double sumEl(double array[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

double averageEl(double array[], int size)
{
    double sum = sumEl(array, size);
    return sum / size;
}

void removeBelowAverage(double array[], int size)
{
    int newSize = 0;
    double average = averageEl(array, size);
    double result[MAX_ARRAY_SIZE] = {};

    for (int i = 0; i < size; i++)
    {
        if (array[i] > average)
        {
            result[newSize] = array[i];
            newSize++;
        }
    }
    print(result, newSize);
}

int main()
{
    int size = getSize();
    double numbers[MAX_ARRAY_SIZE] = {};
    input(numbers, size);
    print(numbers, size);
    removeBelowAverage(numbers, size);
}