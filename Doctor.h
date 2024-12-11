//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {
private:
    string specialization;
public:
    Doctor ();
    Doctor(string n, string g, long i, long a, long p, string s);
    ~Doctor();
    string getType() const;
    long getId () const;
    long getPassword() const;


};



#endif //DOCTOR_H
