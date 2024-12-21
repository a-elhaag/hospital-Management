#pragma once
#include <string>
#include <iostream>
using namespace std;

class Hospital_Management;

class Human {
protected:
    int age;
    string name;

public:
    Human();
    void set_age(int age);
    void set_name(string name);
    virtual int get_age();
    virtual string get_name();
    virtual void display() const;
    friend class Hospital_Management;
};
