#include <iostream>

int main()
{
    int lenght, width;

    std::cout << "Enter lenght and width of rectangle: ";
    std::cin >> lenght >> width;

    std::cout << "Area of rectangle: " << lenght * width << std::endl;
    std::cout << "Perimeter of rectangle: " << 2 * (lenght + width) << std::endl;
   
    return 0;
}