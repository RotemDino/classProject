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
    float totalRating;
    int ratingCount;

    static int ratings;


public:
    Doctor ();
    Doctor(string n, string g, string i, string a, string p, string s, string r, string em);
    ~Doctor();
    string getId() const;
    string getPassword() const;
    string getSpecialization() const;
    string getName() const;
    string getGender() const;
    string getAge() const;
    string getEmail() const;
    string getRate() const {return rate;}
    void setId(string x) { id = x;}
    void setPassword(string x) {password = x;}
    void setSpecialization(string x) {specialization = x;}
    void setName(string x) {name = x;}
    void setGender(string x) {gender = x;}
    void setAge(string x) {age = x;}
    void setEmail(string x) {email = x;}
    void printDoctors() const;
    void set_rate(int newRating);
    float getAverageRating() const;
};



#endif //DOCTOR_H
