#include <iostream>

enum VALID_CODES
{
    OK,
    INVALID_MONTH,
    INVALID_DAY,
    INVALID_HOUR,
    INVALID_MINUTES,
    INVALID_SECONDS
};

int main()
{
    int year, month, day, hour, minutes, seconds;
    std::cin >> year >> month >> day >> hour >> minutes >> seconds;

    if (month < 0 || month > 12)
    {
        return INVALID_MONTH;
    }
    if (day < 1 || day > 31)
    {
        return INVALID_DAY;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return INVALID_DAY;
    }

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0 && year % 400 == 0) && day > 29)
        {
            return INVALID_DAY;
        }
        else if (day > 28)
        {
            return INVALID_DAY;
        }
    }

    if (hour < 0 || hour > 24)
    {
        return INVALID_HOUR;
    }

    if (minutes < 0 || minutes > 59)
    {
        return INVALID_MINUTES;
    }

    if (seconds < 0 || seconds > 59)
    {
        return INVALID_SECONDS;
    }

    return OK;
}
