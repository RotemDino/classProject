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
    Patient(string n, string g, string i, string a, string p, string d, string em);
    ~Patient();
    string getId () const;
    string getPassword() const;
    string getName() const;
    string getGender() const;
    string getAge() const;
    string getEmail() const;
    string getDisease () const;
    void printPatient() const;
    void set_disease(string d) {disease += d;}
    void set_password(string p) {password = p;}


};
#endif //PATIENT_H
