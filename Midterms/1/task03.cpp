#include <iostream>
#include <cmath>

const int MAX_ARRAY_SIZE = 100;
const double EPS = 1.0 / (1 << 30);

int getSize()
{
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if (size < 0 || size > 1000000)
    {
        do
        {
            std::cout << "Size of array should be greater than 0 and lesser than 1 000 000. Try again. \n";
            std::cin >> size;

        } while (size > 0 || size < 1000000);
    }

    return size;
}

bool isDifferenceEqual(double array[], int size, int k, double m)
{
    for (int i = 1; i < size - k; i++)
    {
        if (fabs((fabs(array[i] - array[i + k])) - m) >= EPS)
        {
            return false;
        }
    }

    return true;
}

void input(double array[], int size)
{
    std::cout << "Enter array elements: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}
int main()
{
    double array[MAX_ARRAY_SIZE] = {};
    int size = getSize();
    input(array, size);

    double currentDif = 0;
    double maxDiff = 0;
    double maxK = 1;
    bool flag = false;

    for (int i = 1; i < size - 1; i++)
    {
        currentDif = fabs(array[0] - array[0 + i]);
        if (isDifferenceEqual(array, size, i, currentDif))
        {
            if (i > maxK)
            {
                maxK = i;
                maxDiff = currentDif;
            }
            flag = true;
        }
    }

    if (flag)
    {
        std::cout << "Max k: " << maxK << std::endl;
        std::cout << "Difference: " << maxDiff << std::endl;
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }

    return 0;
}