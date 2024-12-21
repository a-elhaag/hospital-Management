#include "Doctor.h"

int Doctor::doc_counter = 0;

Doctor::Doctor()
{
    id = "";
    doc_counter++;
    cout << "Please choose your specialization: \n";
    cout << "1) General\n2) Cardiologist\n3) Neurologist\n4) Pediatrician\n";
    int choice;
    cin >> choice;
    while (true)
    {
        switch (choice)
        {
        case 1: specialization = General; id += "G"; break;
        case 2: specialization = Cardiologist; id += "C"; break;
        case 3: specialization = Neurologist; id += "N"; break;
        case 4: specialization = Pediatrician; id += "P"; break;
        default:
            cout << "Invalid choice, please try again\n";
            cin >> choice;
            continue;
        }
        break;
    }
    id += to_string(doc_counter);
    set_employeeID(id);
    cout << "Enter your password: ";
    cin >> password;
    cout << "Welcome to our new Doctor, your ID: " << id << "\n";
}

Doctor::Doctor(string name, int age, string id, string password, Specialization specialization)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->password = password;
    this->specialization = specialization;
    set_employeeID(id);
    if (stoi(id.substr(1)) > doc_counter)
    {
        doc_counter = stoi(id.substr(1));
    }
}

void Doctor::set_specialization(Specialization specialization)
{
    this->specialization = specialization;
}

string Doctor::get_id()
{
    return id;
}

Specialization Doctor::get_specialization()
{
    return specialization;
}

void Doctor::display() const
{
    string specialization_str;
    switch (specialization) {
    case General: specialization_str = "General"; break;
    case Cardiologist: specialization_str = "Cardiologist"; break;
    case Neurologist: specialization_str = "Neurologist"; break;
    case Pediatrician: specialization_str = "Pediatrician"; break;
    default: specialization_str = "Unknown"; break;
    }
    cout << "Doctor ID: " << id
        << ", Name: " << name
        << ", Age: " << age
        << ", Specialization: " << specialization_str
        << ", Employee ID: " << employeeID << endl;
}

string Doctor::serialize() const
{
    return name + "," + to_string(age) + "," + id + "," + password + "," + to_string(specialization);
}

void Doctor::deserialize(const string& data)
{
    string token;
    size_t pos = 0;
    int field = 0;
    string tokens[5];
    string temp_data = data;
    while ((pos = temp_data.find(',')) != string::npos && field < 4)
    {
        tokens[field++] = temp_data.substr(0, pos);
        temp_data.erase(0, pos + 1);
    }
    tokens[field++] = temp_data;
    name = tokens[0];
    age = stoi(tokens[1]);
    id = tokens[2];
    password = tokens[3];
    specialization = static_cast<Specialization>(stoi(tokens[4]));
    set_employeeID(id);
    if (stoi(id.substr(1)) > doc_counter)
    {
        doc_counter = stoi(id.substr(1));
    }
}
