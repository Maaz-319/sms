#include "Person.h"
#include "Utility.h"

#include <iostream>
using namespace std;

int Person::count = 0;

Person::Person() : name(""), age(0), type("Person"), phone("0"), address(""), id(-1) { count++; }

// Getters
string Person::getName() { return this->name; }
int Person::getAge() { return this->age; }
string Person::printType() { return this->type; }
string Person::getPhone() { return this->phone; }
string Person::getAddress() { return this->address; }
int Person::getCount() { return count; }
int Person::getId() { return this->id; }

// Setters
void Person::setName(const string &name) { this->name = name; }
void Person::setAge(int age) { this->age = age; }
void Person::setType(const string &type) { this->type = type; }
void Person::setPhone(const string &phone) { this->phone = phone; }
void Person::setAddress(const string &address) { this->address = address; }
void Person::setId(int id) { this->id = id; }

bool Person::save(Person **data, int index)
{
    if (index == -1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (data[i] == nullptr)
            {
                data[i] = this;
                return true;
            }
        }
        return false;
    }
    else
    {
        data[index] = this;
        return true;
    }
}

int Person::get_person_by_id(int id, Person **data)
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id)
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

void Person::get_common_inputs()
{
    this->setName(Utility::take_string_input(this->printType()+" Name"));
    this->setAge(Utility::take_integer_input(18, 50, this->printType()+" Age"));
    this->setPhone(Utility::take_phone_input());
    this->setAddress(Utility::take_string_input(this->printType()+" Address"));
}

Person::~Person() {
    this->count--;
}