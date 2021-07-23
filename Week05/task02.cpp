#include <iostream>

int main()
{
    const int FIB_NUM_1 = 1;
    const int FIB_NUM_2 = 1;
    
    int f1 = FIB_NUM_1, f2 = FIB_NUM_2;

    std::cout << FIB_NUM_1 << " " << FIB_NUM_2 << " ";

    for (int i = 0; i < 11; i++)
    {
        int fibNext = f1 + f2;

        std::cout << fibNext << " ";

        f1 = f2;
        f2 = fibNext;
    }

    return 0;
}