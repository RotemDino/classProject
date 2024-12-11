//
// Created by Rotem Dino on 11/12/2024.
//

#include "Doctor.h"


Doctor::Doctor() : Person() {
    specialization = "";
}
Doctor::Doctor(string n, string g, long i, long a, long p, string s) : Person(n, g, i, a, p) {
    specialization = s;
}
Doctor::~Doctor() {
}
string Doctor::getType() const {
    return "Doctor";
}
long Doctor::getId() const {
    return id;
}
long Doctor::getPassword() const {
    return password;
}
