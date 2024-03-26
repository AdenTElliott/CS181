/*
# Author:                   Aden Elliott
# BannerID:                 001397456
# Course:                   CS 181
# Assignment:               PA4
# Date Assigned:            Monday, March 18, 2024
# Date/Time Due:            Saturday, March 30, 2024 -- 11:55 pm

# Description:              This program will exercise Object-
                            Oriented concepts with C++.

# Certification of Authenticity:
 I certify that this assignment is entirely my own work.
*/

#include <iostream>
#include "Employee.h"
#include <iomanip>
using namespace std;
#include <string>
int main()
{
    const int MAX_MANAGERS = 100;
    int numMans;
    cout<< "Enter number of managers: ";
    cin >> numMans;
    cin.ignore();
    numMans = min(numMans, MAX_MANAGERS); //to ensure no more tahn 100 managers are processed
    Manager **managers = new Manager *[numMans];
    
    //for loop to prompt user to store data
    for(int i=0; i<numMans; i++)
    {
        string name;
        double hours, wage, bonus;
        cout << "Enter manager " <<i<<" name: ";
        getline(cin, name);
        cout << "Enter manager " <<i<<" hourly wage: ";
        cin>>wage;
        cout << "Enter manager " <<i<<" hours worked: ";
        cin>>hours;
        cout << "Enter manager " <<i<<" bonus: ";
        cin>>bonus;
        cout<<endl;
        
        managers[i] = new Manager(name, wage, hours, bonus);
        cin.ignore();
    }
    
    //calculating highest pay manager
    double highestPay = 0.0;
    double total = 0.0;
    string highestPaid;
    for(int i=0; i<numMans; i++)
    {
        double pay = managers[i]->calcPay();
        total += pay;
        if (pay > highestPay) 
        {
            highestPay = pay;
            highestPaid = managers[i]->getName();
        }
    }
    
    //displaying the results
    cout << fixed << setprecision(2);
    cout<<"Highest paid manager is " << highestPaid<< " who is paid $"<<highestPay<<endl;
    cout << "Average pay is $" << (total / numMans) << endl;
    
     //De-allocating memory
     for (int i = 0; i < numMans; ++i) 
    {
        delete managers[i];
    }
    delete[] managers;

    return 0;

}