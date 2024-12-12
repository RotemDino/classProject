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

void displayWelcomeMessage() { // prints the welcome page
    string line = "=======================================================";
    string message = " Welcome to the Patient and Doctor appointment System! ";

    cout << line << endl;
    cout << message;
    cout << endl;
    cout << line << endl;

    cout <<endl;

}

bool main_menu() {
    displayWelcomeMessage();

    cout << "Would you like to login or register to the system?" << endl;
    int choice;
    cout << "Enter your choice: | 1 = register | 2 = login " << endl;
    cin >> choice;

    if (choice == 1) { // if the user chooses to register
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice;
        if (choice == 1) { // if the user decided to register as a doctor
            Doctor doc1 = register_doctor();
            fstream file;
            file.open("Doctors.txt", ios::app);
            if (file.is_open()) { // inputs all the information from the doctor object into the file
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

        if (choice == 2) { // if the user decided to register as a patient
            Patient patient1 = register_patient();
            fstream file;
            file.open("Patients.txt", ios::app);
            if (file.is_open()) { // inputs all the information from the patient object into the file
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

    if (choice == 2) { // // if the user chooses to log in
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice;

        if (choice == 1) { // if the user decided to log in as a doctor
            string id,password;
            cout << "Enter your id: " << endl;
            cin >> id;
            cout << "Enter your password: " << endl;
            cin >> password;
            ifstream file("Doctors.txt");
            if (!file) {
                cout << "File does not exist!" << endl;
                return false;
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
            }
            else {
                cout << "Password incorrect!" << endl;
            }
        }

        if (choice == 2) { // if the user decided to log in as a patient
            string id,password;
            cout << "Enter your id: " << endl;
            cin >> id;
            cout << "Enter your password: " << endl;
            cin >> password;
            ifstream file("Patients.txt");

            if (!file) {
                cout << "File does not exist!" << endl;
                return false;
            }

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
            file.clear();
            file.seekg(0, ios::beg);
            string filePassword;
            bool passwordFound = false;
            while (getline(file, line)) {
                if (line == password) {
                    passwordFound = true;
                    break;
                }
            }
            if (!passwordFound) {
                cout << "Password incorrect!" << endl;
                file.close();
                return false;
            }
            file.close();
            if (idFound && passwordFound)  // Ignore the warning the if condition works as intended
                cout << "Logged in successfully!" << endl;
            else
                cout << "Password incorrect!" << endl;
        }
    }
}


int main () {
    // main menu
    main_menu();

    return 0;
}
