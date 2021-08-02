#include <iostream>

int **allcoteMatrix(int rows, int cols)
{
    int **matrix = new (std::nothrow) int *[rows];
    if (!matrix)
    {
        std::cout << "Memory problem" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new (std::nothrow) int[cols];
        if (!matrix[i])
        {
            std::cout << "Memory problem" << std::endl;
            return nullptr;
        }
    }

    return matrix;
}

void input(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
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

void clear(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int **answerMatrix(int **matrix, int rows, int cols, int num, int &cntRows, int *cntColsEachRow)
{
    for (int i = 0; i < rows; i++)
    {
        cntColsEachRow[i] = 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] % num == 0)
            {
                ++cntColsEachRow[i];
            }
        }
        if (cntColsEachRow[i] > 0)
        {
            cntRows++;
        }
    }

    int **result = new (std::nothrow) int *[cntRows];
    int currentRowAllocation = 0;
    for (int i = 0; i < rows; i++)
    {
        if (cntColsEachRow[i] != 0)
        {
            result[currentRowAllocation] = new (std::nothrow) int[cntColsEachRow[i]];
            if (!result[currentRowAllocation])
            {
                std::cout << "Memory problem" << std::endl;
                return nullptr;
            }
            currentRowAllocation++;
        }
    }

    int currentRow = 0, currentCol = 0;

    for (int i = 0; i < rows; i++)
    {
        currentCol = 0;

        if (cntColsEachRow[i] != 0)
        {
            for (int j = 0; j < cols; j++)
            {
                if (currentCol == cntColsEachRow[i])
                {
                    break;
                }
                if (matrix[i][j] % num == 0)
                {
                    result[currentRow][currentCol] = matrix[i][j];
                    currentCol++;
                }
            }
            currentRow++;
        }
    }

    return result;
}

int main()
{
    int cols, rows, num;
    std::cout << "Enter rows of matrix: ";
    std::cin >> rows;
    std::cout << "Enter cols of matrix: ";
    std::cin >> cols;

    std::cout << "Enter num to divide by: ";
    std::cin >> num;
    if (!cols || !rows || num == 0)
    {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }

    int **matrix = allcoteMatrix(rows, cols);
    if (!matrix)
    {
        return -2;
    }

    input(matrix, rows, cols);

    int *cntColsEachRow = new (std::nothrow) int[rows];
    if (!cntColsEachRow)
    {
        std::cout << "Memory problem" << std::endl;
        return -3;
    }
    int cntOfRows = 0;

    int **result = answerMatrix(matrix, rows, cols, num, cntOfRows, cntColsEachRow);
    int currentRowAllocate = 0;

    for (int i = 0; i < rows; ++i)
    {
        if (cntColsEachRow[i] != 0)
        {
            for (int j = 0; j < cntColsEachRow[i]; ++j)
            {
                std::cout << result[currentRowAllocate][j] << " ";
            }
            std::cout << std::endl;
            ++currentRowAllocate;
        }
    }

    clear(matrix, rows);
    clear(result, rows);
    delete[] cntColsEachRow;
    
    return 0;
}