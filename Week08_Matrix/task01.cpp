#include <iostream>

const int MAX_ARRAY_SIZE = 100;

int sumRow(int array[][MAX_ARRAY_SIZE], int size, int row)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += array[row][i];
    }

    return result;
}

int sumCol(int array[][MAX_ARRAY_SIZE], int size, int col)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += array[i][col];
    }

    return result;
}

int sumAll(int array[][MAX_ARRAY_SIZE], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += sumCol(array, size, i);
    }
    return result;
}

void inputMatrix(int array[][MAX_ARRAY_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> array[i][j];
        }
    }
    std::cin.ignore();
}

int sumOddCols(int array[][MAX_ARRAY_SIZE], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            result += sumCol(array, size, i);
        }
    }

    return result;
}
int main()
{
    // int array[6][100] = {
    //     {11, 12, 13, 14, 15, 16},
    //     {21, 22, 23, 24, 25, 26},
    //     {31, 32, 33, 34, 35, 36},
    //     {41, 42, 43, 44, 45, 46},
    //     {51, 52, 53, 54, 55, 56},
    //     {61, 62, 63, 64, 65, 66}};

    // for (int i = 0; i < 6; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         std::cout << "Col #" << i + 1 << " sum is " << sumCol(array, 6, i) << std::endl;
    //     }
    // }
    // std::cout << "Sum of all odd cols is: " << sumOddCols(array, 6) << std::endl;

    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};
    int size;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;
    std::cin.ignore();

    if (size > 0 && size < MAX_ARRAY_SIZE)
    {
        inputMatrix(numbers, size);
        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << "Col #" << i + 1 << " sum is " << sumCol(numbers, size, i) << std::endl;
            }
        }
        std::cout << "Sum of all odd cols is: " << sumOddCols(numbers, size) << std::endl;
    }
    
    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }

    return 0;
}