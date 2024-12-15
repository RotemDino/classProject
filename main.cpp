#include <iostream>
#include <fstream>
#include "Appointment.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include "Person.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>


#define STARTHOUR  10:00
#define ENDHOUR 12:00
vector <Doctor> doctors;
vector <Patient> patients;

using namespace std;

unordered_map<string, Appointment> loadAppointments() {
    unordered_map<string, Appointment> appointments;
    ifstream file("Appointments.txt");
    if (!file) {
        cout << "File does not exist!" << endl;
        return appointments;
    }

    string line;
    while (getline(file, line)) {
        // Read the date
        string date = line;

        // Read the time
        getline(file, line);
        string time = line;

        // Read the doctor ID
        getline(file, line);
        string doctorId = line;

        // Read the patient ID
        getline(file, line);
        string patientId = line;

        // Read the booking status
        getline(file, line);
        bool isBooked = line == "1";

        // Skip the separator line
        getline(file, line);

        // Create an appointment object
        Appointment appointment(date, doctorId, patientId, time, isBooked);

        // Store the appointment in the map
        appointments[patientId] = appointment;
    }
    file.close();
    return appointments;
}
unordered_map<string, Appointment> newAppointments = loadAppointments();

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
    Doctor doctor(name,gender,id,age,password,special,is_av,rate,email);
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
            doctors.push_back(doc1);
            fstream file;
            file.open("Doctors.txt", ios::app);
            if (file.is_open()) { // inputs all the information from the doctor object into the file
                file << doc1.getName()<<endl;
                file << 999 << doc1.getId() << endl;
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
            patients.push_back(patient1);
            fstream file;
            file.open("Patients.txt", ios::app);
            if (file.is_open()) { // inputs all the information from the patient object into the file
                file << patient1.getName()<<endl;
                file << 999 << patient1.getId() << endl;
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

            if (idFound && passwordFound) { // Doctor's first menu
                cout << "Logged in successfully!" << endl;
                cout << "-----------------------" << endl;
                cout << "Input the number from the menu you would like to choose from: " << endl;
                cout << "1. Enter doctor's menu" << endl;
                cout << "2. Enter patient's menu" << endl;
                cout << "3. Exit" << endl;
                cin >> choice;

                if (choice == 1) { // doctor's personal menu
                    cout << "Input the number from the menu you would like to choose from: " << endl;
                    cout << "1. View current appointments " << endl;
                    cout << "2. Block a certain date for an appointment " << endl;
                    cout << "3. Edit your profile " << endl;
                    cout << "4. Exit" << endl;
                    cin >> choice;
// NOT FINISHED ------------ NOT FINISHED ------------ NOT FINISHED ------------ NOT FINISHED ------------ NOT FINISHED ------------ NOT FINISHED ------------
                    if (choice == 1) { // prints all the lines from the appointment file
                        int d,m,y;
                        cout << "Enter a specific date to view your appointments: DD/MM/YEAR " << endl;
                        cin >> d >> m >> y;
                        Date date1(d,m,y);
                        ifstream file("Appointments.txt");
                        string line;
                        while (getline(file, line)) {

                        }
                    }
                    if (choice == 2) {
                        int d,m,y;
                        cout << "Enter a specific date in which you want to block: DD/MM/YEAR" << endl;
                        cin >> d >> m >> y;
                        Date date2(d,m,y);
                    }
                }

// NOT FINISHED ------------ NOT FINISHED ------------NOT FINISHED ------------NOT FINISHED ------------NOT FINISHED ------------NOT FINISHED ------------NOT FINISHED ------------

            }
            else {
                cout << "Password incorrect!" << endl;
            }
        }

        if (choice == 2) {
            // if the user decided to log in as a patient
            string password;
            long id;
            cout << "Enter your id: " << endl;
            cin >> id;
            string fullID = "999" + to_string(id);

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
                if (line == fullID) {
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
            if (idFound && passwordFound) {
                // Ignore the warning the if condition works as intended
                cout << "Logged in successfully!" << endl;
                cout << "-----------------------" << endl;
                cout << "Input the number from the menu you would like to choose from: " << endl;
                cout << "1. Schedule an appointment " << endl;
                cout << "2. Choose a " << endl;
                cin >> choice;

                if (choice == 1) {
                    int d, m, y;
                    cout << "Enter a specific date to schedule (DD MM YYYY): ";
                    cin >> d >> m >> y;

                    Date date1(d, m, y);
                    string dateTXT = date1.get_Date();
                    bool DateFound = false;

                    // Check if the date already exists in the file
                    ifstream file1("Appointments.txt");
                    string line;
                    while (getline(file1, line)) {
                        if (line == dateTXT) {
                            DateFound = true;
                            break;
                        }
                    }
                    file1.close();

                    vector<long> id_doctors;
                    ifstream file("Doctors.txt");
                    string line1;

                    while (getline(file, line1)) {
                        // Check if the line starts with "999"
                        if (line1.substr(0, 3) == "999") {
                            // Extract the ID by removing the "999" prefix
                            long doctorId = stol(line1.substr(3));
                            id_doctors.push_back(doctorId);
                        }
                    }

                    srand(time(0));
                    int randomIndex = rand() % id_doctors.size();
                    long selectedDoctorId = id_doctors[randomIndex];
                    bool is_booked = false;


                    // If the date is not found, schedule a new appointment
                    if (!DateFound) { // create a date in which he can view them
                        string choice1;
                        cout << "The date is available! choose from these hours: 10:00 | 10:30 | 11:00 | 11:30" << endl;
                        cin >> choice1;
                        //
                        // fstream file1("Appointments.txt", ios::app);
                        // if (file1.is_open()) {
                        //     file1 << dateTXT << endl;             // Date of appointment
                        //     file1 << choice1 << endl;            // Appointment start time
                        //     file1 << selectedDoctorId << endl;  // Random doctor's ID
                        //     file1 << id << endl;
                        //     file1 << is_booked << endl;
                        //     file1 << "----------------------------------" << endl;
                        // }
                        // else {
                        //     cout << "Failed to open Appointments.txt for writing!" << endl;
                        // }
                        // file1.close();
                        string realID = to_string(id);
                        for (auto& pair : newAppointments) {
                            if (pair.first == fullID && pair.second.getTime() == choice1) {
                                pair.second.set_is_available(false);
                            }
                        }
                    }
                }
            }
            else
                cout << "Password incorrect!" << endl;
        }
    }
}

int main () {
    // main menu
    main_menu();
    for (auto& pair : newAppointments) {
        pair.second.print();
    }
    cout << "Thank you for using our system!" << endl;
    return 0;
}

