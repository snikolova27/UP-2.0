#include <iostream>

const int MAX_ARRAY_SIZE = 100;

int insertElements(int *array)
{
    int size;
    std::cout << "How many elements do you wish to enter? ";
    std::cin >> size;

    if (size > 0)
    {

        for (int i = 0; i < size; i++)
        {
            std::cin >> array[i];
        }
    }

    return size;
}

void removeAtPos(int *array, int &size, int pos)
{
    if (pos < size)
    {
        for (int i = pos; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        --size;
    }
}

int main()
{

    int numbers[MAX_ARRAY_SIZE] = {};
    int size = insertElements(numbers);

    int maxEncounters = 1;
    int mostEncountered = numbers[0];

    for (int i = 0; i < size; i++)
    {
        int cntr = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] == numbers[i])
            {
                cntr++;
                removeAtPos(numbers, size, j);
                --j;
            }
        }

        if (cntr > maxEncounters)
        {
            maxEncounters = cntr;
            mostEncountered = numbers[i];
        }
    }
    std::cout << "Most encountered is: " << mostEncountered << " " << maxEncounters << " times" << std::endl;

    return 0;
}