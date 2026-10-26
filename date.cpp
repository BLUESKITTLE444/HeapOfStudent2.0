#include "date.h"
#include <sstream>

Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
}

Date::Date(int month, int day, int year)
{
    this->month = month;
    this->day = day;
    this->year = year;
}

std::string Date::toString()
{
    std::string months[] =
    {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    std::stringstream sout;

    sout << months[month]
         << " "
         << day
         << ", "
         << year;

    return sout.str();
}
