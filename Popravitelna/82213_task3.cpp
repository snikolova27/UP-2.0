//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Поправителен изпит - задачи
// 2021-08-18
//
// Име: Соня Николова Николова
// ФН:  82213
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
#include <new>
#include <cmath>

const double EPS = 1 / (1 << 30);
const double PI = 3.14;
struct Circle
{
    double x;
    double y;
    double radius;
};

Circle createCircle()
{
    Circle result;
    std::cout << "Enter coordinates of centre of the circle \n";
    std::cout << "X: ";
    std::cin >> result.x;
    std::cout << "Y: ";
    std::cin >> result.y;
    do
    {
        std::cout << "Enter radius of circle: ";
        std::cin >> result.radius;

        if (result.radius < 0)
        {
            std::cout << "Radius should be >=0" << std::endl;
        }
    } while (result.radius < 0);

    return result;
}

Circle *allocateArrayOfCircles(int size)
{
    Circle *array = new (std::nothrow) Circle[size];
    if (!array)
    {
        return nullptr;
    }
    return array;
}

void clear(Circle *array)
{
    delete[] array;
}

double *allocate(int size)
{
    double *array = new (std::nothrow) double[size];
    if (!array)
    {
        return nullptr;
    }
    return array;
}

void clear(double *array)
{
    delete[] array;
}

void input(Circle *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter circle #" << i + 1 << std::endl;
        array[i] = createCircle();
        std::cout << std::endl;
    }
}
// (4,2)   (5,6)
// distance = sqrt(( 5^2 - 4^2) + (6^2 - 2^2)      9 + 32
double distanceBetweenCentres(Circle first, Circle second)
{
    return sqrt((pow(second.x, 2.0) - pow(first.x, 2.0)) + (pow(second.y, 2.0) - pow(first.y, 2.0)));
}

double lenght(Circle circle)
{
    return circle.radius * PI * 2;
}

void calculateCircleLens(Circle *circles, int size, double *circleLens)
{
    for (int i = 0; i < size; i++)
    {
        circleLens[i] = lenght(circles[i]);
    }
}

bool isLonely(Circle *allCircles, int size, int posOfCurrentCircle)
{
    if (posOfCurrentCircle < 0 || posOfCurrentCircle > size) //out of bounds
    {
        return false;
    }

    double currentRadius = allCircles[posOfCurrentCircle].radius;

    bool lonelyFirst = false;
    bool lonelySecond = false;

    if (posOfCurrentCircle == 0)
    {
        lonelyFirst = true;
    }
    else
    {
        for (int i = 0; i < posOfCurrentCircle; i++)
        {
            if (distanceBetweenCentres(allCircles[posOfCurrentCircle], allCircles[i]) > currentRadius)
            {
                lonelyFirst = true;
            }
        }
    }

    if (posOfCurrentCircle == size - 1)
    {
        lonelySecond = true;
    }
    else
    {
        for (int i = posOfCurrentCircle + 1; i < size; i++)
        {
            if (distanceBetweenCentres(allCircles[posOfCurrentCircle], allCircles[i]) > currentRadius)
            {
                lonelySecond = true;
            }
        }
    }

    return lonelyFirst && lonelySecond;
}

void removeLonelyCircles(Circle *circles, int size, int &newSize)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (isLonely(circles, size, i))
        {
            newSize--;
            for (int j = i; j < size; j++)
            {
                circles[j] = circles[j + 1];
            }
        }
    }
}

int minFrom(double *circleLens, int from, int to)
{
    int min = from;
    for (int i = from + 1; i < to; i++)
    {
        if (circleLens[min] > circleLens[i])
        {
            min = i;
        }
    }

    return min;
}
void swap(Circle &first, Circle &second)
{
    Circle temp;
    temp.x = first.x;
    temp.y = first.y;
    temp.radius = first.radius;

    first.x = second.x;
    first.y = second.y;
    first.radius = second.radius;

    second.x = temp.x;
    second.y = temp.y;
    second.radius = temp.radius;
}

void selectionSort(Circle *circles, int size, double *circleLens)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = minFrom(circleLens, i, size);
        if (minIdx != i)
        {
            swap(circles[minIdx], circles[i]);
        }
    }
}

void print(Circle *circles, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Circle #" << i + 1 << std::endl;
        std::cout << "X: " << circles[i].x << std::endl;
        std::cout << "Y: " << circles[i].y << std::endl;
        std::cout << "Radius: " << circles[i].radius << std::endl;
        std::cout << std::endl;
    }
}

void printLens(double *lens, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Length of circle #" << i + 1 << "  " << lens[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int main()
{
    int cntCircles;

    do
    {
        std::cout << "Enter count of circles: ";
        std::cin >> cntCircles;

        if (cntCircles <= 0)
        {
            std::cout << "Should be greater than 0. Try again \n";
            std::cout << "Count: ";
            std::cin >> cntCircles;
        }
    } while (cntCircles <= 0);

    Circle *circles = allocateArrayOfCircles(cntCircles);
    if (!circles)
    {
        std::cout << "Problem while allocating memory for array of circles \n";
        return -1;
    }

    input(circles, cntCircles);

    double *lens = allocate(cntCircles);

    calculateCircleLens(circles, cntCircles, lens);
    printLens(lens, cntCircles);

    int newSize = cntCircles;
    selectionSort(circles, cntCircles, lens);
    removeLonelyCircles(circles, cntCircles, newSize);

    std::cout << "After sorting the circles by length and removing the lonely ones: \n";
    print(circles, newSize);

    clear(circles);
    clear(lens);

    return 0;
}