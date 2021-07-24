#include <iostream>

int *createArray(int size)
{
    int *array = new (std::nothrow) int[size];
    if (!array)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return nullptr;
    }
    return array;
}

void fill(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
}

void print2Darray(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    if (!size)
    {
        std::cout << "Size cannot be less than 1!" << std::endl;
    }

    else
    {
        int **array2d = new (std::nothrow) int *[size + 1];
        if (!array2d)
        {
            std::cout << "Problem allocating memory for 2D array :(" << std::endl;
        }

        else
        {
            for (int i = 0; i < size; i++)
            {
                array2d[i] = createArray(size - i);
                if (array2d[i])
                {
                    fill(array2d[i], size - i);
                }
            }

            print2Darray(array2d, size);
        }

        for (int i = 0; i < size + 1; i++)
        {
            delete[] array2d[i];
        }

        delete[] array2d;
    }
    return 0;
}