#include <iostream>

int main()
{
    double len, height, a;
    std::cin >> len >> height >> a;

    double area = len * height;
    std::cout << area / a << " buckets needed";
    return 0;
}