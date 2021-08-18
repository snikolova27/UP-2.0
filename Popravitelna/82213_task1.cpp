//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Поправителен изпит - задачи
// 2021-08-18
//
// Име: Соня Николова Николова
// ФН:  82213
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
#include <new>

int **allocateMatrix(unsigned rows, unsigned cols)
{
    int **res = new (std::nothrow) int *[rows];
    if (!res)
    {
        return nullptr;
    }
    for (int i = 0; i < rows; i++)
    {
        res[i] = new (std::nothrow) int[cols];
        if (!res[i])
        {
            return nullptr;
        }
    }

    return res;
}

void clearMatrix(int **matrix, unsigned rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int **matrix, unsigned rows, unsigned cols)
{
    std::cout << "Enter elements of matrix: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void print(int **matrix, unsigned rows, unsigned cols)
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

int count1Bits(int num)
{
    int cnt = 0;
    int temp = num; //0101  << 1 = 01010
                    // 0101  >> 1 =  010
                    //0101
                    //0001

    //13(10) =  01101
    do
    {
        if (temp & 1 == 1)
        {
            cnt++;
        }
        temp >>= 1;
    } while (temp);

    return cnt;
}

bool isUneven(int num)
{
    return num % 2 != 0;
}

void putZeros(int **matrix, unsigned rows, unsigned cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (isUneven(count1Bits(matrix[i][j])))
            {
                matrix[i][j] = 0;
            }
        }
    }
}
//save the indexes of rows and columns with all zeros
void findZeroRowsCols(int **matrix, unsigned rows, unsigned cols, int *rowsIdx, int &cntRows, int *colsIdx, int &cntCols)
{
    cntRows = 0;
    cntCols = 0;

    for (int i = 0; i < rows; i++)
    {
        bool allZeros;
        for (int j = 0; j < cols; j++)
        {
            allZeros = false;
            if (matrix[i][j] == 0)
            {
                allZeros = true;
            }
        }
        if (allZeros)
        {
            rowsIdx[cntRows] = i;
            cntRows++;
        }
    }

    for (int i = 0; i < cols; i++)
    {
        bool allZeros;
        for (int j = 0; j < rows; j++)
        {
            allZeros = false;
            if (matrix[j][i] == 0)
            {
                allZeros = true;
            }
        }

        if (allZeros)
        {
            colsIdx[cntCols] = i;
            cntCols++;
        }
    }
}
void removeRowsZeros(int **matrix, unsigned rows, unsigned cols, int *rowsIdx, int cntRows, int &newRows)
{
    newRows = rows;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cntRows; j++)
        {
            if (rowsIdx[j] == i)
            {
                for (int k = 0; k < cols; k++)
                {
                    matrix[i][k] = matrix[i + 1][k];
                    newRows--;
                }
            }
        }
    }
}

void removeColsZeros(int **matrix, unsigned rows, unsigned cols, int *colsIdx, int cntCols, int &newCols)
{
    newCols = cols;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < cntCols; j++)
        {
            if (colsIdx[j] == i)
            {
                for (int k = 0; k < rows; k++)
                {
                    matrix[k][i] = matrix[k][i+1];
                    newCols--;
                }
            }
        }
    }
}
int main()
{
    unsigned n, m;
    do
    {
        std::cout << "Enter count of rows:  ";
        std::cin >> n;

        if (!std::cin)
        {
            std::cout << "Should be a number" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else if (n <= 0)
        {
            std::cout << "Number should be greater than zero. Try again. \n";
            std::cout << "N: ";
            std::cin >> n;
        }
    } while (!std::cin || n <= 0);

    do
    {
        std::cout << "Enter count of columns:  ";
        std::cin >> m;
        if (!std::cin)
        {
            std::cout << "Should be a number" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else if (m <= 0)
        {
            std::cout << "Number should be greater than zero. Try again. \n";
            std::cout << "M: ";
            std::cin >> m;
        }
    } while (!std::cin || m <= 0);

    int **matrix = allocateMatrix(n, m);
    if (!matrix)
    {
        std::cout << "Problem while allocating memory for matrix." << std::endl;
        return -1;
    }
    inputMatrix(matrix, n, m);
    print(matrix, n, m);
    clearMatrix(matrix, n);

    return 0;
}