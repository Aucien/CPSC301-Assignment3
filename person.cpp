#include "person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person(){
    
}

string Person::getFirstName() {
  return firstName;  
}

void Person::setFirstName(string fName){
    firstName = fName;
}

void Person::setLastName(string lName){
    lastName = lName;
}

string Person::getLastName(){
    return lastName;
}

void Person::setEmployeeId (int id){
    employeeID = id;
}

int Person::getEmployeeId (){
    return employeeID;
}

void Person::setCompanyName (string coName){
    companyName = coName;
}

string Person::getCompanyName(){
    return companyName;
}

void Person::setPayRate (float rate){
    payRate = rate;
}

float Person::getPayRate (){
    return payRate;
}

void Person::setHoursWorked(float hours){
    hoursWorked = hours;
}

float Person::getHoursWorked(){
    return hoursWorked;
}

float Person::totalPay(){
    return hoursWorked * payRate;
}

string Person::fullName(){
    string name = firstName + " " + lastName;
    return name;
}