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
    string rate;

    static int ratings;


public:
    Doctor ();
    Doctor(string n, string g, string i, string a, string p, string s, string r, string em);
    ~Doctor();
    string getType() const;
    string getId() const;
    string getPassword() const;
    string getSpecialization() const;
    string getName() const;
    string getGender() const;
    string getAge() const;
    string getEmail() const;
    string getRate() const {return rate;}
    void printDoctors() const;
    float set_rate(int x);




};



#endif //DOCTOR_H
