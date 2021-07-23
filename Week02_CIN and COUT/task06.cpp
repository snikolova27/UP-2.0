#include <iostream>

const int MINUTES_IN_A_DAY = 1440;
int main()
{
    int hour, minutes, duration;

    std::cout << "Enter hour and minutes of flight: ";
    std::cin >> hour >> minutes;

    std::cout << "Enter duration of flight: ";
    std::cin >> duration;

    int startOfFlight = hour * 60 + minutes;
    int endOfFlight = startOfFlight + duration;

    if (endOfFlight > MINUTES_IN_A_DAY)
    {
        endOfFlight -= MINUTES_IN_A_DAY;
    }

    std::cout << "Arrival: " << endOfFlight / 60 << ":" << endOfFlight % 60 << std::endl;

    return 0;
}