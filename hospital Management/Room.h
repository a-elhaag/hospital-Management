#pragma once
#include <iostream>
#include <string>
using namespace std;

class Room
{
private:
    static int room_counter;
    string room_id;
    string type;
    string status;

public:
    Room();
    Room(string room_id, string type, string status);
    void set_type(string type);
    void set_status(string status);
    string get_room_id() const;
    string get_type() const;
    string get_status() const;
    void display() const;
    string serialize() const;
    void deserialize(const string& data);
};

