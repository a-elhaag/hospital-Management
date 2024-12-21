#pragma once
#include "Doctor.h"

class Surgeon : public Doctor
{
public:
    Surgeon();
    Surgeon(string name, int age, string id, string password, Specialization specialization);
    void display() const override;
    string serialize() const override;
    void deserialize(const string& data) override;
};