#include "Hospital_Management.h"

void Hospital_Management::add_doctor() {
    cout << "Select Doctor Type:\n1. General Doctor\n2. Surgeon\n3. Consultant\nEnter choice: ";
    int type_choice;
    cin >> type_choice;
    switch (type_choice) {
    case 1: {
        shared_ptr<Doctor> new_doctor = make_shared<Doctor>();
        doctors.push_back(*new_doctor);
        humans.push_back(new_doctor);
        break;
    }
    case 2: {
        shared_ptr<Surgeon> new_surgeon = make_shared<Surgeon>();
        surgeons.push_back(*new_surgeon);
        humans.push_back(new_surgeon);
        break;
    }
    case 3: {
        shared_ptr<Consultant> new_consultant = make_shared<Consultant>();
        consultants.push_back(*new_consultant);
        humans.push_back(new_consultant);
        break;
    }
    default:
        cout << "Invalid choice. Doctor not added.\n";
        break;
    }
}

void Hospital_Management::add_patient()
{
    shared_ptr<Patient> new_patient = make_shared<Patient>();
    patients.push_back(*new_patient);
    humans.push_back(new_patient);
}

void Hospital_Management::add_nurse()
{
    shared_ptr<Nurse> new_nurse = make_shared<Nurse>();
    nurses.push_back(*new_nurse);
    humans.push_back(new_nurse);
}

void Hospital_Management::add_room()
{
    try {
        Room new_room;
        rooms.push_back(new_room);
    }
    catch (...) {
        cout << "Error adding room.\n";
    }
}

void Hospital_Management::list_humans() {
    for (const auto& human : humans) {
        human->display();
    }
}

void Hospital_Management::list_doctors()
{
    for (const auto& doctor : doctors) {
        doctor.display();
    }
}

void Hospital_Management::list_surgeons()
{
    for (const auto& surgeon : surgeons) {
        surgeon.display();
    }
}

void Hospital_Management::list_consultants()
{
    for (const auto& consultant : consultants) {
        consultant.display();
    }
}

void Hospital_Management::list_patients()
{
    for (const auto& patient : patients) {
        patient.display();
    }
}

void Hospital_Management::list_nurses()
{
    for (const auto& nurse : nurses) {
        nurse.display();
    }
}

void Hospital_Management::list_rooms()
{
    for (const auto& room : rooms) {
        room.display();
    }
}

Doctor* Hospital_Management::find_doctor_by_id(const string& id) {
    for (auto& doctor : doctors) {
        if (doctor.get_id() == id) {
            return &doctor;
        }
    }
    return nullptr;
}

Surgeon* Hospital_Management::find_surgeon_by_id(const string& id) {
    for (auto& surgeon : surgeons) {
        if (surgeon.get_id() == id) {
            return &surgeon;
        }
    }
    return nullptr;
}

Consultant* Hospital_Management::find_consultant_by_id(const string& id) {
    for (auto& consultant : consultants) {
        if (consultant.get_id() == id) {
            return &consultant;
        }
    }
    return nullptr;
}

Patient* Hospital_Management::find_patient_by_id(const string& id) {
    for (auto& patient : patients) {
        if (patient.get_patient_id() == id) {
            return &patient;
        }
    }
    return nullptr;
}

Nurse* Hospital_Management::find_nurse_by_id(const string& id) {
    for (auto& nurse : nurses) {
        if (nurse.get_nurse_id() == id) {
            return &nurse;
        }
    }
    return nullptr;
}

Room* Hospital_Management::find_room_by_id(const string& id) {
    for (auto& room : rooms) {
        if (room.get_room_id() == id) {
            return &room;
        }
    }
    return nullptr;
}

void Hospital_Management::assign_room()
{
    string patient_id, room_id;
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    Patient* patient = find_patient_by_id(patient_id);
    if (!patient) {
        cout << "Patient not found.\n";
        return;
    }
    cout << "Enter Room ID: ";
    cin >> room_id;
    Room* room = find_room_by_id(room_id);
    if (!room) {
        cout << "Room not found.\n";
        return;
    }
    if (room->get_status() == "Occupied") {
        cout << "Room is already occupied.\n";
        return;
    }
    room->set_status("Occupied");
    cout << "Room assigned successfully.\n";
}

void Hospital_Management::save_data()
{
    ofstream doctor_file("doctors.txt");
    for (const auto& doctor : doctors) {
        doctor_file << doctor.serialize() << "\n";
    }
    doctor_file.close();

    ofstream surgeon_file("surgeons.txt");
    for (const auto& surgeon : surgeons) {
        surgeon_file << surgeon.serialize() << "\n";
    }
    surgeon_file.close();

    ofstream consultant_file("consultants.txt");
    for (const auto& consultant : consultants) {
        consultant_file << consultant.serialize() << "\n";
    }
    consultant_file.close();

    ofstream patient_file("patients.txt");
    for (const auto& patient : patients) {
        patient_file << patient.serialize() << "\n";
    }
    patient_file.close();

    ofstream nurse_file("nurses.txt");
    for (const auto& nurse : nurses) {
        nurse_file << nurse.serialize() << "\n";
    }
    nurse_file.close();

    ofstream room_file("rooms.txt");
    for (const auto& room : rooms) {
        room_file << room.serialize() << "\n";
    }
    room_file.close();
}

void Hospital_Management::load_data()
{
    string line;
    ifstream doctor_file("doctors.txt");
    while (getline(doctor_file, line)) {
        Doctor temp;
        temp.deserialize(line);
        doctors.push_back(temp);
        shared_ptr<Doctor> ptr = make_shared<Doctor>(temp);
        humans.push_back(ptr);
    }
    doctor_file.close();

    ifstream surgeon_file("surgeons.txt");
    while (getline(surgeon_file, line)) {
        Surgeon temp;
        temp.deserialize(line);
        surgeons.push_back(temp);
        shared_ptr<Surgeon> ptr = make_shared<Surgeon>(temp);
        humans.push_back(ptr);
    }
    surgeon_file.close();

    ifstream consultant_file("consultants.txt");
    while (getline(consultant_file, line)) {
        Consultant temp;
        temp.deserialize(line);
        consultants.push_back(temp);
        shared_ptr<Consultant> ptr = make_shared<Consultant>(temp);
        humans.push_back(ptr);
    }
    consultant_file.close();

    ifstream patient_file("patients.txt");
    while (getline(patient_file, line)) {
        Patient temp;
        temp.deserialize(line);
        patients.push_back(temp);
        shared_ptr<Patient> ptr = make_shared<Patient>(temp);
        humans.push_back(ptr);
    }
    patient_file.close();

    ifstream nurse_file("nurses.txt");
    while (getline(nurse_file, line)) {
        Nurse temp;
        temp.deserialize(line);
        nurses.push_back(temp);
        shared_ptr<Nurse> ptr = make_shared<Nurse>(temp);
        humans.push_back(ptr);
    }
    nurse_file.close();

    ifstream room_file("rooms.txt");
    while (getline(room_file, line)) {
        Room temp;
        temp.deserialize(line);
        rooms.push_back(temp);
    }
    room_file.close();
}
