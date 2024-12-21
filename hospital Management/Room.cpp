#include "Room.h"

int Room::room_counter = 0;

Room::Room()
{
    room_id = "";
    room_counter++;
    cout << "Please enter room type (General/Surgery): \n";
    cin >> type;
    status = "Free";
    room_id = "R" + to_string(room_counter);
    cout << "Room ID: " << room_id << ", Type: " << type << ", Status: " << status << endl;
}

Room::Room(string room_id, string type, string status)
{
    this->room_id = room_id;
    this->type = type;
    this->status = status;
    if (stoi(room_id.substr(1)) > room_counter)
    {
        room_counter = stoi(room_id.substr(1));
    }
}

void Room::set_type(string type)
{
    this->type = type;
}

void Room::set_status(string status)
{
    this->status = status;
}

string Room::get_room_id() const
{
    return room_id;
}

string Room::get_type() const
{
    return type;
}

string Room::get_status() const
{
    return status;
}

void Room::display() const
{
    cout << "Room ID: " << room_id
        << ", Type: " << type
        << ", Status: " << status << endl;
}

string Room::serialize() const
{
    return room_id + "," + type + "," + status;
}

void Room::deserialize(const string& data)
{
    string token;
    size_t pos = 0;
    int field = 0;
    string tokens[3];
    string temp_data = data;
    while ((pos = temp_data.find(',')) != string::npos && field < 2)
    {
        tokens[field++] = temp_data.substr(0, pos);
        temp_data.erase(0, pos + 1);
    }
    tokens[field++] = temp_data;
    room_id = tokens[0];
    type = tokens[1];
    status = tokens[2];
    if (stoi(room_id.substr(1)) > room_counter)
    {
        room_counter = stoi(room_id.substr(1));
    }
}
