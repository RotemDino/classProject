//
// Created by Rotem Dino on 11/12/2024.
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include "Appointment.h"

class Doctor : public Person {
private:
    string specialization;
    bool isAvailable;
    int rate;
public:
    Doctor ();
    Doctor(string n, string g, long i, long a, string p, string s, bool av, int r, string em);
    ~Doctor();
    string getType() const;
    long getId () const;
    string getPassword() const;
    string getSpecialization() const;
    string getName() const;
    string getGender() const;
    long getAge() const;
    string getEmail() const;
    bool IsAvailable() const {return isAvailable;}




};



#endif //DOCTOR_H
