#include <string>
#include<cstdlib>
using namespace std;
#include "Employee.h"

//defining base class functions
Employee::Employee (string theName, double theWage, double theHours)
{
 name = theName;
 wage = theWage;
 hours = theHours;
}
double Employee::calcPay() const
{
 return wage * hours;
}
string Employee::getName () const
{
 return name;
}

//defining derived class
Manager::Manager(string theName, double theWage, double theHours, double theBonus)
    : Employee(theName, theWage, theHours), bonus(theBonus) {}

//Calculating manager pay as well as bonus
double Manager::calcPay() const 
{
    
    double basePay = Employee::calcPay();
    return basePay + bonus;
}
