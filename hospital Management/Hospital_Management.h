#pragma once
#include "Doctor.h"
#include "Surgeon.h"
#include "Consultant.h"
#include "Patient.h"
#include "Nurse.h"
#include "Room.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

class Hospital_Management
{
private:
    vector<shared_ptr<Human>> humans;
    vector<Doctor> doctors;
    vector<Surgeon> surgeons;
    vector<Consultant> consultants;
    vector<Patient> patients;
    vector<Nurse> nurses;
    vector<Room> rooms;

public:
    void add_doctor();
    void add_patient();
    void add_nurse();
    void add_room();
    void list_humans();
    void list_doctors();
    void list_surgeons();
    void list_consultants();
    void list_patients();
    void list_nurses();
    void list_rooms();
    Doctor* find_doctor_by_id(const string& id);
    Surgeon* find_surgeon_by_id(const string& id);
    Consultant* find_consultant_by_id(const string& id);
    Patient* find_patient_by_id(const string& id);
    Nurse* find_nurse_by_id(const string& id);
    Room* find_room_by_id(const string& id);
    void assign_room();
    void save_data();
    void load_data();
};

