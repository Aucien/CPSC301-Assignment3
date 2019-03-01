#include "person.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void readData(vector <Person> &list){
    ifstream data;
    string fname;
    string lname;
    int id;
    string company;
    float hours;
    float rate;
    Person p1;
    data.open("input.txt");
    if(data){
        while(data >> fname >> lname >> id >> company >> hours >> rate){
            //cout << fname << " " << lname << " " << id << " " << company << " " << hours << " " << rate << endl;
            p1.setFirstName(fname);
            p1.setLastName(lname);
            p1.setEmployeeId(id);
            p1.setCompanyName(company);
            p1.setHoursWorked(hours);
            p1.setPayRate(rate);
            list.push_back(p1);
        }
    data.close();
    }
}

void getCompany(vector <Person> &employees, vector <string> &companyNames){
    for(int x = 0; x < employees.size(); x++){
        if(find(companyNames.begin(), companyNames.end(), employees[x].getCompanyName()) == companyNames.end()){
            companyNames.push_back(employees[x].getCompanyName());
        }
    }
}

void printHighestPaid(vector <Person> employees){
    int size = employees.size();
    float high = 0;
    float current = 0;
    Person highPaying;
    for(int x = 0; x < size; x++){
        current = employees[x].getHoursWorked() * employees[x].getPayRate();
        if (current > high){
            highPaying = employees[x];
            high = current;
        }
    }
    cout << fixed << setprecision(2) <<"Highest paid: " << highPaying.fullName()
     << "\nEmployee ID: " << highPaying.getEmployeeId()
     << "\nEmployer: " << highPaying.getCompanyName() 
     << "\nTotal Pay: $" << high << endl << endl;
} 

void separateAndSave(vector <Person> &employees, vector <string> &companyNames){
    for(int x = 0; x < companyNames.size(); x++){
        string company = companyNames[x] + ".txt";
        float total = 0;
        ofstream data;
        data.open(company);
        data << "________________________________________________" << endl;
        for(int y = 0; y < employees.size(); y++){
            if(employees[y].getCompanyName() == companyNames[x]){
                data << fixed << setprecision(2) << setw(10) << left << employees[y].getFirstName() << setw(7) << left << employees[y].getLastName()
                 << setw(4) << right << employees[y].getEmployeeId() << " " << setw(companyNames[x].size()) <<
                  employees[y].getCompanyName() << " $" << employees[y].getPayRate() * employees[y].getHoursWorked()
                  << endl;
                total += employees[y].getPayRate() * employees[y].getHoursWorked(); 
            }
        }
        data << fixed << setprecision(2) << "Total $" << total;
        data.close();
    }
}

int main() {
    vector <Person> employees;
    vector <string> companyNames;
    readData(employees);
    getCompany(employees, companyNames);
    printHighestPaid(employees);
    separateAndSave(employees, companyNames);
    return 0;
}