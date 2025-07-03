# School Management System - Developer Guide

## Table of Contents
1. [Development Environment Setup](#development-environment-setup)
2. [Project Architecture](#project-architecture)
3. [Code Organization](#code-organization)
4. [Class Design Patterns](#class-design-patterns)
5. [Build System](#build-system)
6. [Testing Framework](#testing-framework)
7. [Contributing Guidelines](#contributing-guidelines)
8. [Debugging Guidelines](#debugging-guidelines)
9. [Code Examples](#code-examples)
10. [Future Enhancements](#future-enhancements)

## Development Environment Setup

### Required Tools
- **C++ Compiler**: GCC 7.0+ with C++17 support (recommended: tdm64-1 10.3.0)
- **Git**: For version control
- **IDE/Editor**: Visual Studio Code, CLion, Code::Blocks, or any C++ compatible editor

### Development Dependencies
- **Standard Libraries**: C++17 (for filesystem support in tests)
- **Console I/O**: Standard iostream, conio.h for interactive features
- **File System**: Standard C++ filesystem library for integration tests

### Project Dependencies
No external libraries required - the project uses only standard C++ libraries.

### IDE Configuration

#### Visual Studio Code
1. Install C/C++ extension by Microsoft
2. Configure `tasks.json` for building:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build Main App",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-I", "include",
                "-o", "build/sms.exe",
                "src/start.cpp",
                "src/Person.cpp",
                "src/Student.cpp", 
                "src/Teacher.cpp",
                "src/Staff.cpp",
                "src/Utility.cpp",
                "src/Database_handler.cpp"
            ],
            "group": "build",
            "presentation": {
                "echo": true,
                "reveal": "always"
            }
        }
    ]
}
```

3. Configure `launch.json` for debugging:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug SMS",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/sms.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb"
        }
    ]
}
```
```

#### CLion
1. Open project root directory
2. Configure C++ compiler settings
3. Configure run configurations for main and test executables

## Project Architecture

### Design Patterns

#### 1. Inheritance Hierarchy (Template Method Pattern)
```
Person (Abstract Base Class)
├── Student (Concrete Implementation)
├── Teacher (Concrete Implementation)
└── Staff (Concrete Implementation)
```

#### 2. Static Factory Pattern
- Static counting mechanism in each class
- Static methods for object tracking and retrieval

#### 3. Utility Pattern (Static Methods)
- `Utility`: Static helper functions for console formatting
- No instantiation required - all methods are static

#### 4. Template Method Pattern
- `printDetails()` - Pure virtual method implemented differently by each derived class
- Common interface with specialized implementations

### Class Responsibilities

#### Person Class (Abstract Base)
- **Purpose**: Abstract base class defining common interface
- **Responsibilities**:
  - Common attribute management (name, age, phone, address, type)
  - Pure virtual `printDetails()` method
  - Virtual polymorphic methods (`printType()`, `getId()`)
  - Static counting of all Person-derived objects
  - Virtual setters for derived class attributes (empty implementations)

#### Student Class
- **Purpose**: Represents students in the system
- **Responsibilities**:
  - Student-specific ID management (`stud_id`)
  - Implementation of abstract methods from Person
  - Static counting of Student objects
  - Database operations (save, get_by_id)
  - Type identification as "Student"

#### Teacher Class
- **Purpose**: Represents teachers in the system
- **Responsibilities**:
  - Teacher-specific attributes (teacher_id, subject)
  - Implementation of abstract methods from Person
  - Static counting of Teacher objects  
  - Database operations (save, get_by_id)
  - Type identification as "Teacher"

#### Staff Class
- **Purpose**: Represents administrative staff
- **Responsibilities**:
  - Staff-specific attributes (staff_id, designation)
  - Implementation of abstract methods from Person
  - Static counting of Staff objects
  - Database operations (save, get_by_id)
  - Type identification as "Staff"

#### Utility Class
- **Purpose**: Console formatting and display utilities
- **Responsibilities**:
  - Line and header formatting (`print_line`, `print_header`)
  - Menu box display (`print_menu_box`)
  - Message formatting (success, error, info messages)
  - No instantiation (constructor deleted)

#### Database Handler
- **Purpose**: File-based data persistence
- **Responsibilities**:
  - Save Person arrays to files (`save_person`)
  - Read Person objects from files (`read_person`)
  - File organization by type (students.txt, teachers.txt, staff.txt)

#### Student Class
- **Purpose**: Represents student entities
- **Responsibilities**:
  - Student-specific attributes (grade, GPA)
  - Academic record management
  - Grade validation logic

#### Teacher Class
- **Purpose**: Represents teaching staff
- **Responsibilities**:
  - Subject assignment management
  - Salary information handling
  - Teaching-specific validation

#### Staff Class
- **Purpose**: Represents administrative staff
- **Responsibilities**:
  - Department assignment
  - Administrative role management
  - Staff-specific validation

#### DatabaseHandler Class
- **Purpose**: Data persistence layer
- **Responsibilities**:
  - File I/O operations
  - Data serialization/deserialization
  - Error handling for file operations
  - Data integrity maintenance

#### Utility Class
- **Purpose**: Helper functions and utilities
- **Responsibilities**:
  - Input validation
  - String manipulation
  - ID generation
  - Common formatting operations

## Code Organization

### Directory Structure
```
├── include/               # Header files
│   ├── Person.h          # Base class definition
│   ├── Student.h         # Student class definition
│   ├── Teacher.h         # Teacher class definition
│   ├── Staff.h           # Staff class definition
│   ├── Database_handler.h # Database operations
│   └── Utility.h         # Helper functions
├── src/                  # Implementation files
│   ├── Person.cpp        # Base class implementation
│   ├── Student.cpp       # Student class implementation
│   ├── Teacher.cpp       # Teacher class implementation
│   ├── Staff.cpp         # Staff class implementation
│   ├── Database_handler.cpp # Database implementation
│   ├── Utility.cpp       # Helper implementations
│   └── start.cpp         # Main application entry
├── tests/                # Unit tests
│   ├── PersonTest.cpp    # Base class tests
│   ├── StudentTest.cpp   # Student class tests
│   ├── DatabaseTest.cpp  # Database operation tests
│   └── UtilityTest.cpp   # Utility function tests
├── data/                 # Data files (runtime)
├── docs/                 # Documentation
└── scripts/              # Build and utility scripts
```

### Header File Guidelines
- Use include guards (`#ifndef`, `#define`, `#endif`)
- Forward declarations where possible
- Minimal includes in headers
- Clear documentation for public interfaces

### Source File Guidelines
- Include corresponding header first
- Group includes logically (system, project)
- Implement all declared methods
- Use appropriate namespaces

## Coding Standards

### Naming Conventions
- **Classes**: PascalCase (e.g., `DatabaseHandler`)
- **Methods**: camelCase (e.g., `getName()`, `setAddress()`)
- **Variables**: camelCase (e.g., `studentId`, `phoneNumber`)
- **Constants**: UPPER_SNAKE_CASE (e.g., `MAX_STUDENTS`)
- **Files**: Match class names (e.g., `Person.h`, `Person.cpp`)

### Code Style
- **Indentation**: 4 spaces (no tabs)
- **Braces**: Opening brace on same line
- **Line Length**: Maximum 100 characters
- **Comments**: Use `//` for single line, `/* */` for blocks

### Best Practices
1. **RAII**: Resource Acquisition Is Initialization
2. **const-correctness**: Use const wherever possible
3. **Exception Safety**: Handle errors gracefully
4. **Memory Management**: Use smart pointers when appropriate
5. **Single Responsibility**: Each class has one purpose

### Example Code Style
```cpp
class Person {
private:
    string name;
    int id;
    string phone;
    string address;

public:
    // Default constructor
    Person();
    
    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
    
    // Setters with validation
    void setName(const string& newName);
    void setId(int newId);
    
    // Virtual methods
    virtual void displayInfo() const;
};
```

## Build System

### G++ Compilation
The project uses direct G++ compilation for cross-platform building:

```bash
# Source files location
SOURCES="src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Database_handler.cpp src/Utility.cpp"
INCLUDE_PATH="-Iinclude"

# Main executable
g++ -std=c++11 $INCLUDE_PATH src/start.cpp $SOURCES -o build/sms

# Test executables
g++ -std=c++11 $INCLUDE_PATH tests/UnitTest.cpp $SOURCES -o build/UnitTest
g++ -std=c++11 $INCLUDE_PATH tests/IntegrationTest.cpp $SOURCES -o build/IntegrationTest
```

### Build Commands
```bash
# Debug build
mkdir build
g++ -g -std=c++11 -Wall -Wextra -Iinclude src/*.cpp -o build/sms

# Release build
g++ -O3 -DNDEBUG -std=c++11 -Iinclude src/*.cpp -o build/sms

# Clean build
rm -rf build/*
```

### Compiler Flags
- **Debug**: `-g -O0 -Wall -Wextra`
- **Release**: `-O3 -DNDEBUG`
- **Warnings**: `-Wall -Wextra -Wpedantic`

## Testing Framework

### Unit Testing Structure
Each major class has corresponding test files:

#### Test Naming Convention
- Test files: `ClassNameTest.cpp`
- Test functions: `test_MethodName()`
- Setup functions: `setUp()`, `tearDown()`

#### Test Implementation Example
```cpp
// PersonTest.cpp
#include <cassert>
#include <iostream>
#include "../include/Person.h"

void test_PersonSettersAndGetters() {
    Person person;
    person.setName("John Doe");
    person.setId(123);
    
    assert(person.getName() == "John Doe");
    assert(person.getId() == 123);
    std::cout << "✓ Person setters and getters test passed\n";
}

int main() {
    test_PersonSettersAndGetters();
    // ... other tests
    return 0;
}
```

### Running Tests
```bash
# Build and run all tests
cd build
make RunTests
./RunTests

# Run specific test
./PersonTest
./StudentTest
./DatabaseTest
./UtilityTest
```

### Test Coverage Goals
- **Unit Tests**: 90%+ code coverage
- **Integration Tests**: Critical workflows
- **Edge Cases**: Invalid inputs, boundary conditions
- **Error Handling**: File I/O failures, memory issues

## Contributing Guidelines

### Development Workflow
1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/new-feature`)
3. **Implement** changes following coding standards
4. **Add** appropriate tests
5. **Run** all tests to ensure nothing breaks
6. **Commit** with descriptive messages
7. **Push** changes and create a pull request

### Commit Message Format
```
type(scope): description

[optional body]

[optional footer]
```

**Types**: feat, fix, docs, style, refactor, test, chore

**Examples**:
```
feat(student): add GPA validation in setter method
fix(database): handle missing file gracefully
docs(readme): update build instructions
test(utility): add phone validation tests
```

### Code Review Process
1. All changes require review
2. Tests must pass
3. Documentation must be updated
4. No breaking changes without discussion

### Branch Naming
- `feature/feature-name`: New features
- `bugfix/issue-description`: Bug fixes
- `hotfix/critical-fix`: Critical issues
- `docs/documentation-update`: Documentation changes

## Debugging and Profiling

### Debugging Techniques
1. **Print Debugging**: Use `std::cout` for simple cases
2. **GDB**: GNU Debugger for detailed analysis
3. **Valgrind**: Memory leak detection (Linux/macOS)
4. **Static Analysis**: Use tools like `cppcheck`

### Common Debugging Scenarios
```cpp
// Memory debugging
void debugMemoryUsage() {
    std::cout << "Creating student object..." << std::endl;
    Student* student = new Student();
    std::cout << "Student created at: " << student << std::endl;
    // ... use student
    delete student;
    std::cout << "Student deleted" << std::endl;
}

// File I/O debugging
void debugFileOperations() {
    std::ifstream file("data/students.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << strerror(errno) << std::endl;
        return;
    }
    std::cout << "File opened successfully" << std::endl;
}
```

### Performance Profiling
- **Timing**: Use `<chrono>` for performance measurement
- **Memory**: Monitor heap usage
- **File I/O**: Track read/write operations

## Deployment

### Release Preparation
1. **Version Tagging**: Use semantic versioning (e.g., v1.2.3)
2. **Changelog**: Document all changes
3. **Testing**: Full regression test suite
4. **Documentation**: Update all documentation

### Packaging
```bash
# Create release package
mkdir release
cp build/SchoolManagementSystem release/
cp -r data release/
cp README.md release/
tar -czf SchoolManagementSystem-v1.0.0.tar.gz release/
```

### Distribution
- **GitHub Releases**: Tagged releases with binaries
- **Documentation**: Include user manual and API docs
- **Dependencies**: List all requirements

## Future Enhancements

### Planned Features
1. **Database Integration**: MySQL/SQLite support
2. **GUI Interface**: Qt or web-based interface
3. **Reporting System**: PDF generation
4. **Multi-user Support**: User authentication
5. **Network Features**: Client-server architecture

### Architecture Improvements
1. **Design Patterns**: Observer pattern for updates
2. **Configuration**: JSON/XML configuration files
3. **Logging**: Structured logging system
4. **Validation**: Comprehensive data validation framework

### Technology Upgrades
1. **C++ Standards**: Migrate to C++17/20
2. **Build System**: Advanced build automation scripts
3. **Testing**: Google Test framework integration
4. **CI/CD**: Automated testing and deployment

### Performance Optimizations
1. **Caching**: In-memory data caching
2. **Indexing**: Fast search capabilities
3. **Compression**: Data file compression
4. **Multithreading**: Parallel operations

### Security Enhancements
1. **Encryption**: Data encryption at rest
2. **Authentication**: User access control
3. **Audit Logging**: Track all operations
4. **Input Sanitization**: Prevent injection attacks

## Troubleshooting Development Issues

### Build Problems
- **Missing Headers**: Check include paths with -I flag
- **Linker Errors**: Verify library dependencies and object files
- **Compilation Issues**: Clean build directory and recompile

### Runtime Issues
- **Segmentation Faults**: Use debugger to trace
- **Memory Leaks**: Run with Valgrind
- **File Permissions**: Check directory access rights

### IDE Problems
- **IntelliSense**: Regenerate compile_commands.json
- **Debugging**: Verify debug symbols are included
- **Extensions**: Update C++ language extensions