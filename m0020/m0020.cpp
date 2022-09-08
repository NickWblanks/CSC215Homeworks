#pragma once

using namespace std;

#include <iostream>
#include <fstream>
#include <iomanip>


float minArray(float *array, int size);

float maxArray(float* array, int size);


int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    int size = 0;
    float *array = nullptr;
    float fNums;
    int dataNum;
    int i = 0;
    int j = 0;
    int k = 0;
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
    fin >> dataNum;
    while (fin >> fNums)
    {
        size++;
    }
    array = new (nothrow) float [size];
    if (array == nullptr)
    {
        cout << "Unable to allocate memory" << endl;
        return 0;
    }
    if (dataNum > size)
    {
        dataNum = size;
    }
    if (dataNum < size)
    {
        size = dataNum;
    }
    fin.clear();
    fin.seekg(0, ios::beg);
    fin >> fNums;
    while (fin >> array[i])
    {
        i++;
    }
    fout << dataNum << endl;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 5 && k < size; j++)
        {
            fout << setprecision(5);
            fout << right << setw(15) << array[k];
            k++;
        }
        fout << endl;
    }
    delete[] array;







    fin.close();
    fout.close();
    return 0;
}



float minArray(float *array, int size)
{
    int i;
    int min = 0;
    for (i = 0; i < size - 1; i++)
    {
        if (array[min] > array[i+1])
        {
            min = i + 1;
        }
    }
    return array[min];
}


float maxArray(float* array, int size)
{
    int i;
    int max = 0;
    for (i = 0; i < size - 1; i++)
    {
        if (array[max] < array[i + 1])
        {
            max = i + 1;
        }
    }
    return array[max];
}