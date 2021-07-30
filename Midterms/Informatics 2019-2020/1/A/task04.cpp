#include <iostream>

bool isInBoundaries(int num, int size)
{
    return num > 0 && num <= size * size;
}

int **allocateMatrix(int size)
{
    int **matrix = new (std::nothrow) int *[size];
    if (!matrix)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new (std::nothrow) int[size];
        if (!matrix[i])
        {
            std::cout << "Problem allocating memory" << std::endl;
            return nullptr;
        }
    }
    return matrix;
}

void clear(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void input(int **matrix, int size)
{
    std::cout << "Enter matrix elements: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num;
            std::cin >> num;
            if (isInBoundaries(num, size))
            {
                matrix[i][j] = num;
            }
            else
            {
                do
                {
                    std::cout << "Invalid number! It should be in the interval [1,size]. Try again. \n";
                    std::cin >> num;
                } while (isInBoundaries(num, size));
                matrix[i][j] = num;
            }
        }
    }
}

int sumRow(int **matrix, int size, int row)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[row][i];
    }

    return sum;
}

int sumCol(int **matrix, int size, int col)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][col];
    }

    return sum;
}

int sumMainDiagonal(int **matrix, int size)
{
    int sum = 0;
    int i = 0;

    for (int j = 0; j < size; j++)
    {
        if (i == j)
        {
            sum += matrix[i][j];
        }
        i++;
    }

    return sum;
}

int sumSecondaryDiagonal(int **matrix, int size)
{
    int sum = 0;
    int i = size - 1;
    for (int j = 0; j < size; j++)
    {
        sum += matrix[j][i];
        i--;
    }

    return sum;
}

bool areDiagonalSumsEqual(int **matrix, int size)
{
    return sumMainDiagonal(matrix, size) == sumSecondaryDiagonal(matrix, size);
}

bool isSumRowsEqual(int **matrix, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (sumRow(matrix, size, i) != sumRow(matrix, size, i + 1))
        {
            return false;
        }
    }
    return true;
}

bool isSumColEqual(int **matrix, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (sumCol(matrix, size, i) != sumCol(matrix, size, i + 1))
        {
            return false;
        }
    }
    return true;
}

bool isMagic(int **matrix, int size)
{
    if (!isSumColEqual(matrix, size) || !isSumRowsEqual(matrix, size) || !areDiagonalSumsEqual(matrix, size))
    {
        return false;
    }
    int sumCols = sumCol(matrix, size, 0);
    int sumRows = sumRow(matrix, size, 0);
    int sumDiag = sumMainDiagonal(matrix, size);

    return (sumCols == sumRows && sumCols == sumDiag);
}
int main()
{
    int size;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Size should be greater than 0" << std::endl;
    }
    int **matrix = allocateMatrix(size);
    input(matrix, size);
    // std::cout << isSumColEqual(matrix, size) << std::endl;
    // std::cout << isSumRowsEqual(matrix, size) << std::endl;
    // std::cout << areDiagonalSumsEqual(matrix, size) << std::endl;
    // std::cout << sumRow(matrix, size, 0) << std::endl;
    // std::cout << sumCol(matrix, size, 0) << std::endl;

    // std::cout << sumMainDiagonal(matrix, size) << std::endl;
    // std::cout << sumSecondaryDiagonal(matrix, size) << std::endl;
    if (isMagic(matrix, size))
    {
        std::cout << "Magic" << std::endl;
    }
    else
    {
        std::cout << "Not magic" << std::endl;
    }
    clear(matrix, size);

    return 0;
}