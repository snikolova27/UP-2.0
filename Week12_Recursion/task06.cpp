#include <iostream>

void printRow(char start, char end)
{
    if (start > end)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << start << " ";
    return printRow(start + 1, end);
}
void printTriangle(char start, char end)
{
    if (start > end)
    {
        return;
    }
    printRow(start, end);
    return printTriangle(start, end - 1);
}
int main()
{
    char endCh;
    std::cout << "Enter ending character: ";
    std::cin >> endCh;

    if (endCh < 'A' && endCh > 'Z')
    {
        std::cout << "Character should be a capital letter!" << std::endl;
        return -1;
    }
    printTriangle('A', endCh);
    return 0;
}