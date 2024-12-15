//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string gender;
    string age;
    string password;
    string email;
public:
    Person();
    Person(string n, string g, string i, string a, string p, string em);
    virtual ~Person();
    virtual string getId () const = 0;
    virtual string getPassword() const = 0;

};



#endif //PERSON_H
