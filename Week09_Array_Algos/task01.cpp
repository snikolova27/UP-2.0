#include <iostream>

const int MAX_MATRIX_SIZE = 100;

void input(int array[][MAX_MATRIX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> array[i][j];
        }
    }
}

void print(int array[][MAX_MATRIX_SIZE], int size)
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

void rotate90degrees(int array[][MAX_MATRIX_SIZE], int size)
{
    int temp[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp[i][j] = array[j][size - 1 - i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int array[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = {};
    int size;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    if (size > 0 && size < MAX_MATRIX_SIZE)
    {
        input(array, size);
        rotate90degrees(array, size);
        std::cout << std::endl;
        print(array, size);
    }

    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }
    
    return 0;
}