//
// Created by Rotem Dino on 11/12/2024.
//

#include "Doctor.h"
#include <bits/stdc++.h>


Doctor::Doctor() : Person() {
    specialization = "";
    rate = "0";
}
Doctor::Doctor(string n, string g, string i, string a, string p, string s, string r, string em) : Person(n, g, i, a, p, em) {
    specialization = s;
    rate = r;
    ratings++;
}
Doctor::~Doctor() {
}
string Doctor::getType() const {
    return "Doctor";
}
string Doctor::getId() const {
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
string Doctor::getAge() const {
    return age;
}
string Doctor::getEmail() const {
    return email;
}

void Doctor::printDoctors() const {
    cout << name << endl;
    cout << id << endl;
    cout << gender << endl;
    cout << age << endl;
    cout << password << endl;
    cout << email << endl;
    cout << specialization << endl;
    cout << "----------------------------------" << endl;
}

float Doctor::set_rate(int x) {
    float temp = stof(rate);
    temp += x;
    return temp / ratings;
}

