//
// Created by Rotem Dino on 11/12/2024.
//

#include "Patient.h"

Patient::Patient() {
    disease = "";
}
Patient::Patient(string n, string g, long i, long a, string p, string d, string em) : Person(n, g, i, a, p, em) {
    disease = d;
}
Patient::~Patient() {
}
string Patient::getType() const {
    return "Patient";
}
long Patient::getId() const {
    return id;
}
string Patient::getPassword() const {
    return password;
}
