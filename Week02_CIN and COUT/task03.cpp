#include <iostream>

int main()
{
    const float PI = 3.1415;

    float radius;
    std::cin >> radius;

    std::cout << "Lenght needed: " << 2 * PI * radius << std::endl;
    
    return 0;
}