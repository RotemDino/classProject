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


#define STARTHOUR  10:00
#define ENDHOUR 12:00
vector <Doctor> doctors;
vector <Patient> patients;
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
                        // 1
                        fstream file1("Appointments.txt", ios::app);
                        if (file1.is_open()) {
                            file1 << dateTXT << endl;             // Date of appointment
                            file1 << "10:00" << endl;            // Appointment start time
                            file1 << selectedDoctorId << endl;  // Random doctor's ID
                            file1 << id << endl;
                            file1 << is_booked << endl;
                            file1 << "----------------------------------" << endl;
                            // 2
                            srand(time(0));
                            int randomIndex2 = rand() % id_doctors.size();
                            long selectedDoctorId2 = id_doctors[randomIndex2];

                            file1 << dateTXT << endl;             // Date of appointment
                            file1 << "10:30" << endl;            // Appointment start time
                            file1 << selectedDoctorId2 << endl;  // Random doctor's ID
                            file1 << id << endl;
                            file1 << is_booked << endl;
                            file1 << "----------------------------------" << endl;
                            // 3
                            srand(time(0));
                            int randomIndex3 = rand() % id_doctors.size();
                            long selectedDoctorId3 = id_doctors[randomIndex3];

                            file1 << dateTXT << endl;             // Date of appointment
                            file1 << "11:00" << endl;            // Appointment start time
                            file1 << selectedDoctorId3 << endl;  // Random doctor's ID
                            file1 << id << endl;
                            file1 << is_booked << endl;
                            file1 << "----------------------------------" << endl;
                            // 4
                            srand(time(0));
                            int randomIndex4 = rand() % id_doctors.size();
                            long selectedDoctorId4 = id_doctors[randomIndex4];

                            file1 << dateTXT << endl;             // Date of appointment
                            file1 << "11:30" << endl;            // Appointment start time
                            file1 << selectedDoctorId4 << endl;  // Random doctor's ID
                            file1 << id << endl;
                            file1 << is_booked << endl;
                            file1 << "----------------------------------" << endl;

                        }
                        else {
                            cout << "Failed to open Appointments.txt for writing!" << endl;
                        }
                        file1.close();

                        cout << "The date is available! choose from these hours: 1 = 10:00 | 2 = 10:30 | 3 = 11:00 | 4 = 11:30" << endl;
                        cin >> choice;
                        string realID = to_string(id);
                        if (choice == 1) {
                            cout << "The appointment details are:" << endl;
                            ifstream file1("Appointments.txt");
                            string line;

                            while (getline(file1, line)) {
                                // Check if the line matches the date
                                if (line == dateTXT) {
                                    // Next line will be the time
                                    string time = "10:00";
                                    getline(file1, time);

                                    // Check if this is the 10:00 slot
                                    if (time == "10:00") {
                                        // Read and store the subsequent details
                                        string doctorId, patientId, isBooked;
                                        getline(file1, doctorId);  // Doctor ID
                                        getline(file1, patientId); // Patient ID
                                        getline(file1, isBooked);  // Booking status

                                        // Print the appointment details
                                        cout << "Date: " << dateTXT << endl;
                                        cout << "Time: " << time << endl;
                                        cout << "Doctor ID: " << doctorId << endl;
                                        cout << "Patient ID: " << patientId << endl;
                                        cout << "Booking Status: " << (isBooked == "1" ? "Not Booked" : "Booked") << endl;

                                        // Skip the separator line
                                        getline(file1, line);
                                        break;
                                    }
                                }
                            }
                            file1.close();
                        }
                        if (choice == 2) {
                            cout << "The appointment details are:" << endl;
                            ifstream file1("Appointments.txt");
                            string line;

                            while (getline(file1, line)) {
                                // Check if the line matches the date
                                if (line == dateTXT) {
                                    // Next line will be the time
                                    string time = "10:30";
                                    getline(file1, time);

                                    // Check if this is the 10:30 slot
                                    if (time == "10:30") {
                                        // Read and store the subsequent details
                                        string doctorId, patientId, isBooked;
                                        getline(file1, doctorId);  // Doctor ID
                                        getline(file1, patientId); // Patient ID
                                        getline(file1, isBooked);  // Booking status

                                        // Print the appointment details
                                        cout << "Date: " << dateTXT << endl;
                                        cout << "Time: " << time << endl;
                                        cout << "Doctor ID: " << doctorId << endl;
                                        cout << "Patient ID: " << patientId << endl;
                                        cout << "Booking Status: " << (isBooked == "1" ? "Not Booked" : "Booked") << endl;

                                        // Skip the separator line
                                        getline(file1, line);
                                        break;
                                    }
                                }
                            }
                            file1.close();
                        }
                        if (choice == 3) {
                            cout << "The appointment details are:" << endl;
                            ifstream file1("Appointments.txt");
                            string line;

                            while (getline(file1, line)) {
                                // Check if the line matches the date
                                if (line == dateTXT) {
                                    // Next line will be the time
                                    string time = "11:00";
                                    getline(file1, time);

                                    // Check if this is the 11:00 slot
                                    if (time == "11:00") {
                                        // Read and store the subsequent details
                                        string doctorId, patientId, isBooked;
                                        getline(file1, doctorId);  // Doctor ID
                                        getline(file1, patientId); // Patient ID
                                        getline(file1, isBooked);  // Booking status

                                        // Print the appointment details
                                        cout << "Date: " << dateTXT << endl;
                                        cout << "Time: " << time << endl;
                                        cout << "Doctor ID: " << doctorId << endl;
                                        cout << "Patient ID: " << patientId << endl;
                                        cout << "Booking Status: " << (isBooked == "1" ? "Not Booked" : "Booked") << endl;

                                        // Skip the separator line
                                        getline(file1, line);
                                        break;
                                    }
                                }
                            }
                            file1.close();
                        }
                        if (choice == 4) {
                            cout << "The appointment details are:" << endl;
                            ifstream file1("Appointments.txt");
                            string line;

                            while (getline(file1, line)) {
                                // Check if the line matches the date
                                if (line == dateTXT) {
                                    // Next line will be the time
                                    string time = "11:30";
                                    getline(file1, time);

                                    // Check if this is the 11:30 slot
                                    if (time == "11:30") {
                                        // Read and store the subsequent details
                                        string doctorId, patientId, isBooked;
                                        getline(file1, doctorId);  // Doctor ID
                                        getline(file1, patientId); // Patient ID
                                        getline(file1, isBooked);  // Booking status

                                        // Print the appointment details
                                        cout << "Date: " << dateTXT << endl;
                                        cout << "Time: " << time << endl;
                                        cout << "Doctor ID: " << doctorId << endl;
                                        cout << "Patient ID: " << patientId << endl;
                                        cout << "Booking Status: " << (isBooked == "1" ? "Not Booked" : "Booked") << endl;

                                        // Skip the separator line
                                        getline(file1, line);
                                        break;
                                    }
                                }
                            }
                            file1.close();
                        }
                    }
                    // display all the appointments who are not booked
                    ifstream file2("Appointments.txt");
                    string line2;
                    vector<string> availableAppointments;

                    while (getline(file2, line2)) {
                        // Check if the line matches the date
                        if (line2 == dateTXT) {
                            string time, doctorId, patientId, isBooked, separator;

                            // Read the next lines
                            getline(file2, time);        // Time
                            getline(file2, doctorId);    // Doctor ID
                            getline(file2, patientId);   // Patient ID
                            getline(file2, isBooked);    // Booking status
                            getline(file2, separator);   // Separator line

                            // Check if the appointment is not booked (isBooked == "0")
                            if (isBooked == "0") {
                                // Format the available appointment details
                                string availableAppointment = "Time: " + time +
                                                              ", Doctor ID: " + doctorId;
                                availableAppointments.push_back(availableAppointment);
                            }
                        }
                    }
                    file1.close();

                    // Print available appointments
                    if (availableAppointments.empty()) {
                        cout << "No available appointments on " << dateTXT << endl;
                    }
                    else {
                        cout << "Available appointments on " << dateTXT << ":" << endl;
                        for (const auto& appointment : availableAppointments) {
                            cout << appointment << endl;
                        }
                    }

                    cout << "what time would you like to schedule on appointment? " << endl;
                    string new_time;
                    cin >> new_time;


                }
            }
            else
                cout << "Password incorrect!" << endl;
        }
    }
}

int main (){
    // main menu
    main_menu();


    return 0;
}
