#include <iostream>

const int MAX_SIZE = 100;

unsigned int **allocateMatrix(unsigned int rows, unsigned int cols)
{
    unsigned int **matrix = new (std::nothrow) unsigned int *[rows];
    if (!matrix)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new (std::nothrow) unsigned int[cols];
        if (!matrix[i])
        {
            std::cout << "Problem allocating memory" << std::endl;
            return nullptr;
        }
    }

    return matrix;
}

void input(unsigned int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)

        {
            std::cin >> matrix[i][j];
        }
    }
}
void clear(unsigned int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isPermutation(unsigned int **matrix, int rows, int col1, int col2)
{
    int counterCol1[MAX_SIZE] = {};
    int counterCol2[MAX_SIZE] = {};
    int cnt = 0;

    for (int i = 0; i < rows; i++)
    {
        ++counterCol1[cnt + matrix[i][col1]];
        ++counterCol2[cnt + matrix[i][col2]];
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (counterCol1[i] != counterCol2[i])
        {
            return false;
        }
    }

    return true;
}

void printPermutations(unsigned int **matrix, int rows, int cols)
{
    bool found = false;

    for (int i = 0; i < cols - 1; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            if (isPermutation(matrix, rows, i, j))
            {
                found = true;
                std::cout << i << " " << j << std::endl;
            }
        }
    }
    if (!found)
    {
        std::cout << "No" << std::endl;
    }
}

int main()
{
    unsigned int rows, cols;
    std::cout << "Enter number of rows of matrix: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    unsigned int **matrix = allocateMatrix(rows, cols);
    if (!matrix)
    {
        return -1;
    }
    input(matrix, rows, cols);
    printPermutations(matrix, rows, cols);
    clear(matrix, rows);
    return 0;
}