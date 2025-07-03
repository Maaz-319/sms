#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "Utility.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Database_handler.h"
#include <limits>

using namespace std;

Person **data = new Person *[100];
int *ids = new int[100];
int current_id = 0;

int give_id()
{

    if (current_id <= 0)
    {
        current_id = 1000;
    }

    // Find the next available ID that's not already in use
    int next_id = current_id + 1;
    bool id_exists = true;

    while (id_exists)
    {
        id_exists = false;
        // Check if this ID already exists in data
        for (int i = 0; i < 100; i++)
        {
            if (data[i] != nullptr && data[i]->getId() == next_id)
            {
                id_exists = true;
                next_id++;
                break;
            }
        }
    }

    // Find first available slot in ids array
    for (int i = 0; i < 100; i++)
    {
        if (ids[i] == 0)
        {
            ids[i] = next_id;
            current_id = next_id;
            break;
        }
    }
    current_id = next_id;
    return current_id;
}

void add_person()
{
    if (Person::getCount() >= 100)
    {
        Utility::print_error_message("Data is full, cannot save more Persons.");
        return;
    }

    Person *person;
    int choice, id, age;
    string name, address, phone, subject, designation;

    Utility::print_header("ADD NEW PERSON");
    vector<string> options = {
        "Add Student",
        "Add Teacher",
        "Add Staff",
        "Back to Main Menu"};
    Utility::print_menu_box("ADD PERSON", options);

    choice = Utility::take_integer_input(1, 4, "Select an option");

    if (choice == 4)
        return;
    id = give_id();

    if (choice == 1)
    {
        person = new Student();
    }
    else if (choice == 2)
    {
        person = new Teacher();
    }
    else if (choice == 3)
    {
        person = new Staff();
    }

    person->get_common_inputs();
    person->setId(id);
    person->get_specific_inputs();

    if (person->save(data))
    {
        Utility::print_success_message(person->printType() + " saved successfully.");
    }
    Utility::print_success_message("ID assigned: " + to_string(id));
    getch();
    // delete person; // Free memory after saving
}

// FUNCTIONS FOR GET DATA
void get_person_data()
{
    Person *person = nullptr;
    int choice;
    Utility::print_header("GET PERSON DATA");
    int id;
    id = Utility::take_integer_input(1, 10000, "ID to find");

    int index = Person::get_person_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No Person found with ID: " + to_string(id));
        getch();
        return;
    }
    person = data[index];
    person->printDetails();
    getch();
    // delete person;
}

// FUNCTIONS FOR MODIFY DATA
void modify_person()
{
    Person *person = nullptr; // Initialize to nullptr
    int id, index = 0;

    Utility::print_header("MODIFY PERSON DATA");
    id = Utility::take_integer_input(1, 10000, "ID to modify");

    index = Person::get_person_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No Person found with ID: " + to_string(id));
        getch();
        return;
    }

    person = data[index];
    Utility::print_dashed_line(20);
    cout << "Modifying " << person->printType() << " with ID: "
         << id << endl;
    Utility::print_dashed_line(20);
    person->get_common_inputs();
    person->get_specific_inputs();

    if (person->save(data, index))
    {
        Utility::print_success_message(person->printType() + " modified successfully.");
    }
    getch();
    // delete person;
}

void display_system_stats()
{
    Utility::print_header("SYSTEM STATISTICS");

    cout << "Database Status:" << endl;
    Utility::print_dashed_line(20);
    cout << "Total Records: " << Person::getCount() << "/100" << endl;
    cout << "Available Slots: " << (100 - Person::getCount()) << endl;
    cout << "Memory Usage: " << (Person::getCount() * 100.0 / 100) << "%" << endl;

    cout << "\nRecord Distribution:" << endl;
    Utility::print_dashed_line(25);
    cout << "Students: " << Student::getCount() << endl;
    cout << "Teachers: " << Teacher::getCount() << endl;
    cout << "Staff: " << Staff::getCount() << endl;
    cout << "Total People: " << Person::getCount() << endl;

    Utility::print_success_message("Press any key to continue...");
    getch();
}

void delete_person()
{
    Person *person = nullptr;
    int id, index = -1;

    Utility::print_header("DELETE PERSON DATA");
    id = Utility::take_integer_input(1, 10000, "ID to delete");

    index = Person::get_person_by_id(id, data);
    if (index == -1)
    {
        Utility::print_error_message("No Person found with ID: " + to_string(id));
        getch();
        return;
    }

    person = data[index];
    person->printDetails();
    Utility::print_success_message("FOUND PERSON WITH ID: " + to_string(id));

    char confirm;
    cout << "\nAre you sure you want to delete this person? (y/n): ";
    cin >> confirm;

    if (confirm != 'y' && confirm != 'Y')
    {
        Utility::print_success_message("Deletion cancelled by user!");
        getch();
        return;
    }

    // Delete the person
    string person_type = person->printType();
    delete data[index];
    data[index] = nullptr;

    Utility::print_success_message(person_type + " with ID " + to_string(id) + " deleted successfully!");
    getch();
}

// MAIN MENU
void main_menu()
{
    char choice;
    do
    {
        vector<string> options = {
            "Enter Data",
            "View Data",
            "Modify Data",
            "Delete Data",
            "System Statistics",
            "Exit Program"};

        Utility::print_menu_box("SCHOOL MANAGEMENT SYSTEM", options);
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            add_person();
            break;
        case '2':
            get_person_data();
            break;
        case '3':
            modify_person();
            break;
        case '4':
            delete_person();
            break;
        case '5':
            display_system_stats();
            break;
        case '6':
            Utility::print_header("PROGRAM EXIT");
            cout << "Thank you for using School Management System!" << endl;
            Utility::print_success_message("Program terminated successfully!");
            save_person(data);
            getch();
            break;
        default:
            Utility::print_error_message("Invalid choice! Please select 1-6.");
            cout << "\nPress any key to continue...";
            getch();
        }
    } while (choice != '6');
}

int main()
{
    // getch();
    system("cls");

    data = read_person(ids, current_id);
    main_menu();

    for (int i = 0; i < 100 && data[i] != nullptr; i++)
    {
        delete data[i];
    }
    delete[] data;

    return 0;
}