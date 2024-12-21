#include "Consultant.h"

Consultant::Consultant() : Doctor()
{
    cout << "Creating a new Consultant.\n";
}

Consultant::Consultant(string name, int age, string id, string password, Specialization specialization)
    : Doctor(name, age, id, password, specialization)
{
}

void Consultant::display() const
{
    string specialization_str;
    switch (specialization) {
    case General: specialization_str = "General"; break;
    case Cardiologist: specialization_str = "Cardiologist"; break;
    case Neurologist: specialization_str = "Neurologist"; break;
    case Pediatrician: specialization_str = "Pediatrician"; break;
    default: specialization_str = "Unknown"; break;
    }
    cout << "Consultant ID: " << id
        << ", Name: " << name
        << ", Age: " << age
        << ", Specialization: " << specialization_str
        << ", Employee ID: " << employeeID << endl;
}

string Consultant::serialize() const
{
    return "Consultant," + Doctor::serialize();
}

void Consultant::deserialize(const string& data)
{
    string prefix = "Consultant,";
    if (data.find(prefix) == 0)
    {
        Doctor::deserialize(data.substr(prefix.length()));
    }
}
