#include <iostream>
using namespace std;
#include "Patient.h"

int Patient::patient_counter = 0;

Patient::Patient() {
    patient_id = "";
    patient_counter++;
    cout << "Please enter your medical history: \n";
    cin.ignore();
    getline(cin, medical_history);
    patient_id = "P" + to_string(patient_counter);
    set_employeeID(patient_id);
    cout << "Patient ID: " << patient_id << endl;
}

Patient::Patient(string name, int age, string id, string medical_history) {
    this->name = name;
    this->age = age;
    this->patient_id = id;
    this->medical_history = medical_history;
    set_employeeID(id);
    if (stoi(id.substr(1)) > patient_counter) {
        patient_counter = stoi(id.substr(1));
    }
}

void Patient::set_medical_history(string history) {
    medical_history = history;
}

string Patient::get_patient_id() {
    return patient_id;
}

string Patient::get_medical_history() {
    return medical_history;
}

void Patient::display() const {
    cout << "Patient ID: " << patient_id
        << ", Name: " << name
        << ", Age: " << age
        << ", Medical History: " << medical_history
        << ", Employee ID: " << employeeID << endl;
}

string Patient::serialize() const {
    return name + "," + to_string(age) + "," + patient_id + "," + medical_history;
}

void Patient::deserialize(const string& data) {
    string token;
    size_t pos = 0;
    int field = 0;
    string tokens[4];
    string temp_data = data;
    while ((pos = temp_data.find(',')) != string::npos && field < 3) {
        tokens[field++] = temp_data.substr(0, pos);
        temp_data.erase(0, pos + 1);
    }
    tokens[field++] = temp_data;
    name = tokens[0];
    age = stoi(tokens[1]);
    patient_id = tokens[2];
    medical_history = tokens[3];
    set_employeeID(patient_id);
    if (stoi(patient_id.substr(1)) > patient_counter) {
        patient_counter = stoi(patient_id.substr(1));
    }
}
