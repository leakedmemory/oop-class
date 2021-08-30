#ifndef Employee_h
#define Employee_h

#include "PhysicalPerson.h"

class Employee: public PhysicalPerson
{
friend ostream &operator<<(ostream &, const Employee &);

public:
    Employee(string, unsigned long, string, double, int, int);

    double grossSalary() const;

    inline string getRegistration() const {
        return this->registration;
    }
    inline void setRegistration(string registration) { 
        this->registration = registration;
    }

    inline double getSalary() const { return this->salary; }
    inline void setSalary(double salary) { this->salary = salary; }

    inline int getMonthlyHours() const { return this->monthlyHours; }
    inline void setMonthlyHours(int monthlyHours) {
        this->monthlyHours = monthlyHours;
    }

    inline double getMonthlyWorkedHours() const {
        return this->monthlyWorkedHours;
    }
    inline void setMonthlyWorkedHours(int monthlyWorkedHours) {
        this->monthlyWorkedHours = monthlyWorkedHours;
    }

private:
    string registration;
    double salary;
    int monthlyHours;
    int monthlyWorkedHours;
};

#endif
