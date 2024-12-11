//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Date.h"

class Appointment {
private:
    Date* appointments;
    int size;
public:
    Appointment ();
    Appointment (Date* a, int s);
    ~Appointment();
    Date* getAppointments() const;
    Date* addAppointment (Date a);
    Date* removeAppointment (Date a);
    void printAppointments() const;
    int getSize() const;

};



#endif //APPOINTMENT_H
