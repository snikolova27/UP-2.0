#include <iostream>

typedef bool (*restrictionFunc)(int);

bool isOfAge(int age)
{
    return age >= 18;
}

bool isATeenager(int age)
{
    return age >= 14 && age <= 18;
}

bool any_of(int *array, int size, restrictionFunc restriction)
{
    for (int i = 0; i < size; i++)
    {
        if (restriction(array[i]))
        {
            return true;
        }
    }
    return false;
}

bool all_of(int *array, int size, restrictionFunc restriction)
{
    for (int i = 0; i < size; i++)
    {
        if (!restriction(array[i]))
        {
            return false;
        }
    }

    return false;
}

int main()
{
    int ages[10] = {0, 12, 54, 18, 78, 20, 18, 42, 36, 21};
    std::cout << std::boolalpha << all_of(ages, 10, isOfAge) << std::endl;
    std::cout << std::boolalpha << any_of(ages, 10, isATeenager) << std::endl;
    return 0;
}