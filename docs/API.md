# School Management System - API Documentation

## Overview
This document provides detailed API documentation for the School Management System classes and their methods. The system uses a unified object-oriented design with inheritance, polymorphism, and a centralized ID management system.

## Core Architecture

The system is built around a **unified Person-based architecture** where:
- All entities (Student, Teacher, Staff) inherit from the abstract `Person` class
- All entities use a **unified ID system** through `Person::id`
- Polymorphic operations enable type-agnostic handling
- File persistence is handled consistently across all types

## Core Classes

### Person Class (Abstract Base Class)
Base class for all person entities in the system. This is an abstract class with pure virtual functions that provides the foundation for the unified architecture.

#### Private Attributes
- `static int count`: Static counter tracking total Person objects created

#### Protected Attributes  
- `int id`: **Unified unique identifier** for each person (used by all derived classes)
- `string name`: Person's full name
- `int age`: Person's age
- `string type`: Type identifier for the person
- `string phone`: Phone number (flexible format)
- `string address`: Complete physical address

#### Methods

##### Constructors & Destructors
```cpp
Person();                    // Default constructor (increments count)
virtual ~Person();           // Virtual destructor for proper cleanup (decrements count)
```

##### Pure Virtual Methods
```cpp
virtual void printDetails() = 0;               // Must be implemented by derived classes
virtual void get_specific_inputs() = 0;       // Get type-specific inputs from user
virtual int get_by_id(int id, Person **data) = 0;  // Find person by ID (type-specific)
```

##### Virtual Getters
```cpp
virtual string getName();         // Get person's name
virtual int getAge();            // Get person's age  
virtual string printType();      // Get person type ("Student", "Teacher", "Staff")
virtual string getPhone();       // Get phone number
virtual string getAddress();     // Get address
virtual int getId();             // Get unified ID
```

##### Static Methods
```cpp
static int getCount();                                  // Get total count of Person objects
static int get_person_by_id(int id, Person **data);   // Find any person by ID (returns index)
```

##### Virtual Setters (Person Attributes)
```cpp
virtual void setName(const string& name);      // Set person's name
virtual void setAge(int age);                  // Set person's age
virtual void setType(const string& type);      // Set person type
virtual void setPhone(const string& phone);    // Set phone number
virtual void setAddress(const string& address); // Set address
virtual void setId(int id);                    // Set unified ID
```

##### Virtual Setters (Derived Class Attributes - Default Empty Implementations)
```cpp
virtual void setSubject(const string& subject) {}           // For Teacher class
virtual void setDesignation(const string& designation) {}   // For Staff class
```

##### Input and Data Management Methods
```cpp
virtual void get_common_inputs();              // Get common inputs (name, age, phone, address)
virtual bool save(Person **data, int index = -1);  // Save person to data array
```

---

### Student Class
Inherits from Person. Represents a student in the system using the unified ID architecture.

#### Private Attributes
- `static int count`: Static counter for Student objects

#### Methods

##### Constructors & Destructors
```cpp
Student();                   // Default constructor (calls Person(), increments Student count)
virtual ~Student();          // Virtual destructor (decrements Student count)
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;                           // Display student information to console
int get_by_id(int id, Person **data) override;        // Find student by ID
bool save(Person **data, int index = -1) override;    // Save student to data array
void get_specific_inputs() override;                   // Get student-specific inputs (none currently)
```

---

### Teacher Class
Inherits from Person. Represents a teacher in the system using the unified ID architecture.

#### Private Attributes
- `string subject`: Subject taught by the teacher
- `static int count`: Static counter for Teacher objects

#### Methods

##### Constructors & Destructors
```cpp
Teacher();                   // Default constructor (calls Person(), increments Teacher count)
virtual ~Teacher();          // Virtual destructor (decrements Teacher count)
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;                           // Display teacher information to console
int get_by_id(int id, Person **data) override;        // Find teacher by ID
bool save(Person **data, int index = -1) override;    // Save teacher to data array
void get_specific_inputs() override;                   // Get teacher-specific inputs (subject)
```

##### Teacher-Specific Getters
```cpp
string getSubject() const;      // Get subject taught
```

##### Teacher-Specific Setters
```cpp
void setSubject(const string& subject) override; // Set subject taught
```

##### Static Methods
```cpp
static int getCount();          // Get count of Teacher objects
```

**Note**: Teachers use the unified `Person::id` system. Access ID through `getId()` and `setId()` inherited methods.

---

### Staff Class
Inherits from Person. Represents administrative staff using the unified ID architecture.

#### Private Attributes
- `string designation`: Job designation/title
- `static int count`: Static counter for Staff objects

#### Methods

##### Constructors & Destructors
```cpp
Staff();                     // Default constructor (calls Person(), increments Staff count)
virtual ~Staff();            // Virtual destructor (decrements Staff count)
```

##### Overridden Virtual Methods
```cpp
void printDetails() override;                           // Display staff information to console
int get_by_id(int id, Person **data) override;        // Find staff by ID
bool save(Person **data, int index = -1) override;    // Save staff to data array
void get_specific_inputs() override;                   // Get staff-specific inputs (designation)
```

##### Staff-Specific Getters
```cpp
virtual string getDesignation(); // Get job designation
```

##### Staff-Specific Setters
```cpp
void setDesignation(const string& designation) override;     // Set job designation
```

##### Static Methods
```cpp
static int getCount();          // Get count of Staff objects
```

**Note**: Staff members use the unified `Person::id` system. Access ID through `getId()` and `setId()` inherited methods.

---

## Database Handler

### Database Functions
File-based database operations for Person objects with unified architecture support.

#### File Operations
```cpp
void save_person(Person **person);                     // Save array of Person objects to respective files
Person **read_person(int *ids, int &current_id);      // Read Person objects from files into array
```

#### File Structure
- **data/students.txt**: Student records storage
- **data/teachers.txt**: Teacher records storage  
- **data/staff.txt**: Staff records storage

---

## Utility Class

### Utility
Provides static helper functions for console formatting, display, and input validation.

#### Console Formatting Methods
```cpp
static void print_line(int length);                                          // Print horizontal line
static void print_dashed_line(int length);                                  // Print dashed line
static void print_header(const string& title);                              // Print formatted header
static void print_menu_box(const string& title, const vector<string>& options); // Print menu with options
```

#### Message Display Methods
```cpp
static void print_success_message(const string& message);  // Display success message with formatting
static void print_error_message(const string& message);    // Display error message with formatting
static void print_info_box(const string& message);         // Display info message in box format
```

#### Input Validation Methods
```cpp
static int take_integer_input(int min, int max, const string& prompt);  // Get validated integer input
static string take_string_input(const string& prompt);                  // Get string input
static string take_phone_input();                                       // Get formatted phone input
```

#### Console Color Management
```cpp
enum Colors { RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, RESET };
static void set_console_color(Colors color);                            // Set console text color
static void reset_console_color();                                      // Reset console color
```

#### Class Design
```cpp
Utility() = delete;  // Constructor deleted - utility class with only static methods
```

---

## Global Functions

### ID Management
```cpp
int give_id();  // Generate next available unique ID for new persons
```

### Person Management
```cpp
void add_person();       // Add new person (Student/Teacher/Staff) with user interface
void get_person_data();  // Find and display person by ID
void modify_person();    // Modify existing person by ID
void delete_person();    // Delete person by ID with confirmation
```

### System Functions
```cpp
void display_system_stats(); // Show system statistics and record distribution
void main_menu();            // Main application menu loop
```

---

## Polymorphism and Inheritance

### Virtual Function Behavior
- **printDetails()**: Each derived class implements its own version
- **get_specific_inputs()**: Each derived class implements type-specific input collection
- **get_by_id()**: Each derived class implements type-specific search
- **save()**: Each derived class can override save behavior if needed

### Static Counting System
- Each class maintains its own static count
- Person::getCount() returns total of all Person-derived objects
- Individual class counts available through respective getCount() methods
- Counts are properly decremented in destructors

### Memory Management
- Virtual destructors ensure proper cleanup through base pointers
- Dynamic allocation and deletion fully supported
- RAII principles followed throughout the design
- Proper count management on object destruction

### Unified ID System
- All person types use the same ID field (`Person::id`)
- ID generation is centralized through `give_id()` function
- IDs are unique across all person types
- ID range starts from 1000 for consistency

---

## Usage Examples

### Creating Objects with Unified Architecture
```cpp
// Create objects
Student student;
Teacher teacher; 
Staff staff;

// Set common Person attributes
student.setName("John Doe");
student.setAge(20);
student.setPhone("555-0123");
student.setAddress("123 Main St");
student.setId(1001);  // Unified ID system

// Set specific attributes
teacher.setSubject("Computer Science");
staff.setDesignation("Administrator");

// All use same ID methods
cout << "Student ID: " << student.getId() << endl;
cout << "Teacher ID: " << teacher.getId() << endl;
cout << "Staff ID: " << staff.getId() << endl;
```

### Polymorphic Usage with Unified Architecture
```cpp
// Use base class pointers
Person* people[3];
people[0] = new Student();
people[1] = new Teacher();
people[2] = new Staff();

// Set unified IDs
people[0]->setId(give_id());
people[1]->setId(give_id());
people[2]->setId(give_id());

// Polymorphic method calls
for (int i = 0; i < 3; i++) {
    people[i]->get_common_inputs();  // Get common inputs
    people[i]->get_specific_inputs(); // Get type-specific inputs
    people[i]->printDetails();        // Display details
}

// Proper cleanup
for (int i = 0; i < 3; i++) {
    delete people[i];
}
```

### Database Operations with Unified Architecture
```cpp
// Create data array
Person** data = new Person*[100];
for (int i = 0; i < 100; i++) data[i] = nullptr;

// Add objects with unified system
Person* student = new Student();
student->setId(give_id());
student->save(data);

// Find any person by ID (unified search)
int index = Person::get_person_by_id(1001, data);
if (index != -1) {
    data[index]->printDetails();
}

// Type-specific search
Student temp;
int studentIndex = temp.get_by_id(1001, data);
```