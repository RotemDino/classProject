//
// Created by Rotem Dino on 11/12/2024.
//

#include "Person.h"

Person::Person() {
    name = "";
    id = 0;
    gender = "";
    age = 0;
    password = 0;
}
Person::Person(string n, string g, long i, long a, long p) {
    name = n;
    gender = g;
    id = i;
    age = a;
    password = p;
}
Person::~Person() {
}

