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

void rightShiftElementsOfArray(int *array, int size)
{
    int lastElement = array[size - 1];

    for (int i = size - 1; i > 0; --i)
    {
        array[i] = array[i - 1];
    }

    array[0] = lastElement;
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

        int pos;
        std::cout << "How many positions do you wish to move the elements with? ";
        std::cin >> pos;
        if (pos)
        {
            if (pos == 0)
            {
                printArray(numbers, n);
            }
            else
            {
                for (int i = 0; i < (pos % n); ++i)
                {
                    rightShiftElementsOfArray(numbers, n);
                }
                printArray(numbers, n);
            }
        }
        else
        {
            std::cout << "Position is invalid" << std::endl;
        }
    }
    return 0;
}