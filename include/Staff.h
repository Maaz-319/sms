#ifndef STAFF_H
#define STAFF_H
#include "Person.h"

class Staff : public Person
{
private:
    string designation;
    static int count;

public:
    Staff();
    void printDetails() override;
    int get_by_id(int id, Person **data) override;
    bool save(Person **data, int index = -1);
    static int getCount();
    
    virtual string getDesignation();
    
    void setDesignation(const string& designation) override;
    virtual void get_specific_inputs() override;
    virtual ~Staff();
};
#endif
