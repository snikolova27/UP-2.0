#include <iostream>

const int MAX_DAYS_IN_MONTH = 31;
const int DAYS_IN_MONTH = 30;
const int DAYS_IN_FEB_LEAP = 29;
const int DAYS_IN_FEB_NOT_LEAP = 28;
const int MIN_DAY_MONTH_YEAR = 1;

const int CNT_OF_MONTHS = 12;
const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

bool isLeap(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

bool isDateValid(int day, int month, int year)
{
    if (day <  MIN_DAY_MONTH_YEAR || day > MAX_DAYS_IN_MONTH || month > CNT_OF_MONTHS || month <  MIN_DAY_MONTH_YEAR || year <  MIN_DAY_MONTH_YEAR)
    {
        return false;
    }

    if (month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER)
    {
        if (day <  MIN_DAY_MONTH_YEAR || day > MAX_DAYS_IN_MONTH)
        {
            return false;
        }
    }

    else if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
    {
        if (day <  MIN_DAY_MONTH_YEAR || day > DAYS_IN_MONTH)
        {
            return false;
        }
    }

    else if (month == FEBRUARY && isLeap(year))
    {
        if (day <  MIN_DAY_MONTH_YEAR|| day > DAYS_IN_FEB_LEAP)
        {
            return false;
        }
    }
    else if (month == FEBRUARY && !isLeap(year))
    {
        if (day <  MIN_DAY_MONTH_YEAR || day > DAYS_IN_FEB_NOT_LEAP)
        {
            return false;
        }
    }

    return true;
}

int sumDigits(int num)
{
    int sum = 0;

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main()
{
    int day, month, year;
    std::cout << "Enter date: ";
    std::cin >> day >> month >> year;

    if (!isDateValid(day, month, year))
    {
        std::cout << "Invalid date!" << std::endl;
    }
    else
    {
        int sum = sumDigits(day) + sumDigits(month) + sumDigits(year);
        if (sum % 6 == 0)
        {
            std::cout << "Lucky!" << std::endl;
        }
        else
        {
            std::cout << "Not lucky!" << std::endl;
        }
    }

    return 0;
}