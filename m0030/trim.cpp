#include "trim.h"

void cTrim(char cstring[], trimType method)
{
    //j is size of array
    int j = int(strlen(cstring));
    int i = 0;
    if (method == END || method == BOTH)
    {
        j = j - 1;
        if (j < 0)
        {
            cstring[j + 1] = '\0';
        }
        if (j == 0)
        {
            cstring[j] = '\0';
        }
        while (j >= 0 && isspace(cstring[j]))
        {
            j--;
        }
        cstring[j + 1] = '\0';
    }
    if (method == FRONT || method == BOTH)
    {
        
        while (i < j && isspace(cstring[i]) )
        {
            i++;
        }
        strcpy(cstring, &cstring[i]);
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
        if (it != sString.begin())
        {
            it--;
        }
        count2 = size;
        while (it != sString.begin() && isspace(*it))
        {
            count2--;
            it--;
        }
        if (it == sString.begin() && count2 > 0)
        {
            count2--;
        }
        sString.erase(count2);
    }
}

