#include <iostream>

// Dynamic array functions
int *allocate(int size)
{
    int *result = new (std::nothrow) int[size];
    if (!result)
    {
        std::cout << "Memory allocation problem" << std::endl;
        return nullptr;
    }

    return result;
}

void clear(int *arr)
{
    delete[] arr;
}

void input(int *arr, int size)
{
    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void print(int *arr, int size, int &pos)
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
void count1s(int num, int &evenPositions, int &oddPositions)
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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void removeAtPosition(int *arr, int size, int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

//Required functions
bool isNumberSmallerByBits(int num1, int num2, bool &areEqual)
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

void sort(int *arr, int size)
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

void removeEquals(int *arr, int &size)
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

    do
    {
        std::cout << "Enter size of array: ";
        std::cin >> n;

        if (n <= 0)
        {
            std::cout << "Size should be > 0. Try again." << std::endl;
            std::cout << "Size: ";
            std::cin >> n;
        }

    } while (n <= 0);

    size = n;
    int *numbers = allocate(size);
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