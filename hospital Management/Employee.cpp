#include <iostream>
using namespace std;
#include "Employee.h"

Employee::Employee() {
    employeeID = "";
}

void Employee::set_employeeID(string id) {
    employeeID = id;
}

string Employee::get_employeeID() {
    return employeeID;
}

void Employee::employee_details() const {
    cout << ", Employee ID: " << employeeID;
}
