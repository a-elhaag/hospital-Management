#include "Nurse.h"

int Nurse::nurse_counter = 0;

Nurse::Nurse()
{
    nurse_id = "";
    nurse_counter++;
    cout << "Please enter your assigned ward: \n";
    cin.ignore();
    getline(cin, assignedWard);
    nurse_id = "N" + to_string(nurse_counter);
    set_employeeID(nurse_id);
    cout << "Nurse ID: " << nurse_id << endl;
}

Nurse::Nurse(string name, int age, string id, string ward)
{
    this->name = name;
    this->age = age;
    this->nurse_id = id;
    this->assignedWard = ward;
    set_employeeID(id);
    if (stoi(id.substr(1)) > nurse_counter)
    {
        nurse_counter = stoi(id.substr(1));
    }
}

void Nurse::set_assignedWard(string ward)
{
    assignedWard = ward;
}

string Nurse::get_nurse_id()
{
    return nurse_id;
}

string Nurse::get_assignedWard()
{
    return assignedWard;
}

void Nurse::display() const
{
    cout << "Nurse ID: " << nurse_id
        << ", Name: " << name
        << ", Age: " << age
        << ", Assigned Ward: " << assignedWard
        << ", Employee ID: " << employeeID << endl;
}

string Nurse::serialize() const
{
    return name + "," + to_string(age) + "," + nurse_id + "," + assignedWard;
}

void Nurse::deserialize(const string& data)
{
    string token;
    size_t pos = 0;
    int field = 0;
    string tokens[4];
    string temp_data = data;
    while ((pos = temp_data.find(',')) != string::npos && field < 3)
    {
        tokens[field++] = temp_data.substr(0, pos);
        temp_data.erase(0, pos + 1);
    }
    tokens[field++] = temp_data;
    name = tokens[0];
    age = stoi(tokens[1]);
    nurse_id = tokens[2];
    assignedWard = tokens[3];
    set_employeeID(nurse_id);
    if (stoi(nurse_id.substr(1)) > nurse_counter)
    {
        nurse_counter = stoi(nurse_id.substr(1));
    }
}
