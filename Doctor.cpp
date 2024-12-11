//
// Created by Rotem Dino on 11/12/2024.
//

#include "Doctor.h"


Doctor::Doctor() : Person() {
    specialization = "";
    isAvilable = true;
    rate = 0;
    size = 0;
    appointments = nullptr;
}
Doctor::Doctor(string n, string g, long i, long a, string p, string s, bool av, int r, string em, Appointment* app, int size) : Person(n, g, i, a, p, em) {
    specialization = s;
    isAvilable = av;
    rate = r;
    this->size = size;
    appointments = new Appointment [size];
    for (int i = 0; i < size; i++) {
        appointments[i] = app [i];
    }
}
Doctor::~Doctor() {
    delete [] appointments;
}
string Doctor::getType() const {
    return "Doctor";
}
long Doctor::getId() const {
    return id;
}
string Doctor::getPassword() const {
    return password;
}
string Doctor::getSpecialization() const {
    return specialization;
}
string Doctor::getName() const {
    return name;
}
string Doctor::getGender() const {
    return gender;
}
long Doctor::getAge() const {
    return age;
}
string Doctor::getEmail() const {
    return email;
}


