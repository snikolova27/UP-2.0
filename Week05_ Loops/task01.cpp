#include <iostream>

int main()
{
    int cntOfEvenNums = 20;

    for (int i = 2;; i += 2)
    {
        if (cntOfEvenNums == 0)
        {
            break;
        }

        std::cout << i << " ";
        cntOfEvenNums--;
    }
    std::cout << std::endl;

    int cnt = 1, num = 2;
    while (cnt <= 20)
    {
        std::cout << num << " ";
        num += 2;
        cnt++;
    }
    std::cout << std::endl;

    return 0;
}