#include <iostream>
#include <fstream>
#include "Appointment.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include <vector>

using namespace std;


// function to registrate a doctor
Doctor register_doctor() {

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

Patient register_patient() {

    // parameters
    string name;
    long id;
    string gender;
    int age;
    string password;
    string email;
    string disease;

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
    cout << "Enter your disease: ";
    cin >> disease;

    // inputting the user interface
    Patient patient(name,gender,id,age,password,disease,email);
    // returning the patient to main
    return patient;
}

int main () {


    // main menu

    cout << "~~~Welcome to the Patient Appointment System!~~~" << endl;
    cout << "Would you like to login or register to the system?" << endl;
    int choice;
    cout << "Enter your choice: | 1 = register | 2 = login " << endl;
    cin >> choice;
    if (choice == 1) {
        int choice2;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice2;
        if (choice == 1) { // insert the doctor in the file
            Doctor doc1 = register_doctor();
            fstream file;
            file.open("Doctors.txt", ios::app);
            if (file.is_open()) {
                file << doc1.getName()<<endl;
                file << doc1.getId() << endl;
                file << doc1.getGender() << endl;
                file << doc1.getAge() << endl;
                file << doc1.getPassword() << endl;
                file << doc1.getEmail() << endl;
                file << doc1.getSpecialization() << endl;
                file  << "----------------------------------" << endl;
            }
            file.close();
        }
        if (choice == 2) { // insert the patient in the file
            Patient patient1 = register_patient();
            fstream file;
            file.open("Patients.txt", ios::app);
            if (file.is_open()) {
                file << patient1.getName()<<endl;
                file << patient1.getId() << endl;
                file << patient1.getGender() << endl;
                file << patient1.getAge() << endl;
                file << patient1.getPassword() << endl;
                file << patient1.getEmail() << endl;
                file << patient1.getDisease() << endl;
                file  << "----------------------------------" << endl;
            }
            file.close();
        }
    }
    if (choice == 2) {
        int choice2;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice2;
        if (choice2 == 1) {
            string id,password;
            cout << "Enter your id: " << endl;
            cin >> id;
            cout << "Enter your password: " << endl;
            cin >> password;
            ifstream file("Doctors.txt");
            if (!file) {
                cout << "File does not exist!" << endl;
                return 1;
            }
            // First check for ID
            string line;
            bool idFound = false;
            while (getline(file, line)) {
                if (line == id) {
                    idFound = true;
                    break;
                }
            }
            if (!idFound) {
                cout << "ID not found!" << endl;
                file.close();
                return false;
            }
            // Reset file pointer to start checking for password
            file.clear(); // Clear EOF flag
            file.seekg(0, ios::beg);

            string filePassword;
            bool passwordFound = false;

            while (getline(file, line)) {
                if (line == password) {
                    passwordFound = true;
                    break;
                }
            }
            file.close();

            // Both ID and password must match
            if (idFound && passwordFound) {
                cout << "Logged in successfully!" << endl;
            } else {
                cout << "Password incorrect!" << endl;
            }
        }
    }




    // Doctor doc1 = register_doctor();
    // fstream file;
    // file.open("Doctors.txt", ios::app);
    // if (file.is_open()) {
    //     file << doc1.getName()<<endl;
    //     file << doc1.getId() << endl;
    //     file << doc1.getPassword() << endl;
    //     file  << "----------------------------------" << endl;
    // }
    // file.close();
    //
    // ifstream MyReadFile("Doctors.txt");
    // while (getline(MyReadFile,)) {
    //
    // }





    // ofstream myFile ("Doctors.txt");
    // myFile << "Doctor name: Dr. Rotem Dino, id: 123456789, age: 20" << endl;
    // myFile.close();




    return 0;
}
