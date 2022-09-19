#pragma once
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;


void printFile(fstream& file);

bool applyBonus(fstream& file, int empID);

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
    


    file.close();
    return 0;
}

void printFile(fstream& file)
{
}

bool applyBonus(fstream& file, int empID)
{
}
