#include <iostream>
#include "Hospital_Management.h"
using namespace std;

int main() {
    Hospital_Management hm;
    hm.load_data();
    int choice;
    while (true) {
        cout << "\nHospital Management System\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Patient\n";
        cout << "3. Add Nurse\n";
        cout << "4. Add Room\n";
        cout << "5. List All Humans\n";
        cout << "6. List Doctors\n";
        cout << "7. List Surgeons\n";
        cout << "8. List Consultants\n";
        cout << "9. List Patients\n";
        cout << "10. List Nurses\n";
        cout << "11. List Rooms\n";
        cout << "12. Find Doctor by ID\n";
        cout << "13. Find Surgeon by ID\n";
        cout << "14. Find Consultant by ID\n";
        cout << "15. Find Patient by ID\n";
        cout << "16. Find Nurse by ID\n";
        cout << "17. Find Room by ID\n";
        cout << "18. Assign Room to Patient\n";
        cout << "19. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            hm.add_doctor();
            break;
        case 2:
            hm.add_patient();
            break;
        case 3:
            hm.add_nurse();
            break;
        case 4:
            hm.add_room();
            break;
        case 5:
            hm.list_humans();
            break;
        case 6:
            hm.list_doctors();
            break;
        case 7:
            hm.list_surgeons();
            break;
        case 8:
            hm.list_consultants();
            break;
        case 9:
            hm.list_patients();
            break;
        case 10:
            hm.list_nurses();
            break;
        case 11:
            hm.list_rooms();
            break;
        case 12: {
            string doc_id;
            cout << "Enter Doctor ID: ";
            cin >> doc_id;
            Doctor* doc = hm.find_doctor_by_id(doc_id);
            if (doc) {
                doc->display();
            }
            else {
                cout << "Doctor not found.\n";
            }
            break;
        }
        case 13: {
            string surg_id;
            cout << "Enter Surgeon ID: ";
            cin >> surg_id;
            Surgeon* surg = hm.find_surgeon_by_id(surg_id);
            if (surg) {
                surg->display();
            }
            else {
                cout << "Surgeon not found.\n";
            }
            break;
        }
        case 14: {
            string cons_id;
            cout << "Enter Consultant ID: ";
            cin >> cons_id;
            Consultant* cons = hm.find_consultant_by_id(cons_id);
            if (cons) {
                cons->display();
            }
            else {
                cout << "Consultant not found.\n";
            }
            break;
        }
        case 15: {
            string pat_id;
            cout << "Enter Patient ID: ";
            cin >> pat_id;
            Patient* pat = hm.find_patient_by_id(pat_id);
            if (pat) {
                pat->display();
            }
            else {
                cout << "Patient not found.\n";
            }
            break;
        }
        case 16: {
            string nurse_id;
            cout << "Enter Nurse ID: ";
            cin >> nurse_id;
            Nurse* nurse = hm.find_nurse_by_id(nurse_id);
            if (nurse) {
                nurse->display();
            }
            else {
                cout << "Nurse not found.\n";
            }
            break;
        }
        case 17: {
            string room_id;
            cout << "Enter Room ID: ";
            cin >> room_id;
            Room* room = hm.find_room_by_id(room_id);
            if (room) {
                room->display();
            }
            else {
                cout << "Room not found.\n";
            }
            break;
        }
        case 18:
            hm.assign_room();
            break;
        case 19:
            hm.save_data();
            cout << "Data saved. Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
