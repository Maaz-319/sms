# School Management System - Developer Guide

## Quick Start for Developers

### Requirements
- C++11 or later compiler (GCC, Clang, MSVC)
- Console/terminal access
- Basic knowledge of OOP concepts

### Setup
```bash
git clone "https://github.com/Maaz-319/sms.git"
cd sms
mkdir build
g++ -std=c++11 -Iinclude src/*.cpp -o build/sms.exe
```

## Project Architecture

### Unified Design Philosophy
The system uses a **single inheritance hierarchy** with unified ID management:

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

#### 1. Template Method Pattern
- `printDetails()` - Pure virtual method with type-specific implementations
- `get_specific_inputs()` - Virtual method for type-specific data input
- Common interface with specialized behavior

#### 2. Static Factory Pattern
- Static counting mechanism in each class
- Static methods for object tracking and retrieval
- Unified ID generation system

### Key Classes and Responsibilities

```
Person (Abstract Base)
├── Student (No additional IDs)
├── Teacher (+ subject field)
└── Staff (+ designation field)
```

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
  - Static-only design


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
---

> This Documentation is AI Gen, So Misatakes are Possible !