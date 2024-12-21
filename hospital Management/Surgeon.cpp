#include "Surgeon.h"

Surgeon::Surgeon() : Doctor()
{
    cout << "Creating a new Surgeon.\n";
}

Surgeon::Surgeon(string name, int age, string id, string password, Specialization specialization)
    : Doctor(name, age, id, password, specialization)
{
}

void Surgeon::display() const
{
    string specialization_str;
    switch (specialization) {
    case General: specialization_str = "General"; break;
    case Cardiologist: specialization_str = "Cardiologist"; break;
    case Neurologist: specialization_str = "Neurologist"; break;
    case Pediatrician: specialization_str = "Pediatrician"; break;
    default: specialization_str = "Unknown"; break;
    }
    cout << "Surgeon ID: " << id
        << ", Name: " << name
        << ", Age: " << age
        << ", Specialization: " << specialization_str
        << ", Employee ID: " << employeeID << endl;
}

string Surgeon::serialize() const
{
    return "Surgeon," + Doctor::serialize();
}

void Surgeon::deserialize(const string& data)
{
    string prefix = "Surgeon,";
    if (data.find(prefix) == 0)
    {
        Doctor::deserialize(data.substr(prefix.length()));
    }
}
