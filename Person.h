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
    long id;
    string gender;
    int age;
    string password;
    string email;
public:
    Person();
    Person(string n, string g, long i, long a, string p, string em);
    virtual ~Person();
    virtual string getType() const = 0;
    virtual long getId () const = 0;
    virtual string getPassword() const = 0;

};



#endif //PERSON_H
