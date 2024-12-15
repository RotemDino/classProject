//
// Created by Rotem Dino on 11/12/2024.
//

#include "Date.h"
#include <iostream>
using namespace std;


Date:: Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date:: Date (int d, int m, int y)
{
    day = d;
    month = m;
    year = y;

}
Date::~Date()
{
}
void Date::printDate() const
{
    if ( day <= 9 )
        cout << '0' << day << "/";
    else
        cout << day << "/";
    if ( month <= 9 )
        cout << '0' << month << "/" << year << ", ";
    else
        cout << month << "/" << year << ", ";
}
bool Date::operator == (const Date &d) const {
    return day == d.day && month == d.month && year == d.year;
}
bool Date::operator < (const Date &d) const {
    if (year < d.year)
        return true;
    if (year == d.year && month < d.month)
        return true;
    if ( year == d.year && month == d.month && day < d.day )
        return true;
    return false;
}

string Date::get_Date() const {
    return to_string(day) + to_string(month) + to_string(year);
}

