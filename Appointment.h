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

public:
    Appointment();
    void set_is_available(bool x) {is_available = x;}
    bool get_is_available() const {return is_available;}






};


#endif //APPOINTMENT_H
