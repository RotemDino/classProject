#include <iostream>
#include <fstream>
#include "Appointment.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

int Doctor::ratings = 0;

unordered_map<string, Doctor> loadDoctors() {
    unordered_map<string, Doctor> doctors;
    ifstream file("Doctors.txt");
    if (!file) {
        cerr << "Unable to open file" << endl;
        return doctors;
    }

    string line;
    while (getline(file, line)) {
        string name = line;

        getline(file, line);
        string id = line;

        getline(file, line);
        string gender = line;

        getline(file, line);
        string age = line;

        getline(file, line);
        string password = line;

        getline(file, line);
        string email = line;

        getline(file, line);
        string specialization = line;

        getline(file, line);
        string rate = line;

        getline(file, line);

        Doctor doctor(name,gender,id, age,password,specialization,rate,email);

        doctors[id] = doctor;
    }
    file.close();
    return doctors;
}
unordered_map<string, Patient> loadPatients() {
    unordered_map<string, Patient> patients;

    ifstream file("Patients.txt");
    string line;

    while (getline(file, line)) {
        string name = line;

        getline(file, line);
        string id = line;

        getline(file, line);
        string gender = line;

        getline(file, line);
        string age = line;

        getline(file, line);
        string password = line;

        getline(file, line);
        string email = line;

        getline(file, line);
        string disease = line;

        getline(file, line);

        Patient patient(name,gender,id,age,password,disease,email);

        patients[id] = patient;
    }
    file.close();
    return patients;
}
unordered_map<string, Appointment> loadAppointments() {
    unordered_map<string, Appointment> appointments;
    ifstream file("Appointments.txt");

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
unordered_map<string,Doctor> newDoctors = loadDoctors();
unordered_map<string,Patient> newPatients = loadPatients();

void saveDoctors(const unordered_map<string, Doctor>& doctors) {
    ofstream file("Doctors.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) {
        cerr << "Unable to open Doctors.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newDoctors) {
        const Doctor& doctor = pair.second;
        file << doctor.getName() << endl;
        file << doctor.getId() << endl;
        file << doctor.getGender() << endl;
        file << doctor.getAge() << endl;
        file << doctor.getPassword() << endl;
        file << doctor.getEmail() << endl;
        file << doctor.getSpecialization() << endl;
        file << doctor.getRate() << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}
void savePatients(const unordered_map<string, Patient>& patients) {
    ofstream file("Patients.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) {
        cerr << "Unable to open Patients.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newPatients) {
        const Patient& patient = pair.second;
        file << patient.getName() << endl;
        file << patient.getId() << endl;
        file << patient.getGender() << endl;
        file << patient.getAge() << endl;
        file << patient.getPassword() << endl;
        file << patient.getEmail() << endl;
        file << patient.getDisease() << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}
void saveAppointments(const unordered_map<string, Appointment>& appointments) {
    ofstream file("Appointments.txt", ios::trunc); // Open in truncate mode to clear the file
    if (!file) {
        cerr << "Unable to open Appointments.txt for writing!" << endl;
        return;
    }

    for (const auto& pair : newAppointments) {
        const Appointment& appointment = pair.second;
        file << appointment.get_date() << endl;
        file << appointment.getTime() << endl;
        file << appointment.get_drId() << endl;
        file << appointment.get_ptId() << endl;
        file << (appointment.get_is_available() ? "1" : "0") << endl;
        file << "----------------------------------" << endl;
    }
    file.close();
}
// function to registrate a doctor
Doctor register_doctor() {

    // parameters
    string name;
    string id;
    string gender;
    string age;
    string password;
    string email;
    string special;
    string rate = "0";

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
    Doctor doctor(name,gender,id,age,password,special,rate,email);
    // returning the doctor to main
    return doctor;
}
Patient register_patient() {

    // parameters
    string name;
    string id;
    string gender;
    string age;
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
void Patient_login() {
    string password;
    string id;
    cout << "Enter your id: " << endl;
    cin >> id;

    cout << "Enter your password: " << endl;
    cin >> password;


    for (auto &pair: newPatients) {
        if (pair.first == id && pair.second.getPassword() == password) {
            // menu inside the patient
            int choice4;

            cout << "Logged in successfully!" << endl;
            cout << "-----------------------" << endl;
            cout << "Input the number from the menu you would like to choose from: " << endl;
            cout << "1. Schedule an appointment " << endl;
            cout << "2. Cancel an appointment " << endl;
            cout << "3. View your appointments " << endl;
            cout << "4. Edit medical history " << endl;
            cout << "5. Change Password " << endl;
            cout << "6. Rate your visit" << endl;
            cout << "7. Exit" << endl;

            cin >> choice4;

            if (choice4 == 1) {
                string d,m,y;
                cout << "Enter a specific date to schedule (DD MM YYYY): ";
                cin >> d >> m >> y;
                string date = d + m + y;

                string time;
                cout << "choose from these hours: 10:00 | 10:30 | 11:00 | 11:30 ";
                cin >> time;

                string special;
                cout << "Enter the specialty of the doctor:" << endl;
                cout << "options: " << endl;

                for (auto &pair: newDoctors) {
                    cout << pair.second.getSpecialization() << endl;
                }

                cin >> special;

                string drID;

                for (auto &pair: newDoctors) {
                    if (pair.second.getSpecialization() == special) {drID = pair.first;
                    }
                }

                cout << "id:" << drID << endl;
                bool isAvailable = true;


                for (auto &pair: newAppointments) {
                    if (pair.first == id && pair.second.getTime() == time) {
                        cout << "The appointment is already booked" << endl;
                        isAvailable = false;
                    }
                }
                if (isAvailable) {
                    Appointment appointment(date,drID,id,time,true);
                    newAppointments[id] = appointment;
                    saveAppointments(newAppointments);
                    cout << "Appointment successfully booked" << endl;
                    cout << "-------------------------------" << endl;

                    cout << "Appointment details: " << endl;
                    appointment.print();
                }
            }
            if (choice4 == 2) {
                string d,m,y;
                cout << "Enter a specific date to cancel (DD MM YYYY): " << endl;
                cin >> d >> m >> y;
                string date = d + m + y;

                cout << "Details of your appointment you wish to cancel: " << endl;
                for (auto &pair: newAppointments) {
                    if (pair.first == id && pair.second.get_date() == date) {pair.second.print();
                    }
                }

                int confirm;
                cout << "Are you sure you want to cancel this appointment? 1 = YES | 2 = NO " << endl;
                cin >> confirm;
                if (confirm == 1) {
                    cout << "Appointment cancelled" << endl;
                    for (auto &pair: newAppointments) {
                        if (pair.first == id && pair.second.get_date() == date) {
                            pair.second.set_is_available(true);
                            pair.second.set_ptId("0");
                        }
                    }
                }
                else {
                    cout << "Exiting system ..." << endl;
                    break;
                }
                saveAppointments(newAppointments);
            }

            if (choice4 == 3) {
                string d,m,y;
                cout << "Enter the date of your appointment (DD MM YYYY): " << endl;
                cin >> d >> m >> y;
                string date = d + m + y;

                cout << "Details of your appointment: " << endl;
                for (auto &pair: newAppointments) {
                    if (pair.first == id && pair.second.get_date() == date) {
                        pair.second.print_for_patient();
                    }
                }
            }
            if (choice4 == 4) {
                string disease;
                cout << "Enter your new history: " << endl;
                cin >> disease;
                for (auto &pair: newPatients) {
                    if (pair.first == id) {
                        pair.second.set_disease(disease);
                        cout << "History added" << endl;
                    }
                }
                savePatients(newPatients);
            }

            if (choice4 == 5) {
                bool valid_pass = false;
                do {
                    string old_pass,new_pass;
                    cout << "Enter your previous password for confirmation: " << endl;
                    cin >> old_pass;
                    for (auto &pair: newPatients) {
                        if (pair.first == id && pair.second.getPassword() == old_pass) {
                            cout << "Password confirmed" << endl;
                            cout << "------------------" << endl;
                            cout << "Enter new password: " << endl;
                            cin >> new_pass;
                            pair.second.set_password(new_pass);
                            cout << "Password changed successfully" << endl;
                            valid_pass = true;
                        }
                        else {
                            cout << "Wrong password" << endl;
                            valid_pass = false;
                        }
                    }
                }
                while (!valid_pass);
                savePatients(newPatients);
            }
            if (choice4 == 6) {
                int rating;
                string doc_id;
                cout << "To rate your visit enter the doctor's id: " << endl;
                cin >> doc_id;
                cout << "Rate your appointment: 1-10 " << endl;
                cin >> rating;


                for (auto &pair: newDoctors) {
                    if (pair.first == doc_id)
                        {pair.second.set_rate(rating);
                        cout << "Rating added successfully" << endl;
                    }
                }
                saveDoctors(newDoctors);
            }
            if (choice4 == 7) {
                cout << "Exiting..." << endl;
                break;
            }
        }
    }
}
void Doctor_login() {
    string id,password;
    cout << "Enter your id: " << endl;
    cin >> id;
    cout << "Enter your password: " << endl;
    cin >> password;
    bool idFound = false;
    bool passwordFound = false;

    for (const auto& pair : newDoctors ) {
        if (pair.first == id && pair.second.getPassword() == password) {
            idFound = true;
            passwordFound = true;
            break;
        }
    }

    // Both ID and password must match
    if (idFound && passwordFound) {
        int choice;
        // Doctor's first menu
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
            if (choice == 1) {
                // prints all the lines from the appointment file
                string d,m,y;
                cout << "Enter a specific date to view your appointments: DD/MM/YEAR " << endl;
                cin >> d >> m >> y;
                string date = d + m + y;

                for (const auto& pair : newAppointments) {
                    if (pair.second.get_drId() == id && pair.second.get_date() == date) {
                        pair.second.print();
                    }
                }
            }
            if (choice == 2) {
                string d,m,y;
                cout << "Enter a specific date in which you want to block: DD/MM/YEAR" << endl;
                cin >> d >> m >> y;
                string date = d + m + y;

                for (auto& pair : newAppointments) {
                    if (pair.second.get_drId() == id && pair.second.get_date() == date) {
                        pair.second.set_is_available(false);
                    }
                }
                saveAppointments(newAppointments);
            }
            if (choice == 3) {
                string name,password, email, special;
                int choice1;
                do {
                    cout << "What would you like to edit? " << endl;
                    cout << "1. Name " << endl;
                    cout << "2. Password " << endl;
                    cout << "3. Email " << endl;
                    cout << "4. Specialization " << endl;
                    cout << "5. Exit " << endl;
                    cin >> choice1;
                    switch (choice1) {
                        case 1: {
                            cout << "Enter your new name: " << endl;
                            cin >> name;
                            for (auto& pair : newDoctors) {
                                if (pair.first == id) {
                                    pair.second.setName(name);
                                }
                            }
                            saveDoctors(newDoctors);
                            break;
                        }
                        case 2: {
                            bool valid_pass = false;
                            do {
                                string old_pass;
                                cout << "Enter your previous password for confirmation: " << endl;
                                cin >> old_pass;
                                for (auto &pair: newDoctors) {
                                    if (pair.first == id && pair.second.getPassword() == old_pass) {
                                        cout << "Password confirmed" << endl;
                                        cout << "------------------" << endl;
                                        cout << "Enter new password: " << endl;
                                        cin >> password;
                                        pair.second.setPassword(password);
                                        cout << "Password changed successfully" << endl;
                                        valid_pass = true;
                                    }
                                    else {
                                        cout << "Wrong password" << endl;
                                        valid_pass = false;
                                    }
                                }
                            }
                            while (!valid_pass);
                            saveDoctors(newDoctors);
                            break;
                        }
                        case 3: {
                            cout << "Enter your new Email: " << endl;
                            cin >> email;
                            for (auto& pair : newDoctors) {
                                if (pair.first == id) {
                                    pair.second.setEmail(email);
                                }
                            }
                            saveDoctors(newDoctors);
                            break;
                        }
                        case 4: {
                            cout << "Enter your new specialization: " << endl;
                            cin >> special;
                            for (auto& pair : newDoctors) {
                                if (pair.first == id) {
                                    pair.second.setSpecialization(special);
                                }
                            }
                            saveDoctors(newDoctors);
                            break;
                        }
                        case 5: {
                            cout << "Exiting..." << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid choice, please try again." << endl;
                            break;
                        }
                    }
                }
                while (choice1 != 5);
            }
            if (choice == 4) {
                cout << "Exiting..." << endl;
            }
        }
        if (choice == 2) {
            cout << "Input the number from the menu you would like to choose from: " << endl;
            cout << "1. Edit patient's medical history " << endl;
            cout << "2. View medicine list" << endl;
            cout << "3. Exit " << endl;
            cin >> choice;
            if (choice == 1) {
                string patient_id;
                cout << "Enter the patient's id: " << endl;
                cin >> patient_id;
                for ( auto& pair: newPatients)  {
                    if (pair.first == patient_id) {
                        int choice7;
                        cout << "1. Edit patient's medical history" << endl;
                        cout << "2. View patient's medical history" << endl;
                        cin >> choice7;
                        if (choice7 == 1) {
                            string disease;
                            cout << "Enter the new medical history: " << endl;
                            cin >> disease;
                            pair.second.set_disease(disease);
                            cout << "Medical history added successfully" << endl;
                        }
                        if (choice7 == 2) {
                            cout << "Patient's medical history: " << endl;
                            cout << pair.second.getDisease() << endl;
                        }
                        if (choice7 == 3) {
                            cout << "Exiting..." << endl;
                        }

                    }
                }
                savePatients(newPatients);
            }
            if (choice == 2) {
                cout << "Medicine list: " << endl;
                cout << "1. Paracetamol (Acetaminophen) – Commonly used to relieve pain and reduce fever. " << endl;
                cout << "2. Ibuprofen – A non-steroidal anti-inflammatory drug (NSAID) used for pain, inflammation, and fever." << endl;
                cout << "3. Amoxicillin – An antibiotic used to treat bacterial infections." << endl;
                cout << "4. Metformin – Commonly prescribed for managing type 2 diabetes." << endl;
                cout << "5. Atorvastatin – Used to lower cholesterol and prevent cardiovascular disease." << endl;
                cout << "6. Omeprazole – A proton pump inhibitor used to treat acid reflux and stomach ulcers." << endl;
                cout << "7. Ciprofloxacin – An antibiotic used to treat various bacterial infections, including urinary tract infections." << endl;
            }
            if (choice == 3) {
                cout << "Exiting..." << endl;
            }
        }
        if (choice == 3) {
            cout << "Exiting..." << endl;
        }
    }

}
void registerPatientMenu() {
    Patient patient1 = register_patient();

    newPatients[patient1.getId()] = patient1;
    savePatients(newPatients);
}
void registerDoctorMenu() {
    Doctor doc1 = register_doctor();

    newDoctors[doc1.getId()] = doc1;
    saveDoctors(newDoctors);
}


bool main_menu() {
    displayWelcomeMessage();

    cout << "Would you like to login or register to the system?" << endl;
    int choice;
    cout << "Enter your choice: | 1 = register | 2 = login " << endl;
    cin >> choice;

    if (choice == 1) { // if the user chooses to register
        int choice1;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice1;

        if (choice1 == 1) {  // if the user decided to register as a doctor
            int choice2;
            registerDoctorMenu();
            saveDoctors(newDoctors);
            cout << "Do you want to connect to the system? | 1 = YES | 2 = NO " << endl;
            cin >> choice2;
            if (choice2 == 1) {
                Doctor_login();
            }
            else {
                cout << "Exiting..." << endl;
            }

        }

        if (choice1 == 2) { // if the user decided to register as a patient
            int choice2;
            registerPatientMenu();
            savePatients(newPatients);
            cout << "Do you want to connect to the system? | 1 = YES | 2 = NO " << endl;
            cin >> choice2;
            if (choice2 == 1) {
                Patient_login();
            }
            else {
                cout << "Exiting..." << endl;
            }
        }
    }

    if (choice == 2) { // if the user chooses to log in
        int choice2;
        cout << "Are you a doctor or a patient? " << endl;
        cout << "Enter your choice: | 1 = doctor | 2 = patient " << endl;
        cin >> choice2;

        if (choice2 == 1) {
            // if the user decided to log in as a doctor
            Doctor_login();
        }
        if (choice2 == 2) {
            Patient_login();
        }
    }
}




int main () {
    // main menu
    main_menu();

    return 0;

}

