#include <iostream>

int **allocateMatrix(int rows, int cols)
{
    int **matrix = new (std::nothrow) int *[rows];
    if (!matrix)
    {
        return nullptr;
    }
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new (std::nothrow) int[cols];
        if (!matrix[i])
        {
            return nullptr;
        }
    }

    return matrix;
}

void clear(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **multiplyMatrixes(int **m1, int rows1, int cols1, int **m2, int rows2, int cols2)
{
    if (cols1 != rows2)
    {
        std::cout << "Cannot multiply. Cols of first matrix should be equal to rows of the second one" << std::endl;
        return nullptr;
    }
    int **result = allocateMatrix(rows1, cols2);
    if (!result)
    {
        std::cout << "memory problem ->result matrix" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return result;
}

void input(int **matrix, int rows, int cols)
{
    std::cout << "Enter matrix elements: " << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Element[" << i << "," << j << "]:";
            std::cin >> matrix[i][j];
        }
    }
}

void print(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows1, rows2, cols1, cols2;
    std::cout << "Enter rows and cols of first matrix: ";
    std::cin >> rows1 >> cols1;

    if (!rows1 || !cols1)
    {
        std::cout << "Invalid input!" << std::endl;
        return -1;
    }

    int **matrix1 = allocateMatrix(rows1, cols1);
    if (!matrix1)
    {
        std::cout << "memory problem -> matrix1" << std::endl;
        return -2;
    }

    std::cout << "Enter rows and cols of second matrix: ";
    std::cin >> rows2 >> cols2;

    if (!rows2 || !cols2)
    {
        std::cout << "Invalid input!" << std::endl;
        return -1;
    }

    int **matrix2 = allocateMatrix(rows2, cols2);
    if (!matrix2)
    {
        std::cout << "memory problem -> matrix2" << std::endl;
        return -2;
    }

    input(matrix1, rows1, cols1);
    input(matrix2, rows2, cols2);

    int **result = multiplyMatrixes(matrix1, rows1, cols1, matrix2, rows2, cols2);
    if (!result)
    {
        return -3;
    }
    print(result, rows1, cols2);
    clear(matrix1, rows1);
    clear(matrix2, rows2);
    clear(result, rows1);

    return 0;
}