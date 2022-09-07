#pragma once

using namespace std;

#include <iostream>
#include <fstream>
#include <iomanip>


int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    if (argc != 3)
    {
        cout << "Usage: m0020.exe inputfile outputfile" << endl;
        return 0;
    }
    fin.open(argv[1]);
    if(!fin.is_open())
    {
        cout << "Unable to open the input file: " << argv[1] << endl;
        return 0;
    }
    fout.open(argv[2]);
    if(!fout.is_open())
    {
        cout << "Unable to open the output file: " << argv[2] << endl;
        return 0;
    }








    fin.close();
    fout.close();
    return 0;
}