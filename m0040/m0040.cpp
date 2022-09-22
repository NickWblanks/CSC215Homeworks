#pragma once
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;


void printFile(fstream& file);

bool applyBonus(fstream& file, int empID);

struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};

int main(int argc, char **argv)
{
    fstream file;
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID" << endl;
        return 0;
    }
    file.open(argv[1], ios::in | ios::out | ios::ate | ios::binary);
    if (!file.is_open())
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        return 0;
    }
    int num = atoi(argv[2]);
    printFile(file);
    cout << endl;
    bool foundID = applyBonus(file, num);
    if (foundID == true)
    {
        cout << "Employee ID " << num << " has been updated." << endl;
    }
    else
    {
        cout << "Employee ID " << num << " was not found." << endl;
    }
    cout << endl;
    printFile(file);
    file.close();
    return 0;
}

void printFile(fstream& file)
{
    file.clear();
    file.seekg(0, ios::beg);
    empData Records;
    cout << showpoint << fixed << setprecision(2);
    while (file.read((char*) &Records, sizeof(empData)))
    {
        cout << setw(7) << Records.id << " " 
             << left << setw(20) << Records.firstName
             << setw(40) << Records.lastName << right
             << " Salary: " << setw(10) << Records.salary << " Bonus: "
             << setw(10) << Records.bonus << endl;
    }
}

bool applyBonus(fstream& file, int empID)
{
    double Bonus = 500.00;
    int i = 0;
    empData newRec;
    file.clear();
    file.seekg(0, ios::beg);
    while (file.read((char*) &newRec, sizeof(empData)))
    {
        if (newRec.id == empID)
        {
            newRec.bonus += Bonus;
            //file.seekp(0, ios::beg);
            file.seekp(i * sizeof(empData), ios::beg);
            file.write((char*) &newRec, sizeof(empData));
            return true;
        }
        i++;
    }
    return false;
}
