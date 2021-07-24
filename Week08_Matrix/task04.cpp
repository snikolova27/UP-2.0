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

bool hasDifferentDiagonal(int array[][MAX_ARRAY_SIZE], int size)
{
    //parallel to the main diagonal (diagonal = row - col)

    for (int diag = -(int)(size - 2); diag < (size - 2) - 1; diag++)
    {
        int cnt = 0;
        int firstEl;
        for (int row = 0; row < size; row++)
        {
            int col = row - diag;
            if (col >= 0 && col <= size - 1)
            {
                if (cnt == 0)
                {
                    firstEl = array[row][col];
                    ++cnt;
                }
                else
                {
                    if (array[row][col] != firstEl)
                    {
                        std::cout << firstEl << " " << array[row][col] << std::endl;
                        return true;
                    }
                }
            }
        }
    }

    // parallel to the secondary diagonal (diagonal = row + col)

    for (int diag = 1; diag <= 2 * (size - 1) - 1; ++diag)
    {
        int cnt = 0;
        int firstEl;
        for (int row = 0; row < size; ++row)
        {
            int col = diag - row;
            if (col >= 0 && col <= size - 1)
            {
                if (cnt == 0)
                {
                    firstEl = array[row][col];
                    ++cnt;
                }
                else
                {
                    if (array[row][col] != firstEl)
                    {
                        std::cout << firstEl << " " << array[row][col] << std::endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
        std::cout<< std::boolalpha << hasDifferentDiagonal(array, size) << std::endl;
    }

    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }

    return 0;
}