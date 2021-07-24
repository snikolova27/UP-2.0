#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void input(int array[][MAX_ARRAY_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> array[i][j];
        }
    }
}

void print(int array[][MAX_ARRAY_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printTransposed(int array[][MAX_ARRAY_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << array[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

void transposeMatrix(int array[][MAX_ARRAY_SIZE], int size)
{
    int temp[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][j] = array[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = temp[j][i];
        }
    }
}

int main()
{
    int array[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};
    int size;
    std::cout << "Enter matrix size: ";
    std::cin >> size;

    if (size > 0 && size < MAX_ARRAY_SIZE)
    {
        input(array, size);
        std::cout << std::endl;
        transposeMatrix(array, size);
        print(array, size);
        std::cout << std::endl;
        printTransposed(array, size);
    }

    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }

    return 0;
}