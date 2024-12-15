//
// Created by Rotem Dino on 11/12/2024.
//

#include "Patient.h"

Patient::Patient() {
    disease = "";
}
Patient::Patient(string n, string g, string i, string a, string p, string d, string em) : Person(n, g, i, a, p, em) {
    disease = d;
}
Patient::~Patient() {
}
string Patient::getId() const {
    return id;
}
string Patient::getPassword() const {
    return password;
}
string Patient::getName() const {
    return name;
}
string Patient::getGender() const {
    return gender;
}
string Patient::getAge() const {
    return age;
}
string Patient::getEmail() const {
    return email;
}
string Patient::getDisease() const {
    return disease;
}

void Patient::printPatient() const {
    cout << name << endl;
    cout << id << endl;
    cout << gender << endl;
    cout << age << endl;
    cout << password << endl;
    cout << email << endl;
    cout << disease << endl;
    cout << "----------------------------------" << endl;
}



