#include "trim.h"

void cTrim(char cstring[], trimType method)
{
    int i = 0;
    if (method == FRONT)
    {
        while (isspace(cstring[i]))
        {
            i++;
        }
        strcpy(cstring, &cstring[i]);
    }
}

void sTrim(string sString, trimType method)
{
}

