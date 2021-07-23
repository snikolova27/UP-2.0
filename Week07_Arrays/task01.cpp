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

int minElement(int *array, int size)
{
    int min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int maxElement(int *array, int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int sumOfElements(int *array, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int productOfElements(int *array, int size)
{
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        product *= array[i];
    }

    return product;
}

double avgOfElements(int *array, int size)
{
    double sum = sumOfElements(array, size);
    return sum / size;
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

        std::cout << "Min: " << minElement(numbers, n) << std::endl;
        std::cout << "Max: " << maxElement(numbers, n) << std::endl;
        std::cout << "Sum: " << sumOfElements(numbers, n) << std::endl;
        std::cout << "Product: " << productOfElements(numbers, n) << std::endl;
        std::cout << "Average: " << avgOfElements(numbers, n) << std::endl;
    }
    else
    {
        std::cout << "Elements should be more than 0!" << std::endl;
    }
    return 0;
}