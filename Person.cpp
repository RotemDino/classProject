//
// Created by Rotem Dino on 11/12/2024.
//

#include "Person.h"

Person::Person() {
    name = "";
    id = "";
    gender = "";
    age = "0";
    password = "";
    email = "";
}
Person::Person(string n, string g, string i, string a, string p, string em) {
    name = n;
    gender = g;
    id = i;
    age = a;
    password = p;
    email = em;
}
Person::~Person() {
}

