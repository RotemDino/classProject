#include <iostream>
#include <fstream>
#include "Appointment.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"

using namespace std;


// function to registrate a doctor
Doctor regis_doc() {

    // parameters
    string name;
    long id;
    string gender;
    int age;
    string password;
    string email;
    string special;
    bool is_av = true;
    int rate = 0;
    int size = 0;
    Appointment* appointment = nullptr;

    // user interface
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your special: ";
    cin >> special;

    // inputting the user information
    Doctor doctor(name,gender,id,age,password,special,is_av,rate,email,appointment,size);
    // returning the doctor to main
    return doctor;
}

int main () {
    Person** practice = NULL;





    // ofstream myFile ("Doctors.txt");
    // myFile << "Doctor name: Dr. Rotem Dino, id: 123456789, age: 20" << endl;
    // myFile.close();

    return 0;
}
