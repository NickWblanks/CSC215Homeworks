#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct EmployeeData
{
    int id;
    string firstN;
    string lastN;
    double salary;
    double bonus;
};

bool inFcheck(char *fileName);

bool outFcheck(char* fileName);

bool sortById(EmployeeData left, EmployeeData right);

bool sortBySalary(EmployeeData left, EmployeeData right);

bool sortByNames(EmployeeData left, EmployeeData right);



int optionCheck(char* option);


int main(int argc, char** argv)
{
    cout << fixed << setprecision(2);
    bool check1, check2;
    EmployeeData records;
    ifstream fin;
    ofstream fout;
    string header, holder;
    int i = 0;
    int j = 0;
    int k = 0;
    int check = 0;
    vector<EmployeeData> v;
    vector<EmployeeData>::iterator vit;
    if (argc != 4)
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFile sortMethod" << endl;
        return 0;
    }
    check = optionCheck(argv[3]);
    if (check == 0)
    {
        cout << "Invalid Sort Method:" << endl;
        cout << "-i - sort by id" << endl;
        cout << "-n - sort by name" << endl;
        cout << "-s - sort by salary" << endl;
        return 0;
    }
    fin.open(argv[1]);
    fout.open(argv[2]);
    check1 = inFcheck(argv[1]);
    if (check1 == false)
    {
        return 0;
    }
    check2 = outFcheck(argv[2]);
    if (check2 == false)
    {
        return 0;
    }
    getline(fin, header, '\n');
    while (getline(fin, holder, '\n'))
    {
        i++;
    }
    fin.clear();
    fin.seekg(0, ios::beg);
    getline(fin,header,'\n');
    while( j < i)
    {
        fin >> records.id;
        fin.ignore();
        getline(fin, records.firstN, ',');
        getline(fin, records.lastN, ',');
        fin >> records.salary;
        fin.ignore();
        fin >> records.bonus;
        v.push_back(records);
        v.at(j) = {records};
        j++;
    }
    if (check == 1)
    {
        sort(v.begin(), v.end(), sortById);
    }
    if (check == 2)
    {
        sort(v.begin(), v.end(), sortByNames);
    }
    if (check == 3)
    {
        sort(v.begin(), v.end(), sortBySalary);
    }

    j = 0;
    fout << header << endl;
    while(j < i)
    {
        fout << fixed << showpoint << setprecision(2);
        fout << v[j].id << "," << v[j].firstN << "," << v[j].lastN <<
          "," << v[j].salary << "," << v[j].bonus << endl;
        j++;
    }
    fin.close();
    fout.close();
    return 0;
}


bool inFcheck(char *fileName)
{
    ifstream file;
    file.open(fileName);
    if (!file.is_open())
    {
        cout << "Unable to open input file: " << fileName << endl;
        return false;
    }
    return true;
}


bool outFcheck(char* fileName)
{
    ofstream file2;
    file2.open(fileName);
    if (!file2.is_open())
    {
        cout << "Unable to open output file: " << fileName << endl;
        return false;
    }
    return true;
}

bool sortById(EmployeeData left, EmployeeData right)
{
    if (left.id < right.id)
    {
        return true;
    }
    return false;
}

bool sortBySalary(EmployeeData left, EmployeeData right)
{
    if (left.salary > right.salary)
    {
        return true;
    }
    return false;
}

bool sortByNames(EmployeeData left, EmployeeData right)
{
    if (left.lastN < right.lastN)
    {
        return true;
    }
    if (left.lastN == right.lastN)
    {
        if (left.firstN < right.firstN)
        {
            return true;
        }
        return false;
    }
    return false;
}


int optionCheck(char *option)
{
    if (strcmp(option, "-i") == 0)
    {
        return 1;
    }
    if (strcmp(option, "-n") == 0)
    {
        return 2;
    }
    if (strcmp(option, "-s") == 0)
    {
        return 3;
    }
    return 0;
}

