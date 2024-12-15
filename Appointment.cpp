//
// Created by Rotem Dino on 11/12/2024.
//

#include "Appointment.h"
#include "Date.h"
Appointment::Appointment() {
    is_available = true;
    date = "";
    drId = "";
    ptId = "";
    time = "";
}
Appointment::Appointment(string d, string dr, string pt, string t, bool is_av) {
    is_available = is_av;
    date = d;
    drId = dr;
    ptId = pt;
    time = t;
}
void Appointment::print() const {
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Doctor ID: " << drId << endl;
    cout << "Patient ID: " << ptId << endl;
    cout << "Is available: " << (is_available ? "Yes" : "No") << endl;
    cout << "----------------------------------" << endl;


}


