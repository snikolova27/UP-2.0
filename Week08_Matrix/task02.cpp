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

int sumCol(int array[][MAX_ARRAY_SIZE], int size, int colIdx)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res += array[i][colIdx];
    }

    return res;
}

int sumRow(int array[][MAX_ARRAY_SIZE], int size, int rowIdx)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res += array[rowIdx][i];
    }

    return res;
}

bool isMagic(int array[][MAX_ARRAY_SIZE], int size)
{
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (sumCol(array, size, i) == sumRow(array, size, i))
        {
            cnt++;
        }
    }

    return cnt == size;
}
int main()
{
    int size;
    int numbers[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    if (size > 0 && size < MAX_ARRAY_SIZE)
    {
        input(numbers, size);
        if (isMagic(numbers, size))
        {
            std::cout << "Magic!" << std::endl;
        }
        else
        {
            std::cout << "Normal :(" << std::endl;
        }
    }
    
    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }

    return 0;
}