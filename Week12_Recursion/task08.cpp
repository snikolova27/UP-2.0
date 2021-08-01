#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void input(char matrix[][MAX_ARRAY_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void bucketPaint(char matrix[][MAX_ARRAY_SIZE], int rows, int cols, int currentI, int currentJ, char oldCh, char newCh)
{

    if (matrix[currentI][currentJ] != oldCh || matrix[currentI][currentJ] == newCh || currentI == -1 || currentJ == -1 || currentI == rows || currentJ == cols)
    {
        return;
    }
    if (matrix[currentI][currentJ] == oldCh)
    {
        matrix[currentI][currentJ] = newCh;
    }
    bucketPaint(matrix, rows, cols, currentI + 1, currentJ, oldCh, newCh);
    bucketPaint(matrix, rows, cols, currentI - 1, currentJ, oldCh, newCh);
    bucketPaint(matrix, rows, cols, currentI, currentJ + 1, oldCh, newCh);
    bucketPaint(matrix, rows, cols, currentI, currentJ - 1, oldCh, newCh);
}

void print(char matrix[][MAX_ARRAY_SIZE], int rows, int cols)
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
    int rows, cols;
    std::cout << "Enter count of rows: ";
    std::cin >> rows;
    std::cout << "Enter count of cols: ";
    std::cin >> cols;

    char matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {};

    input(matrix, rows, cols);

    int posR, posC;
    char ch;
    std::cout << "Enter starting position. First, enter row and then column: ";
    std::cin >> posR >> posC;
    if (posC > cols || posR > rows)
    {
        std::cout << "Invalid position!" << std::endl;
        return -2;
    }
    std::cout << "Enter character: ";
    std::cin >> ch;

    bucketPaint(matrix, rows, cols, posR, posC, matrix[posR][posC], ch);
    print(matrix, rows, cols);

    return 0;
}