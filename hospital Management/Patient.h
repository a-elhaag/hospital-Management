#pragma once
#include "Human.h"
#include "Employee.h"
#include <fstream>
#include <string>
using namespace std;

class Patient : public Human, public Employee {
private:
    static int patient_counter;
    string patient_id;
    string medical_history;

public:
    Patient();
    Patient(string name, int age, string id, string medical_history);
    void set_medical_history(string history);
    string get_patient_id();
    string get_medical_history();
    void display() const override;
    string serialize() const;
    void deserialize(const string& data);
};
