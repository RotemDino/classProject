//
// Created by Rotem Dino on 11/12/2024.
//

#include "Appointment.h"
#include "Date.h"
Appointment::Appointment() {
    appointments = nullptr;
    size = 0;
}
Appointment::Appointment(Date* a, int s) {
    size = s;
    appointments = new Date [size];
    for (int i = 0; i < size; i++) {
        appointments[i] = a[i];
    }
}
Appointment::~Appointment() {
    delete [] appointments;
}
Date* Appointment::getAppointments() const {
    return appointments;
}
Date* Appointment::addAppointment(Date a) {
    Date* tmp = new Date [size + 1];
    for (int i = 0; i < size; i++) {
        tmp[i] = appointments[i];
    }
    delete [] appointments;
    tmp[size] = a;
    appointments = tmp;
    size++;
    return appointments;
}
Date* Appointment::removeAppointment(Date a) {
    Date* tmp = new Date [size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (appointments[i] != a) {
            tmp[j] = appointments[i];
            j++;
        }
    }
    delete [] appointments;
    appointments = tmp;
    size--;
    return appointments;
}
void Appointment::printAppointments() const {
    for (int i = 0; i < size; i++) {
        appointments[i].printDate();
    }
}
int Appointment::getSize() const {
    return size;
}
