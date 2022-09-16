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
        cstring[j+1] = '\0';
    }
}

void sTrim(string &sString, trimType method)
{
    size_t count2;
    int count = 0;
    string::iterator it;
    if (method == FRONT || method == BOTH)
    {
        it = sString.begin();
        while (it != sString.end() && isspace(*it))
        {
            count++;
            it++;
        }
        sString = sString.substr(count);
    }
    if (method == END || method == BOTH)
    {
        size_t size = sString.size();
        it = sString.end();
        it--;
        count2 = size;
        while (it != sString.begin() && isspace(*it))
        {
            count2--;
            it--;
        }
        sString.erase(count2);
    }
}

