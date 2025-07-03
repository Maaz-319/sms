#include "Teacher.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int Teacher::count = 0;

Teacher::Teacher() : Person()
{
    count++;
    setType("Teacher");
    subject = "";
}

void Teacher::printDetails()
{
    Utility::print_header("Teacher Details");
    cout << "Name: " << getName() << "\n"
         << "Age: " << getAge() << "\n"
         << "Phone: " << getPhone() << "\n"
         << "Address: " << getAddress() << "\n"
         << "Subject: " << subject << "\n"
         << "Teacher ID: " << getId() << endl;
}


void Teacher::setSubject(const string &subject)
{
    this->subject = subject;
}


string Teacher::getSubject() const
{
    return subject;
}

int Teacher::get_by_id(int id, Person **data)
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == "Teacher")
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

bool Teacher::save(Person **data, int index)
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

void Teacher::get_specific_inputs()
{
    this->setSubject(Utility::take_string_input("Subject"));
}

int Teacher::getCount() { return count; }
Teacher::~Teacher() {
    this->count--;
}
