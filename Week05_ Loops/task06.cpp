#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int cnt = 0;

    while(num > 0 )
    {
        if(num % 2 == 0)
        {
            cnt++;
        }
        std::cin >> num;
    }

    std::cout << "Count of positive even numbers: " << cnt << std::endl;
    return 0;
}