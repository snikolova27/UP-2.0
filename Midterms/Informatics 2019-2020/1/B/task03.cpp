#include <iostream>
const int MAX_ARRAY_SIZE = 5000;

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

void input(int array[], int size)
{
    std::cout << "Enter elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
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

bool isOdd(int num)
{
    return num % 2 == 1;
}

int sumLesserOddNums(int num)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        if (isOdd(i))
        {
            sum += i;
        }
    }
    return sum;
}

void addNums(int array[], int size)
{
    int result[MAX_ARRAY_SIZE] = {};
    int newSize = 0;

    for (int i = 0; i < size; i++)
    {
        result[newSize] = array[i];
        newSize++;
        if (!isOdd(array[i]))
        {
            result[newSize] = array[i] / 2;
            newSize++;
        }
        else
        {
            result[newSize] = sumLesserOddNums(array[i]);
            newSize++;
        }
    }

    print(result, newSize);
}

int main()
{

    int size = getSize();
    int numbers[MAX_ARRAY_SIZE] = {};
    input(numbers, size);
    print(numbers, size);
    addNums(numbers, size);
    return 0;
}