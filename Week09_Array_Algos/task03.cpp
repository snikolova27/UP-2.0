#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void input(int array[], int size)
{
    std::cout << "Enter elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void removeAtPos(int array[], int size, int pos)
{
    for (int i = pos ; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = -1;
}

int main()
{
    int array[MAX_ARRAY_SIZE] = {};
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size > 0 && size < MAX_ARRAY_SIZE)
    {
        input(array, size);

        int pos;
        std::cout << "Enter position at which an element should be deleted: ";
        std::cin >> pos;

        if (pos < size)
        {
            removeAtPos(array, size, pos);
            print(array, size);
        }
        else
        {
            std::cout << "Position cannot be greater than size of the array!" << std::endl;
        }
    }

    else
    {
        std::cout << "Size should be greater than 0 and less than 100." << std::endl;
    }
}