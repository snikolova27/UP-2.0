//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Поправителен изпит - задачи
// 2021-08-18
//
// Име: Соня Николова Николова
// ФН:  82213
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
#include <new>

typedef bool(*predicatFunc)(int);

int *allocate(unsigned size)
{
    int *res = new (std::nothrow) int[size];
    if (!res)
    {
        return nullptr;
    }

    return res;
}

void clear(int *arr)
{
    delete[] arr;
}

void input(unsigned size, int *arr)
{
    std::cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void print(unsigned size, int *arr)
{
    std::cout << "Elements of array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

bool isEven(int num)
{
    return num % 2 == 0;
}

bool isDivisibleBy3(int num)
{
    return num % 3 == 0;
}

int cntTruePredicats(int *arr, unsigned size, predicatFunc funcs[], int cntPredicats)
{
    int cnt = 0;
    for (int i = 0; i < cntPredicats; i++)
    {
        bool isTrue = true;

        for (int j = 0; j < size; j++)
        {
            if (!(funcs[i](arr[j])))
            {
                isTrue = false;
            }
        }

        if (isTrue)
        {
            cnt++;
        }
    }

    return cnt;
}
int main()
{
    unsigned n;
    do
    {
        std::cout << "Enter count of elements:  ";
        std::cin >> n;

        if (!std::cin)
        {
            std::cout << "Should be a number" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else if (n <= 0)
        {
            std::cout << "Number should be greater than zero. Try again. \n";
            std::cout << "N: ";
            std::cin >> n;
        }
    } while (!std::cin || n <= 0);

    int *arr = allocate(n);
    if (!arr)
    {
        std::cout << "Problem allocating memory" << std::endl;
        return -1;
    }

    input(n, arr);
    print(n, arr);
    predicatFunc predicats[2] = {isEven, isDivisibleBy3};
    std::cout << "Count of predicats that are true for all elements:  " << cntTruePredicats(arr, n, predicats, 2) << std::endl;

    clear(arr);
    return 0;
}