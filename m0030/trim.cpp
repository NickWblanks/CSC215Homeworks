#include "trim.h"

void cTrim(char cstring[], trimType method)
{
    ofstream fout;
    int i = 0;
    if (method == FRONT || method == BOTH)
    {
        while (isspace(cstring[i]))
        {
            i++;
        }
        strcpy(cstring, &cstring[i]);
    }
    if (method == END || method == BOTH)
    {
        char nStr[1] = "";
        size_t j = strlen(cstring);
        j = j- 1;
        cout << j << endl;
        while(isspace(cstring[j]))
        {
            j--;
        }
        cout << j << endl;
        i = 0;
        strcat(cstring, nStr);
        cout << cstring << endl;
        char filename[30] = "checkFile.txt";
        fout.open("checkFile.txt");
        fout << cstring << endl;

    }
}

void sTrim(string &sString, trimType method)
{
    int count = 0;
    string::iterator it;
    if (method == FRONT || method == BOTH)
    {
        it = sString.begin();
        while (isspace(*it))
        {
            count++;
            it++;
        }
        sString = sString.substr(count);
    }
}

