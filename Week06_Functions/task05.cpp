#include <iostream>
const int CNT_OF_ROWS_TO_SKIP = 2;

int main()
{
    int m, n;
    std::cout << "Enter two numbers m and n ( m -> count of stars, n -> count of squares): ";
    std::cin >> m >> n;

    //first row
    for (int i = 0; i < (m + (n - 1) * (m - 1)); ++i)
    {
        std::cout << "* ";
    }

    std::cout << std::endl;

    for (int j = 0; j < m - CNT_OF_ROWS_TO_SKIP; j++)
    {
        for (int i = 0; i < (m + (n - 1) * (m - 1)); ++i)
        {
            if (i % (m - 1) == 0)
            {
                std::cout << "* ";
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    
    //last row
    for (int i = 0; i < (m + (n - 1) * (m - 1)); ++i)
    {
        std::cout << "* ";
    }

    return 0;
}