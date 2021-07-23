#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void insertElements(double *array, int size)
{
    double num;
    for (int i = 0; i < size; i++)
    {
        std::cin >> num;
        array[i] = num;
    }
}

double minElement(double *array, int size)
{
    double min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

int elementsEqualToMin(double *array, int size)
{
    double min = minElement(array, size);
    int cnt = 0;

    for (int i = 0; i < size; i++)
    {
        if (min == array[i])
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{

    int n;
    std::cout << "How many elements do you wish to enter? ";
    std::cin >> n;

    if (n)
    {
        double numbers[MAX_ARRAY_SIZE] = {};
        insertElements(numbers, n);
        std::cout << elementsEqualToMin(numbers, n) << std::endl;
    }
    return 0;
}