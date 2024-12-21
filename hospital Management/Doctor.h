#pragma once
#include "Human.h"
#include "Employee.h"
#include <fstream>

enum Specialization {
    General,
    Cardiologist,
    Neurologist,
    Pediatrician
};

class Doctor : public Human, public Employee
{
protected:
    static int doc_counter;
    string id;
    string password;
    Specialization specialization;

public:
    Doctor();
    Doctor(string name, int age, string id, string password, Specialization specialization);
    void set_specialization(Specialization specialization);
    string get_id();
    Specialization get_specialization();
    virtual void display() const;
    virtual string serialize() const;
    virtual void deserialize(const string& data);
};

