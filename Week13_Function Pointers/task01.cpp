#include <iostream>

typedef void (*funcPtr)(int, double *, int);

void increase(int percent, double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += arr[i] * percent / 100;
    }
}

void decrease(int percent, double *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] -= arr[i] * percent / 100;
    }
}
void modify(double *array, int size, int percent, funcPtr function)
{
    function(percent, array, size);
}

double *allocateArray(int size)
{
    double *array = new (std::nothrow) double[size];
    if (!array)
    {
        std::cout << "problem allocating memory" << std::endl;
        return nullptr;
    }
    return array;
}

void input(double *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void clear(const double *array)
{
    delete[] array;
}

void print(const double *array, int size)
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
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Invalid size" << std::endl;
        return -1;
    }
    double *numbers = allocateArray(size);
    if (!numbers)
    {
        return -2;
    }
    input(numbers, size);

    int percentI, percentD;
    std::cout << "Enter percent for increase: ";
    std::cin >> percentI;
    std::cout << "Enter percent for decrease: ";
    std::cin >> percentD;
    if (!percentD || !percentI)
    {
        std::cout << "Invalid percents!" << std::endl;
        return -3;
    }
    modify(numbers, size, percentI, increase);
    print(numbers, size);
    modify(numbers, size, percentD, decrease);
    print(numbers, size);
}