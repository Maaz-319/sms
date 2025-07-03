#include "Database_handler.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

#include <iostream>
#include <fstream>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#else
#include <unistd.h>
#endif

using namespace std;

// Helper function to create directory if it doesn't exist
void ensureDataDirectory()
{
    struct stat info;
    if (stat("../data", &info) != 0)
    {
        // Directory doesn't exist, create it
        mkdir("../data", 0755);
    }
}

void save_person(Person **data)
{
    ensureDataDirectory();

    ofstream file_stud("../data/students.txt");
    ofstream file_teach("../data/teachers.txt");
    ofstream file_staff("../data/staff.txt");

    if (!file_stud.is_open() || !file_teach.is_open() || !file_staff.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < 100; i++)
    {
        if (data[i] != nullptr)
        {
            if (data[i]->printType() == "Student")
            {
                file_stud << data[i]->getName() << "`"
                          << data[i]->getAge() << "`"
                          << data[i]->getPhone() << "`"
                          << data[i]->getAddress() << "`"
                          << data[i]->getId() << endl;
            }
            else if (data[i]->printType() == "Teacher")
            {
                Teacher *teacher = static_cast<Teacher *>(data[i]);
                file_teach << data[i]->getName() << "`"
                           << data[i]->getAge() << "`"
                           << data[i]->getPhone() << "`"
                           << data[i]->getAddress() << "`"
                           << data[i]->getId() << "`"
                           << teacher->getSubject() << endl;
            }
            else if (data[i]->printType() == "Staff")
            {
                Staff *staff = static_cast<Staff *>(data[i]);
                file_staff << data[i]->getName() << "`"
                           << data[i]->getAge() << "`"
                           << data[i]->getPhone() << "`"
                           << data[i]->getAddress() << "`"
                           << data[i]->getId() << "`"
                           << staff->getDesignation() << endl;
            }
        }
    }
    file_stud.close();
    file_teach.close();
    file_staff.close();
}

Person **read_person(int *ids, int &current_id)
{
    Person **data = new Person *[100];
    for (int i = 0; i < 100; i++)
    {
        data[i] = nullptr;
    }

    for (int i = 0; i < 100; i++)
    {
        ids[i] = 0;
    }

    // Fix: Read from data folder instead of root directory
    ifstream file_stud("../data/students.txt");
    ifstream file_teach("../data/teachers.txt");
    ifstream file_staff("../data/staff.txt");

    // If files don't exist (first run), create empty files and return empty data
    if (!file_stud.is_open() || !file_teach.is_open() || !file_staff.is_open())
    {
        cout << "Data files not found. Starting with empty database." << endl;
        return data; // Return empty data array instead of nullptr
    }

    string line;
    int index = 0;

    // Read students
    while (getline(file_stud, line) && !line.empty())
    {
        string name, age_str, phone, address, id_str;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        size_t pos3 = line.find('`', pos2 + 1);
        size_t pos4 = line.find('`', pos3 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || pos4 == string::npos)
        {
            continue; // Skip malformed lines
        }

        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        phone = line.substr(pos2 + 1, pos3 - pos2 - 1);
        address = line.substr(pos3 + 1, pos4 - pos3 - 1);
        id_str = line.substr(pos4 + 1);

        try
        {
            int age = stoi(age_str);
            int id = stoi(id_str);

            Student *student = new Student();
            student->setName(name);
            student->setAge(age);
            student->setPhone(phone);
            student->setAddress(address);
            student->setId(id);
            ids[index] = id;
            // Keep track of maximum ID for proper ID generation
            if (id > current_id) {
                current_id = id;
            }

            data[index++] = student;
        }
        catch (const exception &e)
        {
            cerr << "Error parsing student data: " << line << endl;
            continue;
        }
    }

    // Read teachers
    while (getline(file_teach, line) && !line.empty())
    {
        string name, age_str, phone, address, id_str, subject;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        size_t pos3 = line.find('`', pos2 + 1);
        size_t pos4 = line.find('`', pos3 + 1);
        size_t pos5 = line.find('`', pos4 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos ||
            pos4 == string::npos || pos5 == string::npos)
        {
            continue; // Skip malformed lines
        }

        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        phone = line.substr(pos2 + 1, pos3 - pos2 - 1);
        address = line.substr(pos3 + 1, pos4 - pos3 - 1);
        id_str = line.substr(pos4 + 1, pos5 - pos4 - 1);
        subject = line.substr(pos5 + 1);

        try
        {
            int age = stoi(age_str);
            int id = stoi(id_str);

            Teacher *teacher = new Teacher();
            teacher->setName(name);
            teacher->setAge(age);
            teacher->setPhone(phone);
            teacher->setAddress(address);
            teacher->setId(id);
            teacher->setSubject(subject);

            ids[index] = id;
            // Keep track of maximum ID for proper ID generation
            if (id > current_id) {
                current_id = id;
            }
            data[index++] = teacher;
        }
        catch (const exception &e)
        {
            cerr << "Error parsing teacher data: " << line << endl;
            continue;
        }
    }

    // Read staff
    while (getline(file_staff, line) && !line.empty())
    {
        string name, age_str, phone, address, id_str, designation;
        size_t pos1 = line.find('`');
        size_t pos2 = line.find('`', pos1 + 1);
        size_t pos3 = line.find('`', pos2 + 1);
        size_t pos4 = line.find('`', pos3 + 1);
        size_t pos5 = line.find('`', pos4 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos ||
            pos4 == string::npos || pos5 == string::npos)
        {
            continue; // Skip malformed lines
        }

        name = line.substr(0, pos1);
        age_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
        phone = line.substr(pos2 + 1, pos3 - pos2 - 1);
        address = line.substr(pos3 + 1, pos4 - pos3 - 1);
        id_str = line.substr(pos4 + 1, pos5 - pos4 - 1);
        designation = line.substr(pos5 + 1);

        try
        {
            int age = stoi(age_str);
            int id = stoi(id_str);

            Staff *staff = new Staff();
            staff->setName(name);
            staff->setAge(age);
            staff->setPhone(phone);
            staff->setAddress(address);
            staff->setId(id);
            staff->setDesignation(designation);

            ids[index] = id;
            // Keep track of maximum ID for proper ID generation
            if (id > current_id) {
                current_id = id;
            }
            data[index++] = staff;
        }
        catch (const exception &e)
        {
            cerr << "Error parsing staff data: " << line << endl;
            continue;
        }
    }

    file_stud.close();
    file_teach.close();
    file_staff.close();
    data[index] = nullptr;

    return data;
}