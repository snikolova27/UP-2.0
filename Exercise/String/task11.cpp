#include <iostream>

const int MAX_ARRAY_SIZE = 100;

char *rowWithSymbol(char **matrix, int rows, int cols, char symbol)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == symbol)
            {
                return matrix[i];
            }
        }
    }
    return nullptr;
}

void input(char **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void clearMatrix(char **matrix, int rows)
{

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int rows, cols;
    std::cout << "Enter rows and cols: ";
    std::cin >> rows >> cols;

    if (!rows || !cols)
    {
        std::cout << "Gluposti!" << std::endl;
        return -1;
    }

    char **matrix = new (std::nothrow) char *[rows];
    if (!matrix)
    {
        std::cout << "Memory allocation problem :(" << std::endl;
        return -1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new (std::nothrow) char[cols];
        if (!matrix[i])
        {
            std::cout << "Memory allocation problem :(" << std::endl;
            return -1;
        }
    }
    std::cout << "Enter matrix elements: ";
    input(matrix, rows, cols);

    char symbol;
    std::cout << "Enter symbol to find: ";
    std::cin >> symbol;

    char *resRow = rowWithSymbol(matrix, rows, cols, symbol);
    for (int j = 0; j < cols; j++)
    {
        std::cout << resRow[j] << " ";
    }

    clearMatrix(matrix, rows);
    return 0;
}