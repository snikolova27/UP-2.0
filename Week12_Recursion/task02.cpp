#include <iostream>

const int MAX_STR_LEN = 2000;

int strlen(const char *str, int len)
{
    if (str[len])
    {
        return strlen(str, len + 1);
    }
    return len;
}

int main()
{
    char buffer[MAX_STR_LEN] = {};
    std::cout << "Enter string: ";
    std::cin.getline(buffer, MAX_STR_LEN);

    int len = strlen(buffer, 0);
    std::cout << len << std::endl;
    return 0;
}