# School Management System - Developer Guide

**Version**: 2.0.0  
**Last Updated**: July 2025  
**Architecture**: Unified Person-based System

## Quick Start for Developers

### Requirements
- C++11 or later compiler (GCC, Clang, MSVC)
- Console/terminal access
- Basic knowledge of OOP concepts

### Setup
```bash
git clone <repository>
cd school-management-system
mkdir build
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe
```

## Project Architecture

### Unified Design Philosophy
The system uses a **single inheritance hierarchy** with unified ID management:

```
Person (Abstract Base)
├── Student (No additional IDs)
├── Teacher (+ subject field)
└── Staff (+ designation field)
```

### Key Design Principles
1. **One ID System**: All persons use `Person::id` (no separate IDs per type)
2. **Polymorphism**: Virtual functions handle type-specific behavior
3. **Static Counting**: Each class tracks its own instances
4. **File Persistence**: Unified save/load for all types

## Code Organization

### Directory Structure
```
src/
├── main.cpp              # Application entry point
├── Person.cpp            # Base class implementation
├── Student.cpp           # Student class
├── Teacher.cpp           # Teacher class
├── Staff.cpp             # Staff class
├── Database_handler.cpp  # File I/O operations
└── Utility.cpp           # Helper functions

include/
├── Person.h              # Base class header
├── Student.h             # Student header
├── Teacher.h             # Teacher header
├── Staff.h               # Staff header
├── Database_handler.h    # File I/O header
└── Utility.h             # Helper functions header

tests/
├── UnitTest.cpp          # Component testing
└── IntegrationTest.cpp   # System testing
```

### Core Classes

#### Person (Abstract Base)
```cpp
class Person {
protected:
    int id;              // Unified ID for all types
    string name, phone, address;
    int age;
    string type;         // "Student", "Teacher", "Staff"
public:
    // Pure virtual methods
    virtual void printDetails() = 0;
    virtual void get_specific_inputs() = 0;
    virtual int get_by_id(int id, Person** data) = 0;
    
    // Common methods
    void get_common_inputs();  // Gets name, age, phone, address
    int getId(), setId(int);   // Unified ID management
    // ... other getters/setters
};
```

#### Derived Classes
- **Student**: Uses only inherited features (no additional attributes)
- **Teacher**: Adds `string subject` for teaching subject
- **Staff**: Adds `string designation` for job role

## Development Environment Setup

### Build Configuration
```bash
# Main application
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe

# Unit tests
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp -o build/UnitTest.exe

# Integration tests
g++ -std=c++11 -Iinclude tests/IntegrationTest.cpp src/*.cpp -o build/IntegrationTest.exe
```

### IDE Setup

#### Visual Studio Code
1. Install C++ extension
2. Configure tasks.json for building
3. Configure launch.json for debugging

#### CLion
1. Open project root directory
2. Configure C++ compiler settings
3. Configure run configurations for main and test executables

## Architecture Details

### Design Patterns Used

#### 1. Inheritance Hierarchy
```
Person (Abstract Base Class)
├── Student (Concrete Implementation)
├── Teacher (Concrete Implementation - adds subject)
└── Staff (Concrete Implementation - adds designation)
```

#### 2. Template Method Pattern
- `printDetails()` - Pure virtual method with type-specific implementations
- `get_specific_inputs()` - Virtual method for type-specific data input
- Common interface with specialized behavior

#### 3. Static Factory Pattern
- Static counting mechanism in each class
- Static methods for object tracking and retrieval
- Unified ID generation system

### Key Classes and Responsibilities

#### Person (Abstract Base)
- **Purpose**: Common interface and shared functionality
- **Key Features**:
  - Unified ID system (`Person::id`)
  - Common attributes (name, age, phone, address, type)
  - Pure virtual methods for polymorphism
  - Static count management

#### Student Class
- **Purpose**: Student entity management
- **Key Features**:
  - Inherits all Person functionality
  - No additional attributes (demonstrates pure inheritance)
  - Implements required virtual methods

#### Teacher Class
- **Purpose**: Teacher entity management  
- **Key Features**:
  - Adds subject management
  - Subject-specific input/output handling
  - Maintains unified ID system

#### Staff Class
- **Purpose**: Staff entity management
- **Key Features**:
  - Adds designation management
  - Designation-specific input/output handling
  - Maintains unified ID system

#### Database Handler
- **Purpose**: Data persistence layer
- **Key Features**:
  - File I/O operations for all person types
  - Unified save/load system
  - Error handling and validation

#### Utility Class
- **Purpose**: Helper functions and UI formatting
- **Key Features**:
  - Console formatting and colors
  - Input validation
  - Menu display systems
  - Static-only design (no instantiation)

## Coding Standards

### Naming Conventions
- **Classes**: PascalCase (e.g., `Person`, `DatabaseHandler`)
- **Methods**: camelCase (e.g., `getName()`, `setAddress()`)
- **Variables**: camelCase (e.g., `id`, `phoneNumber`)
- **Constants**: UPPER_SNAKE_CASE (e.g., `MAX_STUDENTS`)
- **Files**: Match class names (e.g., `Person.h`, `Person.cpp`)

### Code Style
- **Indentation**: 4 spaces (no tabs)
- **Braces**: Opening brace on same line
- **Line Length**: Maximum 100 characters
- **Comments**: Use `//` for single line, `/* */` for multi-line

### Memory Management
- Use RAII principles
- Avoid raw pointers where possible
- Always pair `new` with `delete`
- Initialize all variables
- Use smart pointers when appropriate

## Testing Framework

### Test Organization
```
tests/
├── UnitTest.cpp          # Individual class tests
└── IntegrationTest.cpp   # System workflow tests
```

### Test Execution
```bash
# Build tests
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp -o build/UnitTest.exe

# Run tests
cd build
.\UnitTest.exe
.\IntegrationTest.exe
```

### Test Guidelines
- Test all public methods
- Include edge cases and error conditions
- Use descriptive test names
- Keep tests independent
- Verify both positive and negative scenarios

## Development Workflow

### Getting Started
1. **Setup Environment**: Install C++ compiler and tools
2. **Clone Repository**: Get latest codebase
3. **Build Project**: Compile main application and tests
4. **Run Tests**: Verify everything works correctly
5. **Start Development**: Make changes and test iteratively

### Best Practices
- **Test-Driven Development**: Write tests before implementation
- **Code Reviews**: Review all changes before merging
- **Documentation**: Keep docs updated with code changes
- **Version Control**: Use meaningful commit messages
- **Continuous Testing**: Run tests frequently during development

### Common Tasks
```bash
# Clean build
rm -rf build/*
mkdir -p build

# Quick build and test
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe && cd build && .\sms.exe

# Debug build
g++ -std=c++11 -g -Iinclude src/*.cpp -o build/sms_debug.exe
```

## Troubleshooting

### Build Issues
- **Missing Headers**: Check include paths with `-I` flag
- **Linker Errors**: Verify all source files are included
- **Compilation Errors**: Check C++11 compatibility

### Runtime Issues
- **Segmentation Faults**: Use debugger to trace memory issues
- **File Access**: Ensure proper permissions for data directory
- **Input Validation**: Check user input handling

### Common Solutions
- **Clean Build**: Delete build directory and recompile
- **Check Dependencies**: Verify all source files are included
- **Debug Mode**: Compile with `-g` flag for debugging symbols

---

**End of Developer Guide**
