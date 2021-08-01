#include <iostream>

double calculateExprHelper(double x, int n, double y, int i)
{
    if (i > n)
    {
        return y;
    }
    return calculateExprHelper(x, n, y * x + i, i + 1);
}
double calculateExpr(double x, int n)
{
    return calculateExprHelper(x, n, 1, 2);
}
int main()
{
    double x;
    int n;
    std::cout << "Enter x:";
    std::cin >> x;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << calculateExpr(x, n) << std::endl;
    return 0;
}