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
    string empID(argv[2]);
    int num = stoi(empID);
    printFile(file);
    


    file.close();
    return 0;
}

void printFile(fstream& file)
{
    empData Records;
    int i = 0;
    file.seekg(0, ios::end);
    size_t fsize = file.tellg() / sizeof(empData);
    file.clear();
    file.seekg(0, ios::beg);
    cout << showpoint << fixed << setprecision(2) << endl;
    while (i < fsize)
    {
        file.read((char*) &Records, sizeof(empData));
        cout << setw(7) << Records.id << " " << left << setw(20) << Records.firstName << setw(40) << Records.lastName << right << " Salary: " << setw(10) << Records.salary << " Bonus: " << setw(10) << Records.bonus << endl;
        i++;
    }
}

bool applyBonus(fstream& file, int empID)
{
    return true;
}
