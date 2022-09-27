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

void inFcheck(char *fileName);

void outFcheck(char* fileName);

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    string header;
    if (argc != 4)
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFile sortMethod" << endl;
        return 0;
    }
    fin.open(argv[1]);
    fout.open(argv[2]);
    inFcheck(argv[1]);
    outFcheck(argv[2]);
    getline(fin, header, '\n');




    fin.close();
    fout.close();
    return 0;
}


void inFcheck(char *fileName)
{
    ifstream file;
    file.open(fileName);
    if (!file.is_open())
    {
        cout << "Unable to open input file: " << fileName << endl;
        exit;

    }
}


void outFcheck(char* fileName)
{
    ofstream file2;
    file2.open(fileName);
    if (!file2.is_open())
    {
        cout << "Unable to open output file: " << fileName << endl;
        exit;
    }
}

