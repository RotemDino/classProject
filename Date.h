//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>;
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date ();
    Date ( int d, int m, int y );
    ~Date();
    void printDate () const;
    bool operator < (const Date &d) const;
    bool operator == (const Date &d) const;
    Date& operator = (const Date &d);
    friend ostream& operator << (ostream &os, const Date& d ) {
        if ( d.day <= 9 )
            os << '0' << d.day << "/";
        else
            os << d.day << "/";
        if ( d.month <= 9 )
            os << '0' << d.month << "/" << d.year << endl;
        else
            os << d.month << "/" << d.year << endl;
        return os;
    }
    string get_Date () const;


};



#endif //DATE_H
