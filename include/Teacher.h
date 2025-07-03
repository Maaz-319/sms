#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : public Person {
private:
    string subject;
    static int count;
public:
    Teacher();  // Default constructor
    void printDetails() override;
    int get_by_id(int id, Person **data) override;
    bool save(Person **data, int index = -1);
    static int getCount();
    
    string getSubject() const;
    
    void setSubject(const string& subject) override;

    virtual void get_specific_inputs() override;
    
    virtual ~Teacher();
};
#endif
