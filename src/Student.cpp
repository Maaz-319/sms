#include "Student.h"
#include "Utility.h"
#include <iostream>
#include <conio.h>
using namespace std;

int Student::count = 0;

Student::Student() : Person()
{
    count++;
    setType("Student");
}

void Student::printDetails()
{
    Utility::print_header("Student Details");
    cout << "Name: " << getName() << "\n"
         << "Age: " << getAge() << "\n"
         << "Phone: " << getPhone() << "\n"
         << "Address: " << getAddress() << "\n"
         << "Student ID: " << getId() << endl;
}

int Student::get_by_id(int id, Person **data)
{
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr && data[i]->getId() == id && data[i]->printType() == "Student")
        {
            cout << data[i]->printType() << endl;
            data[i]->printDetails();
            return i;
        }
    }
    return -1;
}

bool Student::save(Person **data, int index)
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

int Student::getCount() { return count; }
void Student::get_specific_inputs() {
    // Students don't need additional specific inputs beyond common ones
    // The ID is already set in add_person()
}


Student::~Student() {
    this->count--;
}
