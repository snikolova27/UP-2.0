#include <iostream>

int main()
{
    char ch;
    std::cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
    {
        std::cout << "Letter must be lower case, sorry" << std::endl;
    }
    else
    {
        std::cout << char(ch + 1) << std::endl;
    }
    return 0;
}