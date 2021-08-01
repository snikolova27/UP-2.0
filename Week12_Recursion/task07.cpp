#include <iostream>

void generateAllCombinations(char *str, int pos, int size)
{
    if (pos == size)
    {
        str[pos] = '\0';
        std::cout << str << " " << std::endl;
        return;
    }

    if (str[pos - 1] == '1')
    {
        str[pos] = '0';
        generateAllCombinations(str, pos + 1, size);
    }
    if (str[pos - 1] == '0')
    {
        str[pos] = '0';
        generateAllCombinations(str, pos + 1, size);
        str[pos] = '1';
        generateAllCombinations(str, pos + 1, size);
    }
}

void generateStrings(int size)
{
    if (!size)
    {
        return;
    }

    char str[size];

    str[0] = '0';
    generateAllCombinations(str, 1, size);

    str[0] = '1';
    generateAllCombinations(str, 1, size);
}

int main()
{
    int n;
    std::cout << "N: ";
    std::cin >> n;

    generateStrings(n);
    return 0;
}