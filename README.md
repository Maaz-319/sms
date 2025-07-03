# School Management System

A comprehensive C++ console application for managing student, teacher, and staff records in educational institutions. Built with object-oriented programming principles, featuring polymorphism, inheritance, and file-based data persistence.

## 🌐 Connect & Follow

<div align="center">

### 📱 Social Media & Professional Networks

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/maaz-319)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://linkedin.com/in/maazbinasif)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://instagram.com/maaz.binasif)

### 💬 Get in Touch

**📧 Email**: maazbinaasif@gmail.com
**💼 Portfolio**: [portfolio.maaz.me](https://portfolio.maaz.me)  
**🌐 Website**: [maaz.me](https://maaz.me)
</div>

## 🎯 Overview

The School Management System is a robust console application that allows educational institutions to efficiently manage their personnel records. The system supports three types of users: Students, Teachers, and Staff members, each with their specific attributes and functionalities.

### Key Features

- **Multi-User Management**: Handle Students, Teachers, and Staff with dedicated workflows
- **Object-Oriented Design**: Built using C++ classes with inheritance and polymorphism
- **Data Persistence**: File-based storage system for permanent data retention
- **Interactive Console Interface**: User-friendly menu-driven navigation
- **Data Validation**: Input validation and error handling
- **Search & Modify**: Find and update records by unique ID
- **System Statistics**: Real-time database status and record distribution
- **Memory Management**: Efficient dynamic memory allocation and cleanup

### Technical Highlights

- **Inheritance Hierarchy**: Abstract `Person` base class with `Student`, `Teacher`, and `Staff` derived classes
- **Polymorphism**: Virtual functions for type-specific behavior
- **Static Counting**: Track object instances across all classes
- **File I/O**: Separate data files for each entity type
- **Utility System**: Formatted console output with professional styling

## 📋 System Requirements

### Runtime Requirements (Pre-built Executable)
- **OS**: Windows 7/10/11 (64-bit)
- **RAM**: 128 MB minimum
- **Storage**: 10 MB free space
- **Display**: Console/Terminal support

### Development Requirements (Source Compilation)
- **Compiler**: GCC 7.0+ / MSVC 2017+ / Clang 6.0+
- **C++ Standard**: C++11 or higher
- **OS**: Windows, Linux, or macOS
- **RAM**: 512 MB minimum (for compilation)

## 🚀 Quick Start

### Option 1: Run Pre-built Executable (Recommended)

If you don't have a C++ compiler installed, you can run the program directly:

```bash
# Navigate to build directory
cd build

# Run the application
.\sms.exe
```

### Option 2: Compile from Source

```bash
# Create build directory (if not exists)
mkdir build

# Compile the application
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Run the application
cd build
.\sms.exe
```

### Option 3: Compile and Run Tests

```bash
# Compile unit tests
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp -o build/UnitTest.exe

# Compile integration tests
g++ -std=c++11 -Iinclude tests/IntegrationTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp -o build/IntegrationTest.exe

# Run tests
cd build
.\UnitTest.exe
.\IntegrationTest.exe

# Or Run through a Testing Suite I created
cd build
RunTests.bat
```

## 📖 Usage Guide

### Main Menu Options

The system provides six main functions accessible through a menu-driven interface:

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

### 1. Enter Data (Unified Architecture)
Add new records using the unified ID system:

**Add Student**
- Student Name (Full name)
- Student Age (18-50)
- Phone Number (Validated format)
- Address (Complete address)
- **Unified ID** (Auto-generated, starting from 1000)

**Add Teacher**  
- Teacher Name (Full name)
- Teacher Age (18-50)
- Phone Number (Validated format)
- Address (Complete address)
- Subject (Teaching subject)
- **Unified ID** (Auto-generated, starting from 1000)

**Add Staff**
- Staff Name (Full name)
- Staff Age (18-50)
- Phone Number (Validated format)
- Address (Complete address)
- Designation (Job title)
- **Unified ID** (Auto-generated, starting from 1000)

### 2. View Data (Unified Search)
Search and display existing records using the unified ID system:

- **Find Person by ID**: Enter any ID to find any person type (unified search)
- **Type Identification**: System automatically identifies and displays the correct person type
- **Detailed Display**: Shows all relevant information including type-specific attributes

### 3. Modify Data (Unified System)
Update existing records using unified ID system:

- **Modify by ID**: Enter any person's ID to modify their information
- **Type Detection**: System automatically detects person type and shows appropriate fields
- **Common Fields**: Update name, age, phone, address for any person type
- **Specific Fields**: Update subject (Teachers) or designation (Staff) as applicable

### 4. Delete Data (Unified System)
Remove records with confirmation:

- **Delete by ID**: Enter any person's ID to delete their record
- **Confirmation**: System shows record details and asks for confirmation
- **Safe Deletion**: Proper memory cleanup and count management
- **Immediate Feedback**: Success/failure notification

### 5. System Statistics (Enhanced)
View comprehensive system information:

- **Database Status**: Current capacity and usage (X/100 records)
- **Available Slots**: Remaining storage capacity
- **Memory Usage**: System resource utilization percentage
- **Record Distribution**: 
  - Students: X records
  - Teachers: Y records  
  - Staff: Z records
  - Total People: X+Y+Z records

### 6. Exit Program
Safely exit the application with automatic data saving to files.

## 🗂️ Data Storage (Unified Architecture)

The system uses file-based storage with unified architecture support. The data directory is located in the project root, while executables are in the `build/` folder:

```
project-root/
├── data/                    # Data storage (project root)  
│   ├── students.txt         # Student records (unified format)
│   ├── teachers.txt         # Teacher records (unified format)
│   └── staff.txt            # Staff records (unified format)
└── build/                   # Compiled executables
    ├── sms.exe              # Main application
    ├── UnitTest.exe         # Unit tests
    └── IntegrationTest.exe  # Integration tests
```

### Data Persistence Features (Enhanced)
- **Unified Loading**: All person types loaded with consistent ID system from `../data/`
- **Unified Saving**: All person types saved with unified architecture to `../data/`
- **ID Persistence**: Current ID counter maintained across sessions
- **Directory Auto-Creation**: Data directory created automatically if missing
- **Type-Safe Storage**: Each type maintains separate file while using unified ID system
- **Capacity Management**: Maximum 100 total records across all types
- **Cross-Platform Paths**: Works on Windows, Linux, and macOS

### Important Notes
- **Run from build/ directory**: `cd build && ./sms.exe` (recommended)
- **Unified ID System**: All IDs start from 1000 and are unique across all person types
- **Automatic ID Management**: System handles ID generation and uniqueness
- **Data files**: Always stored in project-root/data/ regardless of execution location

## 🧪 Testing

The system includes comprehensive test suites for quality assurance. For detailed testing information, see [tests/README.md](tests/README.md).

### Available Test Executables
- **UnitTest.exe**: Component and class testing
- **IntegrationTest.exe**: System workflow and integration testing

### Quick Test Commands
```bash
cd build
.\UnitTest.exe      # Run unit tests
.\IntegrationTest.exe   # Run integration tests
```

## 📁 Project Structure

```
school-management-system/
├── 📄 README.md                     # Project documentation
├── 📄 .gitignore                    # Git exclusions
│
├── 📁 include/                      # Header files
│   ├── Person.h                     # Abstract base class
│   ├── Student.h                    # Student class declaration
│   ├── Teacher.h                    # Teacher class declaration
│   ├── Staff.h                      # Staff class declaration
│   ├── Database_handler.h           # File I/O operations
│   └── Utility.h                    # Console formatting utilities
│
├── 📁 src/                          # Source implementation
│   ├── start.cpp                    # Main application entry point
│   ├── Person.cpp                   # Person class implementation
│   ├── Student.cpp                  # Student class implementation
│   ├── Teacher.cpp                  # Teacher class implementation
│   ├── Staff.cpp                    # Staff class implementation
│   ├── Database_handler.cpp         # Database operations
│   └── Utility.cpp                  # Utility functions
│
├── 📁 build/                        # Compiled executables
│   ├── sms.exe                      # Main application
│   ├── UnitTest.exe                 # Unit test executable
│   ├── IntegrationTest.exe          # Integration test executable
│   └── RunTests.bat                 # Test automation script
│
├── 📁 data/                         # Data storage
│   ├── students.txt                 # Student records
│   ├── teachers.txt                 # Teacher records
│   └── staff.txt                    # Staff records
│
├── 📁 tests/                        # Test suites
│   ├── README.md                    # Testing documentation
│   ├── UnitTest.cpp                 # Unit test source
│   └── IntegrationTest.cpp          # Integration test source
│
└── 📁 docs/                         # Additional documentation
    ├── API.md                       # Class and method reference
    ├── UserManual.md                # Detailed user guide
    └── DeveloperGuide.md            # Development documentation
```

## 🔧 Development

### Code Architecture
- **Abstract Base Class**: `Person` with pure virtual functions
- **Derived Classes**: `Student`, `Teacher`, `Staff` with specific implementations
- **Polymorphism**: Virtual function overriding for type-specific behavior
- **Static Counting**: Class-level instance tracking
- **Memory Management**: RAII principles and proper cleanup

### Compilation Commands
```bash
# Debug build with all warnings
g++ -g -std=c++11 -Wall -Wextra -Iinclude src/*.cpp -o build/sms.exe

# Release build with optimizations  
g++ -O3 -DNDEBUG -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Clean build
rm -rf build/*
mkdir build
```

## 🐛 Troubleshooting

### Common Issues

**Program Not Starting**
- Ensure `data/` directory exists
- Check file permissions for data files
- Verify executable permissions on `sms.exe`

**Data Not Saving**
- Check write permissions in `data/` directory  
- Ensure sufficient disk space
- Verify data files are not corrupted

**Compilation Errors**
- Ensure C++11 compiler support
- Check include path is correct (`-Iinclude`)
- Verify all source files are present

**Runtime Errors**
- Check system capacity (max 100 records)
- Validate input data format
- Ensure proper program termination

---

## 🤝 Support

For technical support, bug reports, or feature requests:
- Review the documentation in the `docs/` directory
- Check the testing guide in `tests/README.md`
- Examine the source code for implementation details

**Version**: 2.0.0  
**Last Updated**: July 2025  
**Compatibility**: C++11 and later

---

## Contributions
Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a new branch for your feature or fix
3. Make your changes and commit them
4. Push to your fork
5. Create a pull request with a clear description of your changes
6. Wait for review and feedback
7. Address any comments or suggestions
8. Once approved, your changes will be merged into the main branch

Thank you for your interest in improving the School Management System! Your contributions help make this project better for everyone.