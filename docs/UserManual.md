# School Management System - User Manual

**Version**: 2.0.0  
**Last Updated**: July 2025  
**Architecture**: Unified Person-based System

## Table of Contents
1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Getting Started](#getting-started)
4. [Using the Application](#using-the-application)
5. [Data Management](#data-management)
6. [Troubleshooting](#troubleshooting)

## Introduction

The School Management System is a C++ console application that demonstrates modern object-oriented programming with a **unified Person-based architecture**. All person types (Students, Teachers, Staff) share a common ID system and interface for consistent, type-safe operations.

### Key Features
- **Unified ID System**: All persons use the same ID format starting from 1000
- **Polymorphic Operations**: Type-safe handling through inheritance
- **File Persistence**: Automatic save/load for all data
- **Input Validation**: Robust data validation and error handling
- **Console Interface**: Colored output and formatted menus
- **Comprehensive Testing**: Built-in unit and integration tests

### System Architecture
```
Person (Abstract Base)
├── Student (No additional attributes)
├── Teacher (+ subject field)
└── Staff (+ designation field)
```

All classes share the same ID system and common interface while providing type-specific functionality.

## Installation

### Prerequisites
- C++ compiler with C++11 support (GCC 7.0+, Clang 6.0+, or MSVC 2017+)
- Windows, Linux, or macOS
- Console/terminal access

### Building from Source

#### Quick Build
```bash
# Navigate to project directory
cd school-management-system
mkdir build

# Compile main application
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Compile tests (optional)
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp -o build/UnitTest.exe
g++ -std=c++11 -Iinclude tests/IntegrationTest.cpp src/*.cpp -o build/IntegrationTest.exe
```

## Getting Started

### First Time Setup
1. **Build the Application**: Follow installation instructions above
2. **Run Tests** (Recommended): Verify everything works correctly
3. **Launch Main Application**: Start using the system

### Running Tests
```bash
cd build

# Unit tests - Test individual components
.\UnitTest.exe

# Integration tests - Test complete workflows  
.\IntegrationTest.exe
```

**Test Options**:
- Choose **'y'** to pause after each test for detailed review
- Choose **'n'** for quick automated testing

### Launch Main Application
```bash
cd build
.\sms.exe
```

## Using the Application

### Main Menu
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

### Basic Operations

#### 1. Adding People
1. Select "Enter Data" from main menu
2. Choose person type (Student/Teacher/Staff)
3. Enter common information:
   - Name
   - Age  
   - Phone number
   - Address
4. Enter type-specific information:
   - **Teachers**: Subject they teach
   - **Staff**: Job designation
   - **Students**: No additional information needed
5. System automatically assigns unique ID

#### 2. Viewing Data
1. Select "View Data" from main menu
2. Enter the person's ID number
3. System displays complete information

#### 3. Modifying Records
1. Select "Modify Data" from main menu
2. Enter person's ID to modify
3. Choose which field to update
4. Enter new value
5. System confirms changes

#### 4. Deleting Records
1. Select "Delete Data" from main menu
2. Enter person's ID to delete
3. Confirm deletion when prompted
4. System removes record and updates counts

#### 5. System Statistics
View current system statistics:
- Total number of people in system
- Number of students, teachers, and staff
- System status and data file information

### Example Usage

#### Adding a Student
```
Select option: 1 (Enter Data)
Select type: 1 (Student)
Enter name: John Smith
Enter age: 20
Enter phone: 555-0123
Enter address: 123 College St
System assigns ID: 1000
Student added successfully!
```

#### Adding a Teacher
```
Select option: 1 (Enter Data)
Select type: 2 (Teacher)
Enter name: Dr. Sarah Wilson
Enter age: 35
Enter phone: 555-0456
Enter address: 456 Faculty Ave
Enter subject: Mathematics
System assigns ID: 1001
Teacher added successfully!
```

#### Adding Staff
```
Select option: 1 (Enter Data)
Select type: 3 (Staff)
Enter name: Mike Johnson
Enter age: 42
Enter phone: 555-0789
Enter address: 789 Admin Blvd
Enter designation: IT Administrator
System assigns ID: 1002
Staff member added successfully!
```

## Data Management

### Automatic File Storage
The system automatically creates and manages data files:
- `data/students.txt` - Student records
- `data/teachers.txt` - Teacher records
- `data/staff.txt` - Staff records

### Data Format
All records use a consistent pipe-separated format:
```
ID|Name|Age|Phone|Address|[Type-specific fields]
```

### Data Persistence
- **Automatic Save**: Data is saved after each operation
- **Load on Startup**: Previous data is automatically loaded
- **Cross-Platform**: Works on Windows, Linux, and macOS
- **Error Handling**: Graceful handling of file access issues

### ID Management
- **Unique IDs**: All persons get unique IDs starting from 1000
- **Sequential**: IDs increment automatically (1000, 1001, 1002...)
- **Persistent**: IDs are maintained across program sessions
- **Search**: Find any person by their ID regardless of type

## Troubleshooting

### Common Issues

#### Build Problems
**Error**: "Cannot find header files"
- **Solution**: Ensure you're using `-Iinclude` flag when compiling
- **Command**: `g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe`

**Error**: "Linker errors"
- **Solution**: Make sure all source files are included
- **Check**: Verify all `.cpp` files in `src/` directory are compiled

#### Runtime Issues
**Error**: "Cannot create data directory"
- **Solution**: Check file permissions in project directory
- **Fix**: Ensure write permissions for data folder creation

**Error**: "File access denied"
- **Solution**: Close any open data files and restart application
- **Check**: Ensure data files aren't open in other programs

**Error**: "Invalid input"
- **Solution**: Follow input prompts carefully
- **Note**: Phone numbers should be in format "XXX-XXXX" or similar

#### Data Issues
**Problem**: "Lost data after restart"
- **Solution**: Check data directory exists and files aren't corrupted
- **Prevention**: Don't manually edit data files

**Problem**: "Incorrect counts or statistics"
- **Solution**: Restart application to reload data
- **Check**: Verify data files haven't been manually modified

### Getting Help
1. **Run Tests**: Execute unit and integration tests to verify system
2. **Check Documentation**: Review API.md and DeveloperGuide.md
3. **Validate Installation**: Ensure proper C++11 compiler setup
4. **File Permissions**: Verify read/write access to project directory

### System Requirements Verification
```bash
# Check C++ compiler
g++ --version

# Test compilation
g++ -std=c++11 -Iinclude src/main.cpp -c

# Verify file system access
ls -la data/
```

---

**End of User Manual**

For technical details and development information, see `API.md` and `DeveloperGuide.md`.
