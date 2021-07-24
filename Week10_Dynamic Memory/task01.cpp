#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b;
    std::cout << "Enter two numebrs to be swapped: ";
    std::cin >> a >> b;

    swap(&a, &b);

    std::cout << a << " " << b << std::endl;

    return 0;
}