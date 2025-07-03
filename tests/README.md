# Test Documentation - School Management System

## Overview

This directory contains comprehensive test suites for the School Management System, designed to validate both individual components and system-wide integration. The tests are built to match the latest unified Person-based architecture with polymorphic operations and centralized ID management.

## Test Architecture

The testing framework validates:
- **Unified ID System**: All person types use `Person::id` for consistent identification
- **Polymorphic Operations**: Virtual function calls through base class pointers
- **Memory Management**: Proper object lifecycle with static count tracking
- **Input/Output Systems**: User interface utilities and file persistence
- **Cross-platform Compatibility**: Works on Windows, Linux, and macOS

## Test Suites

### 1. Unit Tests (`UnitTest.exe`)
**Purpose**: Validates individual components and class functionality

**Test Coverage**:
- **Person Basic Functionality**: Setters/getters, unified ID system
- **Student Specific Functionality**: Student class implementation with unified architecture
- **Teacher Specific Functionality**: Teacher class with subject management and unified IDs
- **Staff Specific Functionality**: Staff class with designation management and unified IDs
- **Polymorphism Testing**: Virtual function behavior through base pointers
- **Utility Functions Testing**: Console formatting, input validation, color management
- **Edge Cases Testing**: Boundary conditions, empty values, special characters

**Features**:
- Interactive test execution with optional pausing
- Detailed step-by-step validation
- Sub-test breakdown for complex operations
- Success/failure reporting with specific details
- Colored console output for clarity

**Location**: `build/UnitTest.exe`
**Run Command**: `.\UnitTest.exe` (from build directory)

### 2. Integration Tests (`IntegrationTest.exe`)
**Purpose**: Validates complete system workflow and component integration

**Test Coverage**:
- **Complete Person Workflow**: End-to-end person creation, management, and polymorphic operations
- **Utility System Integration**: Complete UI system testing with menu generation
- **Data File System Integration**: File operations, directory structure, database handler
- **Complete System Simulation**: Full user session simulation with all components
- **Stress and Performance Testing**: Large dataset handling, memory management validation

**Features**:
- Real-world usage simulation
- File system validation and auto-creation
- Database operation testing with unified architecture
- Performance testing with 100+ objects
- Complete system lifecycle simulation
- Cross-platform file path handling

**Location**: `build/IntegrationTest.exe`
**Run Command**: `.\IntegrationTest.exe` (from build directory)

### 3. Test Runner (`RunTests.bat`)
**Purpose**: Convenient test execution with menu-driven interface

**Features**:
- Automated test suite execution
- Menu-driven test selection
- Batch execution of all tests
- Clear result reporting

**Location**: `build/RunTests.bat`
**Run Command**: `.\RunTests.bat` (from build directory)

## Key Testing Features

### Unified Architecture Validation
- Tests verify the unified `Person::id` system works across all derived classes
- Validates polymorphic behavior with the new architecture
- Ensures proper static count management in constructors/destructors

### Advanced Test Framework
1. **Interactive Mode**: Optional pausing after each test for detailed examination
2. **Detailed Reporting**: Pre-test descriptions explain what will be tested
3. **Step-by-step Execution**: Progress tracking for complex operations
4. **Sub-test Granularity**: Individual validation of complex test scenarios
5. **Color-coded Results**: Visual success/failure indication
6. **Comprehensive Summary**: Statistics and overall system health reporting

### Cross-platform Support
- Tests work on Windows, Linux, and macOS
- Proper file path handling for different operating systems
- Cross-platform directory and file operations

## Compilation Instructions

### Prerequisites
- C++11 or later compiler
- Standard library support
- Console/terminal access for colored output

### Unit Tests
```bash
g++ -std=c++11 -Iinclude tests/UnitTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp -o build/UnitTest.exe
```

### Integration Tests
```bash
g++ -std=c++11 -Iinclude tests/IntegrationTest.cpp src/Person.cpp src/Student.cpp src/Teacher.cpp src/Staff.cpp src/Utility.cpp src/Database_handler.cpp -o build/IntegrationTest.exe
```

### Batch Compilation
```bash
# Compile both test suites
cd build
g++ -std=c++11 -I../include ../tests/UnitTest.cpp ../src/Person.cpp ../src/Student.cpp ../src/Teacher.cpp ../src/Staff.cpp ../src/Utility.cpp -o UnitTest.exe

g++ -std=c++11 -I../include ../tests/IntegrationTest.cpp ../src/Person.cpp ../src/Student.cpp ../src/Teacher.cpp ../src/Staff.cpp ../src/Utility.cpp ../src/Database_handler.cpp -o IntegrationTest.exe
```

## Quick Start Guide

### Step 1: Navigate to Build Directory
```bash
cd build
```

### Step 2: Run Tests
```bash
# Run unit tests
.\UnitTest.exe

# Run integration tests  
.\IntegrationTest.exe

# Or use the test runner for both
.\RunTests.bat
```

### Step 3: Interactive Options
Both test executables will ask:
- **"Do you want to pause after each test? (y/n):"**
  - Answer `y` for detailed step-by-step examination
  - Answer `n` for fast continuous execution

## Expected Test Results

### Successful Unit Test Output
```
SCHOOL MANAGEMENT SYSTEM - UNIT TEST SUITE
===========================================
Total tests run: 7
Tests passed: 7 [PASS]
Tests failed: 0 [FAIL]
Success rate: 100%
ALL UNIT TESTS PASSED! The system components are working correctly.
```

### Successful Integration Test Output
```
SCHOOL MANAGEMENT SYSTEM - INTEGRATION TEST SUITE
==================================================
Total integration tests run: 5
Tests passed: 5 [PASS]
Tests failed: 0 [FAIL]
Success rate: 100%
ALL INTEGRATION TESTS PASSED!
System is ready for production use!
```

## Test Maintenance

The test suites are designed to:
- Automatically adapt to changes in the unified architecture
- Validate new features added to the Person hierarchy
- Ensure backward compatibility with existing functionality
- Provide comprehensive validation for deployment readiness

Regular test execution is recommended:
- **Before deployment**: Run both test suites
- **After code changes**: Run relevant test suite
- **Performance validation**: Use integration stress tests
- **Architecture changes**: Run full test battery

For development workflow, these tests provide confidence that the unified Person-based architecture is working correctly and all components integrate properly.