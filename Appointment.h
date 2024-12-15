//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Date.h"
#include <iomanip>

class Appointment {
private:
    bool is_available;
    string drId, ptId, time, date;

public:
    Appointment();
    Appointment(string d, string dr, string pt, string t, bool is_av);
    void set_is_available(bool x) {is_available = x;}
    bool get_is_available() const {return is_available;}
    string getTime() const {return time;}
    void print () const;
    string get_date() const {return date;}
    string get_drId() const {return drId;}
    bool get_is_Available() const {return is_available;}
    string get_ptId() const {return ptId;}
    string set_ptId(string ptId) {this->ptId = ptId;}
    void print_for_patient() const;

};


#endif //APPOINTMENT_H
