#pragma once
#include <string>
using namespace std;

class Employee {
protected:
    string employeeID;

public:
    Employee();
    void set_employeeID(string id);
    string get_employeeID();
    virtual void employee_details() const;
};
