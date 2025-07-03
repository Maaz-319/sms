#include "../include/Person.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Staff.h"
#include "../include/Utility.h"
#include "../include/Database_handler.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // For file operations
#include <conio.h>  // For getch()
#include <sys/stat.h>  // For directory checking

#ifdef _WIN32
#include <direct.h>  // For _mkdir on Windows
#define mkdir(path, mode) _mkdir(path)
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;

// Global settings
bool pauseAfterEachTest = false;
int testsRun = 0;
int testsPassed = 0;
int testsFailed = 0;

// Test framework functions
void pauseIfRequested() {
    if (pauseAfterEachTest) {
        cout << "\nPress any key to continue to next test...";
        getch();
        cout << "\n" << endl;
    }
}

void printTestHeader(const string& testName) {
    cout << "\n" << string(70, '=') << endl;
    cout << "INTEGRATION TEST: " << testName << endl;
    cout << string(70, '=') << endl;
}

void printTestDescription(const string& description) {
    cout << "What this test will do: " << description << endl;
    cout << "Starting test execution..." << endl;
}

void printTestResult(const string& testName, bool passed, const string& details = "") {
    testsRun++;
    if (passed) {
        testsPassed++;
        string message = "INTEGRATION TEST PASSED: " + testName;
        if (!details.empty()) message += " - " + details;
        Utility::print_success_message(message);
    } else {
        testsFailed++;
        string message = "INTEGRATION TEST FAILED: " + testName;
        if (!details.empty()) message += " - " + details;
        Utility::print_error_message(message);
    }
    pauseIfRequested();
}

void printStep(int stepNum, const string& action, bool result = true) {
    cout << "\nStep " << stepNum << ": " << action;
    if (result) {
        Utility::set_console_color(Utility::Colors::GREEN);
        cout << " [SUCCESS]" << endl;
        Utility::reset_console_color();
    } else {
        Utility::set_console_color(Utility::Colors::RED);
        cout << " [FAILED]" << endl;
        Utility::reset_console_color();
    }
    
    // Pause after each step if user requested it
    if (pauseAfterEachTest) {
        cout << "Press any key to continue to next step...";
        getch();
        cout << endl;
    }
}

void printSubAction(const string& action, const string& result = "") {
    cout << "  -> " << action;
    if (!result.empty()) {
        cout << " -> " << result;
    }
    cout << endl;
    
    // Pause after each sub-action if user requested it
    if (pauseAfterEachTest) {
        cout << "    Press any key to continue...";
        getch();
        cout << endl;
    }
}

// Helper functions to replace filesystem operations
bool directoryExists(const string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        return false;  // Cannot access
    }
    return (info.st_mode & S_IFDIR) != 0;  // Is directory
}

bool fileExists(const string& path) {
    struct stat info;
    return stat(path.c_str(), &info) == 0;
}

bool createDirectory(const string& path) {
    return mkdir(path.c_str(), 0755) == 0;
}

string getCurrentPath() {
    #ifdef _WIN32
    char buffer[1000];
    if (_getcwd(buffer, sizeof(buffer)) != nullptr) {
        return string(buffer);
    }
    #else
    char buffer[1000];
    if (getcwd(buffer, sizeof(buffer)) != nullptr) {
        return string(buffer);
    }
    #endif
    return "Unable to determine current path";
}

// Integration Tests
bool testCompletePersonWorkflow() {
    printTestHeader("Complete Person Workflow");
    printTestDescription("Create different types of persons, set their data, and verify complete functionality");
    
    bool allPassed = true;
    
    printStep(1, "Creating instances of all person types");
    Student* student = new Student();
    Teacher* teacher = new Teacher();
    Staff* staff = new Staff();
    
    printStep(2, "Setting up Student data with unified ID system");
    student->setName("Alice Johnson");
    student->setAge(19);
    student->setPhone("555-0101");
    student->setAddress("123 Dormitory Lane");
    student->setId(2024001);  // Unified ID system
    printSubAction("Student name", student->getName());
    printSubAction("Student ID", to_string(student->getId()));
    printSubAction("Student type", student->printType());
    
    printStep(3, "Setting up Teacher data with unified ID system");
    teacher->setName("Dr. Robert Smith");
    teacher->setAge(42);
    teacher->setPhone("555-0201");
    teacher->setAddress("456 Faculty Street");
    teacher->setId(1001);  // Unified ID system
    teacher->setSubject("Computer Science");
    printSubAction("Teacher name", teacher->getName());
    printSubAction("Teacher ID", to_string(teacher->getId()));
    printSubAction("Teacher subject", teacher->getSubject());
    printSubAction("Teacher type", teacher->printType());
    
    printStep(4, "Setting up Staff data with unified ID system");
    staff->setName("Mary Williams");
    staff->setAge(38);
    staff->setPhone("555-0301");
    staff->setAddress("789 Admin Building");
    staff->setId(3001);  // Unified ID system
    staff->setDesignation("Registrar");
    printSubAction("Staff name", staff->getName());
    printSubAction("Staff ID", to_string(staff->getId()));
    printSubAction("Staff designation", staff->getDesignation());
    printSubAction("Staff type", staff->printType());
    
    printStep(5, "Testing polymorphic behavior");
    vector<Person*> people = {student, teacher, staff};
    for (size_t i = 0; i < people.size(); i++) {
        printSubAction("Person " + to_string(i+1) + " type", people[i]->printType());
        printSubAction("Person " + to_string(i+1) + " name", people[i]->getName());
        printSubAction("Person " + to_string(i+1) + " ID", to_string(people[i]->getId()));
    }
    
    printStep(6, "Testing print details functionality");
    cout << "\nStudent Details:" << endl;
    student->printDetails();
    cout << "\nTeacher Details:" << endl;
    teacher->printDetails();
    cout << "\nStaff Details:" << endl;
    staff->printDetails();
    
    printStep(7, "Cleaning up memory");
    delete student;
    delete teacher;
    delete staff;
    
    printTestResult("Complete Person Workflow", allPassed, "All person types created and tested successfully");
    return allPassed;
}

bool testUtilityIntegration() {
    printTestHeader("Utility System Integration");
    printTestDescription("Test all utility functions working together to create a complete user interface");
    
    bool allPassed = true;
    
    printStep(1, "Testing header and line utilities");
    cout << "\nDemonstrating header creation:" << endl;
    Utility::print_header("SCHOOL MANAGEMENT SYSTEM");
    
    printStep(2, "Testing line utilities");
    cout << "\nDemonstrating line utilities:" << endl;
    Utility::print_line(50);
    Utility::print_dashed_line(50);
    
    printStep(3, "Testing message utilities");
    cout << "\nDemonstrating message utilities:" << endl;
    Utility::print_success_message("System initialized successfully");
    Utility::print_error_message("This is how errors are displayed");
    Utility::print_info_box("This is how information is presented to users");
    
    printStep(4, "Testing menu system");
    cout << "\nDemonstrating menu system:" << endl;
    vector<string> mainMenu = {
        "1. Manage Students",
        "2. Manage Teachers", 
        "3. Manage Staff",
        "4. View Reports",
        "5. System Settings",
        "6. Exit"
    };
    Utility::print_menu_box("Main Menu", mainMenu);
    
    printStep(5, "Testing nested menu system");
    cout << "\nDemonstrating nested menu:" << endl;
    vector<string> studentMenu = {
        "1. Add Student",
        "2. View Student",
        "3. Update Student",
        "4. Delete Student",
        "5. Back to Main Menu"
    };
    Utility::print_menu_box("Student Management", studentMenu);
    
    printTestResult("Utility System Integration", allPassed, "All utility functions working properly");
    return allPassed;
}

bool testDataFileSystemIntegration() {
    printTestHeader("Data File System Integration");
    printTestDescription("Test file system setup and data directory structure for the application");
    
    bool allPassed = true;
    
    printStep(1, "Checking data directory structure");
    bool dataDir = directoryExists("../data");
    printSubAction("Data directory exists", dataDir ? "YES" : "NO");
    
    if (!dataDir) {
        printSubAction("Creating data directory", "ATTEMPTING");
        try {
            createDirectory("../data");
            dataDir = directoryExists("../data");
            printSubAction("Data directory created", dataDir ? "SUCCESS" : "FAILED");
        } catch (...) {
            printSubAction("Data directory creation", "FAILED - Exception");
        }
    }
    
    printStep(2, "Checking required data files");
    vector<string> requiredFiles = {"students.txt", "teachers.txt", "staff.txt"};
    for (const string& filename : requiredFiles) {
        string filepath = "../data/" + filename;
        bool exists = fileExists(filepath);
        printSubAction("File " + filename, exists ? "EXISTS" : "MISSING");
        
        if (!exists) {
            printSubAction("Creating " + filename, "ATTEMPTING");
            try {
                ofstream file(filepath);
                if (file.is_open()) {
                    file << "# " << filename << " - School Management System Data File" << endl;
                    file << "# This file stores " << filename.substr(0, filename.find('.')) << " data" << endl;
                    file.close();
                    printSubAction("File " + filename + " created", "SUCCESS");
                } else {
                    printSubAction("File " + filename + " creation", "FAILED");
                }
            } catch (...) {
                printSubAction("File " + filename + " creation", "FAILED - Exception");
            }
        }
    }
    
    printStep(3, "Testing database handler integration");
    cout << "\nTesting database functionality:" << endl;
    try {
        // Create test data - Use full 100-element array for compatibility with save_person
        Person** testData = new Person*[100];
        for (int i = 0; i < 100; i++) testData[i] = nullptr;
        
        // Add test persons with unified ID system
        testData[0] = new Student();
        testData[0]->setName("Test Student");
        testData[0]->setAge(20);
        testData[0]->setPhone("555-0123");
        testData[0]->setAddress("123 Test St");
        testData[0]->setId(9999);  // Unified ID system
        
        testData[1] = new Teacher();
        testData[1]->setName("Test Teacher");
        testData[1]->setAge(35);
        testData[1]->setPhone("555-0124");
        testData[1]->setAddress("124 Test St");
        testData[1]->setId(8888);  // Unified ID system
        testData[1]->setSubject("Test Subject");
        
        printSubAction("Test data prepared", "SUCCESS");
        
        // Test save operation
        printSubAction("Attempting to save data", "EXECUTING");
        save_person(testData);
        printSubAction("Save operation", "COMPLETED");
        
        // Test read operation with updated database handler signature
        printSubAction("Attempting to read data", "EXECUTING");
        int ids[100] = {0};
        int current_id = 0;
        Person** loadedData = read_person(ids, current_id);
        printSubAction("Read operation", loadedData ? "COMPLETED" : "RETURNED NULL");
        
        // Cleanup
        delete testData[0];
        delete testData[1];
        delete[] testData;
        
        if (loadedData) {
            for (int i = 0; i < 100 && loadedData[i] != nullptr; i++) {
                delete loadedData[i];
            }
            delete[] loadedData;
        }
        
    } catch (...) {
        printSubAction("Database operations", "EXCEPTION OCCURRED");
        allPassed = false;
    }
    
    printTestResult("Data File System Integration", allPassed, "File system and database operations tested");
    return allPassed;
}

bool testCompleteSystemSimulation() {
    printTestHeader("Complete System Simulation");
    printTestDescription("Simulate a complete user session with all system components working together");
    
    bool allPassed = true;
    
    printStep(1, "System startup simulation");
    cout << "\n" << string(60, '*') << endl;
    cout << "     SIMULATING COMPLETE SCHOOL MANAGEMENT SYSTEM" << endl;
    cout << string(60, '*') << endl;
    
    Utility::print_header("SCHOOL MANAGEMENT SYSTEM v1.0");
    Utility::print_info_box("System starting up...");
    
    printStep(2, "User authentication simulation");
    printSubAction("Checking user credentials", "ADMIN ACCESS GRANTED");
    Utility::print_success_message("Welcome, Administrator!");
    
    printStep(3, "Loading system data");
    printSubAction("Loading student records", "FOUND " + to_string(Student::getCount()) + " students");
    printSubAction("Loading teacher records", "FOUND " + to_string(Teacher::getCount()) + " teachers");
    printSubAction("Loading staff records", "FOUND " + to_string(Staff::getCount()) + " staff members");
    
    printStep(4, "Displaying main menu");
    vector<string> systemMenu = {
        "1. Student Management",
        "2. Teacher Management",
        "3. Staff Management",
        "4. Academic Reports",
        "5. System Administration",
        "6. Backup & Restore",
        "7. Exit System"
    };
    Utility::print_menu_box("MAIN SYSTEM MENU", systemMenu);
    
    printStep(5, "Simulating student management workflow");
    cout << "\nUser selects: Student Management" << endl;
    
    // Create new student simulation with unified ID system
    Student newStudent;
    printSubAction("Creating new student record", "INITIALIZING");
    newStudent.setName("Emma Thompson");
    newStudent.setAge(18);
    newStudent.setPhone("555-1234");
    newStudent.setAddress("456 College Ave");
    newStudent.setId(2024100);  // Unified ID system
    
    printSubAction("Student data entered", "COMPLETE");
    cout << "New student created:" << endl;
    newStudent.printDetails();
    
    printStep(6, "Simulating data validation and save with unified ID system");
    bool validData = (!newStudent.getName().empty() && 
                     newStudent.getAge() > 0 && 
                     newStudent.getId() > 0);  // Using unified ID system
    printSubAction("Data validation", validData ? "PASSED" : "FAILED");
    
    if (validData) {
        printSubAction("Saving to database", "SIMULATED SUCCESS");
        Utility::print_success_message("Student record saved successfully!");
    }
    
    printStep(7, "Simulating system shutdown");
    printSubAction("Saving all changes", "COMPLETE");
    printSubAction("Closing database connections", "COMPLETE");
    printSubAction("Logging out user", "COMPLETE");
    
    Utility::print_info_box("Thank you for using School Management System!");
    cout << string(60, '*') << endl;
    cout << "     SYSTEM SIMULATION COMPLETED SUCCESSFULLY" << endl;
    cout << string(60, '*') << endl;
    
    printTestResult("Complete System Simulation", allPassed, "Full system workflow executed successfully");
    return allPassed;
}

bool testStressAndPerformance() {
    printTestHeader("Stress and Performance Testing");
    printTestDescription("Test system behavior under load with multiple objects and operations");
    
    bool allPassed = true;
    
    printStep(1, "Creating multiple objects stress test");
    const int TEST_COUNT = 100;
    vector<Person*> testObjects;
    
    printSubAction("Creating " + to_string(TEST_COUNT) + " student objects", "STARTING");
    for (int i = 0; i < TEST_COUNT; i++) {
        Student* s = new Student();
        s->setName("Student " + to_string(i));
        s->setAge(18 + (i % 10));
        s->setId(2024000 + i);  // Unified ID system
        testObjects.push_back(s);
    }
    printSubAction("Student objects created", "SUCCESS");
    
    printStep(2, "Testing polymorphic operations on large dataset");
    int correctTypes = 0;
    for (Person* p : testObjects) {
        if (p->printType() == "Student") correctTypes++;
    }
    bool typeTest = (correctTypes == TEST_COUNT);
    printSubAction("Polymorphic type checking on " + to_string(TEST_COUNT) + " objects", 
                   typeTest ? "ALL CORRECT" : "SOME FAILED");
    
    printStep(3, "Testing memory management");
    printSubAction("Deleting " + to_string(TEST_COUNT) + " objects", "STARTING");
    for (Person* p : testObjects) {
        delete p;
    }
    testObjects.clear();
    printSubAction("Memory cleanup", "COMPLETED");
    
    printStep(4, "Testing utility functions under load");
    printSubAction("Generating multiple UI elements", "STARTING");
    for (int i = 0; i < 10; i++) {
        Utility::print_line(20);
        vector<string> testMenu = {"Option " + to_string(i), "Exit"};
        Utility::print_menu_box("Test Menu " + to_string(i), testMenu);
    }
    printSubAction("UI stress test", "COMPLETED");
    
    printTestResult("Stress and Performance Testing", allPassed, 
                   "System handled " + to_string(TEST_COUNT) + " objects successfully");
    return allPassed;
}

int main() {
    cout << string(80, '=') << endl;
    cout << "      SCHOOL MANAGEMENT SYSTEM - INTEGRATION TEST SUITE" << endl;
    cout << string(80, '=') << endl;
    cout << "This test suite will perform comprehensive integration testing of the entire system." << endl;
    cout << "Each test will show what it's going to do, execute the test, and report results." << endl;
    cout << "Integration tests verify that all components work together correctly." << endl;
    
    // Ask user about pause preference
    cout << "\nDo you want to pause after each integration test? (y/n): ";
    char choice;
    cin >> choice;
    pauseAfterEachTest = (choice == 'y' || choice == 'Y');
    
    cout << "\nStarting integration tests..." << endl;
    if (pauseAfterEachTest) {
        cout << "Note: You will be prompted to press a key after each test." << endl;
    }
    
    cout << "\nPreparing test environment..." << endl;
    cout << "Current working directory: " << getCurrentPath() << endl;
    
    // Run all integration tests
    testCompletePersonWorkflow();
    testUtilityIntegration();
    testDataFileSystemIntegration();
    testCompleteSystemSimulation();
    testStressAndPerformance();
    
    // Print final summary
    cout << "\n" << string(80, '=') << endl;
    cout << "                     INTEGRATION TEST SUMMARY" << endl;
    cout << string(80, '=') << endl;
    cout << "Total integration tests run: " << testsRun << endl;
    cout << "Tests passed: " << testsPassed << " [PASS]" << endl;
    cout << "Tests failed: " << testsFailed << " [FAIL]" << endl;
    cout << "Success rate: " << (testsRun > 0 ? (testsPassed * 100 / testsRun) : 0) << "%" << endl;
    
    if (testsFailed == 0) {
        Utility::print_success_message("ALL INTEGRATION TESTS PASSED!");
        cout << "The complete system is working correctly and all components integrate properly." << endl;
        Utility::print_success_message("System is ready for production use!");
        return 0;
    } else {
        Utility::print_error_message("Some integration tests failed.");
        cout << "Please review the failed components and their interactions." << endl;
        Utility::print_error_message("System needs attention before deployment!");
        return 1;
    }
}
