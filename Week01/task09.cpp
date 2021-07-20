#include <iostream>

int main()
{
    char ch;
    std::cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
    {
        std::cout << char(ch + ('a' - 'A'));
    }
    else
    {
        std::cout << "Letter must be upper case, sorry" << std::endl;
    }
    return 0;
}