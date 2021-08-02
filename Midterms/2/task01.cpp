#include <iostream>

const int MAX_ARRAY_SIZE = 1000;

void print(const int *arr, int size, int pos)
{
    if (pos == size)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << arr[pos] << " ";
    print(arr, size, pos + 1);
}

bool isSorted(const int *arr, int size, int pos, bool areEqual)
{
    if (pos == size && !areEqual)
    {
        return true;
    }
    if (arr[pos] != arr[pos - 1])
    {
        areEqual = false;
    }
    if (arr[pos] < arr[pos - 1])
    {
        return false;
    }
    return isSorted(arr, size, pos + 1, areEqual);
}

int findPos(int *arr, int size, int element, int pos)
{
    if (size == 0)
    {
        return pos;
    }
    if (element < arr[pos])
    {
        return pos;
    }

    return findPos(arr, size, element, pos + 1);
}

void moveElByOnePos(int *arr, int size, int element, int pos)
{
    if (pos == size)
    {
        return;
    }
    arr[pos] = arr[pos - 1];

    return moveElByOnePos(arr, size, element, pos - 1);
}
void insertInSorted(int *arr, int size, int element)
{
    if (size == 0)
    {
        arr[0] = element;
    }
    else
    {
        int pos = findPos(arr, size, element, 0);
        moveElByOnePos(arr, size, element, size);
        arr[pos] = element;
    }
}
int main()
{
    int numbers[MAX_ARRAY_SIZE] = {};
    int size = 0;
    int el, n;

    std::cin >> n;
    if (!n)
    {
        std::cout << "Size should be greater than 0!" << std::endl;
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> el;
        insertInSorted(numbers, size, el);
        size++;
    }

    std::cout << std::boolalpha << isSorted(numbers, size, 1, true) << std::endl;

    print(numbers, size, 0);
    return 0;
}