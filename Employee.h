#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
using namespace std;

//base class
class Employee
{
 protected:
 string name;
 double wage;
 double hours;
 public:
 // Create a new employee
 Employee (string theName, double theWage, double theHours);
 
 //member functions to get name and calculate pay
 double calcPay() const;
 string getName () const;
};

//derived class
class Manager: public Employee
{
    private:
    double bonus;
    
    public:
     Manager(string theName, double theWage, double theHours, double theBonus);
     
     double calcPay() const;
};



#endif // EMPLOYEE_H