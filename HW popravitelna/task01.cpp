#include <iostream>

// Dynamic array functions

/**
     * @brief Function to dynamically allocate an array of ints with given size
     * @param size: Size of array to be allocated
     * @return: Pointer to the allocated array or nullptr if allocation was no successful
     */
unsigned int *allocate(int size)
{
    unsigned int *result = new (std::nothrow) unsigned int[size];
    if (!result)
    {
        std::cout << "Memory allocation problem" << std::endl;
        return nullptr;
    }

    return result;
}

/**
     * @brief Function to  deallocate dynamically allocated array of ints
     */
void clear(unsigned int *arr)
{
    delete[] arr;
}

/**
     * @brief Function enter the elements of array
     * @param arr: The array
     * @param size: Size of array 
     */
void input(unsigned int *arr, int size)
{
    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        unsigned int temp;
        std::cin >> temp;
        do
        {
            if (!std::cin)
            {
                std::cout << "Enter positive number: ";
                std::cin >> temp;
            }
        } while (!std::cin);

        arr[i] = temp;
    }
}

/**
     * @brief Recursive function to print the elements of an array
     * @param arr: The array
     * @param size: Size of array 
     * @param pos: Position of element to print
     */
void print(unsigned int *arr, int size, int &pos)
{
    if (pos == size)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << arr[pos] << " ";
    pos++;
    print(arr, size, pos);
}

//Helper functions

/**
     * @brief Function to count the 1 bits in even and odd positions in a numvber
     * @param num: The anumber
     * @param evenPositions: Amount of 1 bits in even positions
     * @param oddPositions: Amount of 1 bits in odd positions
     */
void count1s(unsigned int num, int &evenPositions, int &oddPositions)
{
    evenPositions = 0;
    oddPositions = 0;
    int tempEven = num;
    int tempOdd = num >> 1;

    while (tempEven)
    {
        if (tempEven & 1)
        {
            evenPositions++;
        }
        tempEven = (tempEven >> 2);
    }

    while (tempOdd)
    {
        if (tempOdd & 1)
        {
            oddPositions++;
        }
        tempOdd = (tempOdd >> 2);
    }
}
/**
     * @brief Function to swap two ints
     * @param a: First int
     * @param b: Second int
     */
void swap(unsigned int &a, unsigned int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/**
     * @brief Function to remove an element at a certain position from an array
     * @param arr: The array
     * @param size: Size of array 
     * @param pos: Position at which element is to be deleted
     */
void removeAtPosition(unsigned int *arr, int size, int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

//Required functions

/**
     * @brief Function to decide if the first number is smaller by bits than the second one
     * @param num1: First number
     * @param num2: Second number
     * @param areEqual: Stores whether the numbers have equal amount of 1 bits at odd and even positions
     * @return True if first number is smaller by bits
     */
bool isNumberSmallerByBits(unsigned int num1, unsigned int num2, bool &areEqual)
{
    int cntEven1, cntOdd1, cntEven2, cntOdd2;

    count1s(num1, cntEven1, cntOdd1);
    count1s(num2, cntEven2, cntOdd2);

    if (cntEven1 == cntEven2 && cntOdd1 == cntOdd2)
    {
        areEqual = true;
    }

    return ((cntEven1 < cntEven2) || (cntEven1 == cntEven2 && cntOdd1 < cntOdd2));
}

/**
     * @brief Function to sort the elements of an array 
     * @param arr: The array
     * @param size: Size of array 
     */
void sort(unsigned int *arr, int size)
{
    bool isSorted = true;
    bool boolForFunc = false;
    int start = 0;

    do
    {
        isSorted = true;
        for (int i = size - 1; i > start; i--)
        {
            if (!isNumberSmallerByBits(arr[i], arr[i - 1], boolForFunc))
            {
                swap(arr[i], arr[i - 1]);
                isSorted = false;
            }
        }

        start++;

    } while (!isSorted);
}

/**
     * @brief Function to remove equal (by the given by the task criteria) elements of an array
     * @param arr: The array
     * @param size: Size of array 
     */
void removeEquals(unsigned int *arr, int &size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            bool equal = false;
            if (!isNumberSmallerByBits(arr[i], arr[j], equal))
            {
                if (equal)
                {
                    removeAtPosition(arr, size, j);
                    size--;
                    j--;
                    removeAtPosition(arr, size, i);
                    size--;
                    i--;
                }
            }
        }
    }
}

int main()
{
    int n, size;

    std::cout << "Enter size of array: ";
    std::cin >> n;
    
    if (!std::cin)
    {

        std::cout << "Invalid user input. You should enter a number." << std::endl;
        return -2;
    }
    if (n <= 0)
    {
        do
        {
            std::cout << "Size should be > 0. Try again." << std::endl;
            std::cout << "Size: ";
            std::cin >> n;
        } while (n <= 0);
    }

    size = n;
    unsigned int *numbers = allocate(size);
    if (!numbers)
    {
        return -1; //mark that the allocation has failed, the above function returns nullptr if that's the case
    }
    input(numbers, size);

    int startingIdx = 0;
    std::cout << "Sorted array: ";
    sort(numbers, size);
    print(numbers, size, startingIdx);

    startingIdx = 0;
    std::cout << "Removed equals: ";
    removeEquals(numbers, size);
    print(numbers, size, startingIdx);

    clear(numbers);

    return 0;
}