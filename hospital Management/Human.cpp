#include "Human.h"

Human::Human() {
    cout << "Please enter your name: \n";
    cin >> name;
    cout << "Please enter your age: \n";
    cin >> age;
}

void Human::set_age(int age) {
    this->age = age;
}

void Human::set_name(string name) {
    this->name = name;
}

int Human::get_age() {
    return age;
}

string Human::get_name() {
    return name;
}

void Human::display() const {
    cout << "Name: " << name << ", Age: " << age;
}
