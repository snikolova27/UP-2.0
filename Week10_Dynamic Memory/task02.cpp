#include <iostream>

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

int *createArray(int size)
{
    int *array = new (std::nothrow) int[size];

    if (array != nullptr)
    {
        return array;
    }
    else
    {
        std::cout << "Couldn't allocate needed memory." << std::endl;
        return nullptr;
    }
}

void input(int *array, int size)
{
    std::cout << "Enter elements of array: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

int main()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size)
    {
        int *array = createArray(size);
        if (array)
        {
            input(array, size);
            print(array, size);
            delete[] array;
        }
    }
    
    else
    {
        std::cout << "Size cannot be less than or equal to 0!" << std::endl;
    }
    return 0;
}