#pragma once
#include "Human.h"
#include "Employee.h"
#include <fstream>

class Nurse : public Human, public Employee
{
private:
    static int nurse_counter;
    string nurse_id;
    string assignedWard;

public:
    Nurse();
    Nurse(string name, int age, string id, string ward);
    void set_assignedWard(string ward);
    string get_nurse_id();
    string get_assignedWard();
    void display() const override;
    string serialize() const;
    void deserialize(const string& data);
};