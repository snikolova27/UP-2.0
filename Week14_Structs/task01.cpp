#include <iostream>
#include <cmath>
struct Point
{
    int x;
    int y;
};

double distanceToCenter(Point point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

double distanceBetweeenPoints(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
int main()
{
    Point first, second;
    std::cout << "Enter coordinates of first point: ";
    std::cin >> first.x >> first.y;
    std::cout << "Enter coordinates of second point: ";
    std::cin >> second.x >> second.y;
    std::cout << "Distance to center of first point: " << distanceToCenter(first) << std::endl;
    std::cout << "Distance to center of second point: " << distanceToCenter(second) << std::endl;
    std::cout << "Distance between the two points: " << distanceBetweeenPoints(first, second) << std::endl;
}