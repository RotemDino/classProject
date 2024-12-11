//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"


class Patient : public Person {
private:
    string disease;
public:
    Patient ();
    Patient(string n, string g, long i, int a, string p, string d, string em);
    ~Patient();
    string getType() const;
    long getId () const;
    string getPassword() const;
    string getName() const;
    string getGender() const;
    int getAge() const;
    string getEmail() const;
    string getDisease () const;


};
#endif //PATIENT_H
