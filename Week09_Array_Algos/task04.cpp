#include <iostream>

const int MAX_ARRAY_SIZE = 100;

void input(int array[], int size)
{
    std::cout << "Enter array elements: \n";

    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void mostEncountered(int array[], int size)
{
    int resIdx;
    int cnt = 0;
    for (int j = 0; j < size; j++)
    {
        int mostEncEl = array[j];
        int mostEncIdx = j;
        int encCnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (mostEncEl == array[i])
            {
                encCnt++;
            }
        }
        if (encCnt > cnt)
        {
            cnt = encCnt;
            resIdx = j;
        }
    }

    std::cout << "Most encountered element is: " << array[resIdx] << " " << cnt << " times" << std::endl;
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
        mostEncountered(array, size);
    }

    else
    {
        std::cout << "Size should be greater than 0 and less than 100!" << std::endl;
    }
    return 0;
}