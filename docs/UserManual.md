# School Management System - User Manual

## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Getting Started](#getting-started)
4. [System Overview](#system-overview)
5. [Testing the System](#testing-the-system)
6. [Using the Application](#using-the-application)
7. [Data Management](#data-management)
8. [Troubleshooting](#troubleshooting)

## Introduction

The School Management System is a C++ console application designed to demonstrate advanced object-oriented programming principles while providing a functional system for managing educational institution data. The system features a **unified Person-based architecture** with polymorphic operations and centralized ID management.

### Key Features
- **Unified Architecture**: All person types share a common ID system and interface
- **Polymorphic Operations**: Type-agnostic handling through base class pointers
- **Static Object Counting**: Real-time tracking of objects with proper memory management
- **Centralized ID Management**: Unique ID generation across all person types
- **File-based Data Persistence**: Automatic save/load with cross-platform compatibility
- **Comprehensive Testing Framework**: Unit and integration tests for quality assurance
- **Professional Console Interface**: Colored output, formatted menus, input validation

### System Architecture - Unified Design
- **Person (Abstract Base)**: Unified base class with common ID system (`Person::id`)
- **Student Class**: Inherits unified architecture, no additional specific attributes
- **Teacher Class**: Adds subject management while using unified ID system
- **Staff Class**: Adds designation management while using unified ID system
- **Utility Class**: Enhanced formatting, input validation, and color management
- **Database Handler**: File I/O with unified architecture support
- **Global Functions**: Centralized ID generation and person management

### Technical Highlights
- **Unified ID System**: All persons use `Person::id` starting from 1000
- **Polymorphic Input**: `get_common_inputs()` and `get_specific_inputs()` methods
- **Type-safe Operations**: Virtual functions ensure correct behavior per type
- **Memory Safety**: RAII principles with proper destructor count management
- **Cross-platform**: Compatible with Windows, Linux, and macOS

## Installation

### Prerequisites
- C++ compiler with C++11 support (GCC 7.0+, Clang 6.0+, or MSVC 2017+)
- Windows, Linux, or macOS operating system
- Console/terminal access

### Building from Source

#### Direct Compilation (Recommended)
1. Navigate to the project directory
2. Create build directory if it doesn't exist:
   ```bash
   mkdir build
   ```
3. Compile the main application:
   ```bash
   g++ -std=c++11 -Iinclude -o build/sms.exe src/main.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp
   ```

#### Building Test Suites
```bash
# Unit Tests
g++ -std=c++11 -Iinclude -o build/UnitTest.exe tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp

# Integration Tests  
g++ -std=c++11 -Iinclude -o build/IntegrationTest.exe tests/IntegrationTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp
```

## Getting Started

### First Launch - Testing the System

Before using the main application, it's recommended to run the test suites to verify everything is working correctly:

#### 1. Run Unit Tests
```bash
cd build
.\UnitTest.exe
```
- Tests individual class functionality
- Verifies inheritance and polymorphism
- Choose 'y' to pause after each test for detailed review
- Choose 'n' for quick automated testing

#### 2. Run Integration Tests
```bash
.\IntegrationTest.exe
```
- Tests complete system workflows
- Verifies file operations and data persistence
- Simulates real user sessions
- Includes stress testing with multiple objects

#### 3. Run Main Application
```bash
.\sms.exe
```

## System Overview

### Unified Object-Oriented Architecture

The system demonstrates advanced OOP principles with a unified design:

#### Inheritance Hierarchy with Unified ID System
```
Person (Abstract Base with unified ID system)
├── Student (Uses Person::id)
├── Teacher (Uses Person::id + subject)
└── Staff (Uses Person::id + designation)
```

#### Key Architectural Features
- **Unified ID System**: All person types use `Person::id` for consistent identification
- **Polymorphic Operations**: Type-agnostic handling through virtual functions
- **Centralized Management**: Single ID generation system starting from 1000
- **Static Counting with Memory Safety**: Proper count management in constructors/destructors
- **Input Abstraction**: Common and specific input methods for each type

### Data Management - Unified Approach
- **Consistent File Storage**: All types save using unified architecture
- **Type-safe Operations**: Polymorphic save/load while maintaining type integrity
- **Centralized Search**: `Person::get_person_by_id()` works across all types
- **Type-specific Search**: Each class implements `get_by_id()` for type filtering

### ID Management System
- **Range**: IDs start from 1000 and increment
- **Uniqueness**: System ensures no duplicate IDs across all person types
- **Persistence**: IDs are maintained across program sessions
- **Generation**: `give_id()` function provides next available ID

## Testing the System

### Interactive Testing Mode

Both test suites offer interactive mode designed for the unified architecture:
1. When prompted "Do you want to pause after each test? (y/n):", choose:
   - **'y'**: Detailed mode - examine each test step and unified architecture validation
   - **'n'**: Quick mode - automated testing of all unified system components

### Unit Test Coverage - Unified Architecture
- **Person Basic Functionality**: Unified ID system, common setters/getters
- **Student Specific Features**: Unified ID usage, type identification with inheritance
- **Teacher Specific Features**: Subject management with unified ID system
- **Staff Specific Features**: Designation management with unified ID system
- **Polymorphism Testing**: Virtual function calls using unified architecture
- **Utility Functions**: Enhanced console features, input validation, color support
- **Edge Cases**: Boundary testing with unified ID system

### Integration Test Coverage - System-wide
- **Complete Person Workflow**: Full lifecycle using unified architecture
- **Utility System Integration**: Enhanced UI with color and input validation
- **File System Integration**: Unified data persistence across all types
- **Complete System Simulation**: Real-world usage with unified ID management
- **Stress Testing**: Performance validation with unified architecture (100+ objects)

### Test Output Format - Enhanced
```
============================================================
UNIT TEST: Student Specific Functionality
============================================================
What this test will do: Testing Student class unified ID system and polymorphism
Starting test...

1. Testing unified ID functionality:
  -> Set unified ID to 12345: [SUCCESS] (Got: 12345)

2. Testing type identification:
  -> Check if type is 'Student': [SUCCESS] (Got: Student)

[PASSED]: Student Specific Functionality - Unified architecture working correctly
```

## Using the Application

### Starting the Application
1. Navigate to the build directory
2. Run `.\sms.exe`
3. Follow the on-screen menu prompts
4. Use the unified ID system for all operations

### Main Menu Options
```
SCHOOL MANAGEMENT SYSTEM
========================
1. Enter Data
2. View Data  
3. Modify Data
4. Delete Data
5. System Statistics
6. Exit Program
```

### Creating Objects - Unified Architecture

#### Student Objects (Using Unified ID)
```cpp
Student student;
student.setName("Alice Johnson");
student.setAge(19);
student.setPhone("555-0123");
student.setAddress("123 College Ave");
student.setId(1001);  // Unified ID system
// No additional student-specific attributes needed
```

#### Teacher Objects (Using Unified ID)
```cpp
Teacher teacher;
teacher.setName("Dr. Robert Smith");
teacher.setAge(42);
teacher.setPhone("555-0201");
teacher.setAddress("456 Faculty Street");
teacher.setId(1002);  // Unified ID system
teacher.setSubject("Computer Science");
```

#### Staff Objects (Using Unified ID)
```cpp
Staff staff;
staff.setName("Mary Williams");
staff.setAge(38);
staff.setPhone("555-0301");
staff.setAddress("789 Admin Building");
staff.setId(1003);  // Unified ID system
staff.setDesignation("Registrar");
```

### Polymorphic Operations
```cpp
// Create array of Person pointers
Person* people[3];
people[0] = new Student();
people[1] = new Teacher();
people[2] = new Staff();

// Set unified IDs
people[0]->setId(give_id());  // Automatic ID generation
people[1]->setId(give_id());
people[2]->setId(give_id());

// Polymorphic operations work seamlessly
for (int i = 0; i < 3; i++) {
    people[i]->get_common_inputs();   // Common data collection
    people[i]->get_specific_inputs(); // Type-specific data
    people[i]->printDetails();        // Type-specific display
}
```

### Polymorphic Operations
The system supports polymorphic operations through base class pointers:
```cpp
Person* person = new Student();
person->setName("John");
cout << person->printType();  // Outputs: "Student"
person->printDetails();       // Calls Student's implementation
```

## Data Management

### File Structure
The system automatically creates and manages:
- `data/students.txt` - Student records
- `data/teachers.txt` - Teacher records  
- `data/staff.txt` - Staff records

### Data Operations
- **Save**: Objects are saved to appropriate files
- **Load**: Data is read back into objects
- **Validation**: Input validation prevents data corruption

### Static Counting
Track object creation with static counters:
- `Person::getCount()` - Total Person-derived objects
- `Student::getCount()` - Total Student objects
- `Teacher::getCount()` - Total Teacher objects
- `Staff::getCount()` - Total Staff objects
- View all students or search by ID
- Update student records
- Delete student entries
- Track grades and GPA

### 2. Teacher Management
- Register new teachers
- Assign subjects and departments
- Manage salary information
- Update contact details
- View teaching assignments

### 3. Staff Management
- Add administrative staff
- Organize by departments
- Manage payroll information
- Track contact information
- Update job roles

### 4. Data Persistence
- Automatic saving to files
- Data integrity checks
- Backup and recovery
- Import/export capabilities

## Menu Navigation

### Main Menu Options
When you start the application, you'll see the main menu:

```
=== School Management System ===
1. Manage Students
2. Manage Teachers
3. Manage Staff
4. Reports
5. Settings
6. Exit
```

### Navigation Tips
- Enter the number corresponding to your choice
- Use '0' or 'Back' to return to previous menus
- Press 'Q' or 'Quit' to exit at any time
- Follow on-screen prompts for data entry

## Managing Students

### Adding a New Student
1. Select "Manage Students" from the main menu
2. Choose "Add Student"
3. Enter the following information:
   - **Name**: Full name of the student
   - **ID**: Unique student ID number
   - **Phone**: Contact number (format: XXX-XXX-XXXX)
   - **Address**: Complete address
   - **Grade**: Current grade level (e.g., "9th", "10th")
   - **GPA**: Grade Point Average (0.0 - 4.0)

### Viewing Students
- **View All**: Displays all registered students
- **Search by ID**: Find a specific student using their ID
- **Filter by Grade**: Show students from a specific grade

### Updating Student Information
1. Search for the student by ID
2. Select "Edit Student"
3. Choose which field to update
4. Enter the new information
5. Confirm the changes

### Removing Students
1. Search for the student by ID
2. Select "Delete Student"
3. Confirm the deletion
4. The student record will be permanently removed

## Managing Teachers

### Adding a New Teacher
1. Select "Manage Teachers" from the main menu
2. Choose "Add Teacher"
3. Provide the required information:
   - **Name**: Full name
   - **ID**: Unique teacher ID
   - **Phone**: Contact number
   - **Address**: Complete address
   - **Subject**: Primary subject taught
   - **Salary**: Annual salary amount

### Teacher Operations
- **View All Teachers**: Complete teacher directory
- **Search by Subject**: Find teachers by subject area
- **Update Information**: Modify teacher details
- **Salary Management**: Update compensation information

## Managing Staff

### Adding Staff Members
1. Select "Manage Staff" from the main menu
2. Choose "Add Staff"
3. Enter staff information:
   - **Name**: Full name
   - **ID**: Unique staff ID
   - **Phone**: Contact number
   - **Address**: Complete address
   - **Department**: Working department
   - **Salary**: Annual salary

### Staff Operations
- **Department View**: List staff by department
- **Role Management**: Update job responsibilities
- **Contact Updates**: Modify contact information
- **Payroll Management**: Handle salary changes

## Data Management

### Saving Data
- Data is automatically saved when you add, update, or delete records
- Manual save option available in the Settings menu
- Backup files are created before major operations

### Loading Data
- Data is automatically loaded when the application starts
- Manual reload option available if files are updated externally
- Error checking ensures data integrity

### Data Format
All data files use pipe-delimited format (|) for easy parsing:
```
ID|Name|Phone|Address|SpecificField1|SpecificField2
```

### Backup and Recovery
- Regular backups are recommended
- Copy the entire `data/` folder to preserve all information
- Restore by replacing the `data/` folder with a backup

## Troubleshooting

### Common Issues

#### "File not found" Error
**Problem**: Data files are missing
**Solution**: 
- Ensure the `data/` directory exists
- Check file permissions
- Restart the application to recreate files

#### "Invalid data format" Error
**Problem**: Data file corruption
**Solution**:
- Restore from backup
- Manually edit the file to fix formatting
- Use the repair function in Settings

#### Application Crashes
**Problem**: Unexpected termination
**Solution**:
- Check available disk space
- Verify data file integrity
- Restart with administrator privileges

#### Memory Issues
**Problem**: Large datasets causing slowdowns
**Solution**:
- Close other applications
- Consider data archiving for old records
- Increase system memory if possible

### Error Codes
- **ERR_001**: File access denied
- **ERR_002**: Invalid data format
- **ERR_003**: Duplicate ID found
- **ERR_004**: Insufficient memory
- **ERR_005**: Network connection failed

### Getting Help
For additional support:
1. Check the FAQ section in docs/
2. Review the API documentation
3. Contact system administrator
4. Submit bug reports with detailed error information

### Performance Tips
- Keep data files under 10MB for optimal performance
- Regular data cleanup improves responsiveness
- Archive old records to maintain speed
- Use search functions instead of browsing large lists

## Data Validation Rules

### Phone Numbers
- Format: XXX-XXX-XXXX
- Must contain only numbers and hyphens
- Exactly 12 characters including hyphens

### GPA Values
- Range: 0.0 to 4.0
- Maximum 2 decimal places
- Cannot be negative

### Salary Information
- Must be positive numbers
- No special characters except decimal point
- Reasonable range validation applied

### ID Numbers
- Must be unique across each category
- Positive integers only
- Automatically generated if not provided

## Security Considerations

### Data Protection
- Files are stored locally on the system
- No network transmission of sensitive data
- Regular backups recommended for data security

### Access Control
- Single-user application design
- File system permissions control access
- No built-in user authentication

### Privacy
- Personal information remains on local system
- No external data sharing
- User responsible for data protection compliance