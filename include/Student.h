#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
private:
    static int count;
public:
    Student();
    void printDetails() override;
    int get_by_id(int id, Person **data) override;
    bool save(Person **data, int index = -1);
    static int getCount();
    

    void get_specific_inputs() override;

    virtual ~Student();
};
#endif
