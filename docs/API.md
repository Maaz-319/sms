# School Management System - API Documentation

**Version**: 2.0.0  
**Last Updated**: July 2025  
**Architecture**: Unified Person-based System

## Overview
Simple API documentation for the School Management System with unified Person architecture.

## Core Architecture

### Unified Design
- All person types (Student, Teacher, Staff) use the same ID system (`Person::id`)
- IDs are auto-generated starting from 1000
- Polymorphic operations work across all types
- Single save/load system for all data

## Class Hierarchy

```
Person (Abstract Base)
├── Student
├── Teacher 
└── Staff
```

## Person Class (Base)

### Key Attributes
```cpp
protected:
    int id;           // Unified ID for all person types
    string name;      // Person's name
    int age;          // Person's age
    string phone;     // Phone number
    string address;   // Address
    string type;      // "Student", "Teacher", or "Staff"
```

### Important Methods
```cpp
// ID Management
int getId();                    // Get unified ID
void setId(int id);            // Set unified ID

// Common Data
string getName();              // Get name
void setName(string name);     // Set name
int getAge();                  // Get age
void setAge(int age);         // Set age
string getPhone();            // Get phone
void setPhone(string phone);  // Set phone
string getAddress();          // Get address
void setAddress(string addr); // Set address

// Type Info
virtual string printType() = 0;     // Returns person type

// Input/Output
virtual void printDetails() = 0;           // Display info
virtual void get_common_inputs();          // Get name, age, phone, address
virtual void get_specific_inputs() = 0;    // Get type-specific data

// File Operations
virtual bool save(Person** data, int index = -1);  // Save to array

// Static Methods
static int getCount();                              // Total person count
static int get_person_by_id(int id, Person** data); // Find by ID
```

## Student Class

### Description
Represents a student. Uses unified ID system - no separate student ID needed.

### Methods
```cpp
// Constructor/Destructor
Student();          // Creates student, sets type to "Student"
~Student();          // Cleans up, decrements count

// Overridden Methods
string printType() override;              // Returns "Student"
void printDetails() override;             // Shows student info
void get_specific_inputs() override;      // No additional inputs needed
bool save(Person** data, int index) override;  // Save student
int get_by_id(int id, Person** data) override; // Find student by ID

// Static
static int getCount();  // Number of students
```

## Teacher Class

### Description  
Represents a teacher. Uses unified ID system plus subject information.

### Additional Attributes
```cpp
private:
    string subject;  // Teaching subject
```

### Methods
```cpp
// Constructor/Destructor
Teacher();         // Creates teacher, sets type to "Teacher"
~Teacher();        // Cleans up, decrements count

// Subject Management
string getSubject();                    // Get teaching subject
void setSubject(string subject);       // Set teaching subject

// Overridden Methods
string printType() override;            // Returns "Teacher"
void printDetails() override;           // Shows teacher info including subject
void get_specific_inputs() override;    // Gets subject from user
bool save(Person** data, int index) override;  // Save teacher
int get_by_id(int id, Person** data) override; // Find teacher by ID

// Static
static int getCount();  // Number of teachers
```

## Staff Class

### Description
Represents staff member. Uses unified ID system plus designation information.

### Additional Attributes
```cpp
private:
    string designation;  // Job designation
```

### Methods
```cpp
// Constructor/Destructor
Staff();           // Creates staff, sets type to "Staff"
~Staff();          // Cleans up, decrements count

// Designation Management
string getDesignation();                // Get job designation
void setDesignation(string designation); // Set job designation

// Overridden Methods
string printType() override;            // Returns "Staff"
void printDetails() override;           // Shows staff info including designation
void get_specific_inputs() override;    // Gets designation from user
bool save(Person** data, int index) override;  // Save staff
int get_by_id(int id, Person** data) override; // Find staff by ID

// Static
static int getCount();  // Number of staff
```

## Database Handler

### Functions
```cpp
void save_person(Person** data);                   // Save all data to files
Person** read_person(int* ids, int& current_id);   // Load all data from files
```

### Description
- Saves/loads data to `data/students.txt`, `data/teachers.txt`, `data/staff.txt`
- Uses unified format with pipe (`|`) separators
- Auto-creates data directory if needed

## Utility Functions

### Console Display
```cpp
static void print_header(const string& title);    // Print formatted header
static void print_success_message(const string& msg); // Green success message
static void print_error_message(const string& msg);   // Red error message
static void print_menu_box(const string& title, const vector<string>& options); // Menu display
static void print_line(int length = 50);          // Print line separator
static void print_dashed_line(int length = 50);   // Print dashed line
static void print_info_box(const string& message); // Info message box
```

### Color Support
```cpp
static void set_console_color(int color);         // Set text color (Windows)
static void reset_console_color();                // Reset to default
```

### Input Validation
```cpp
static int take_integer_input(int min, int max, const string& prompt); // Validated integer
static string take_string_input(const string& prompt);                 // String input
static string take_phone_input();                                      // Phone validation
```

## Global Functions

### ID Management
```cpp
int give_id();  // Generate next unique ID (starts from 1000)
```

### Main Operations
```cpp
void add_person();       // Add new person with menu
void get_person_data();  // Find and display person by ID
void modify_person();    // Modify person by ID
void delete_person();    // Delete person by ID
void display_system_stats(); // Show counts and statistics
void main_menu();        // Main application loop
```

## Usage Examples

### Basic Usage
```cpp
// Create objects
Student student;
student.setName("John Doe");
student.setAge(20);
student.setId(give_id());  // Auto-generate ID

Teacher teacher;
teacher.setName("Dr. Smith");
teacher.setAge(35);
teacher.setId(give_id());
teacher.setSubject("Math");

// Polymorphic array
Person* people[2] = {&student, &teacher};
for(int i = 0; i < 2; i++) {
    people[i]->printDetails();  // Calls correct version
}
```

### File Operations
```cpp
Person** data = new Person*[100];
// ... add data ...
save_person(data);  // Save to files

int ids[100];
int current_id;
Person** loaded = read_person(ids, current_id);  // Load from files
```

---

**End of API Documentation**