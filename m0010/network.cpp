#include "network.h"


ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4)
{
    ip add = 0;
    add = oct1;
    add = add << 8;
    add = add | oct2;
    add = add << 8;
    add = add | oct3;
    add = add << 8;
    add = add | oct4;

    return add;
}

void extractOctets(ip address, octet &oct1, octet &oct2, octet &oct3, octet &oct4)
{
    octet mask1 = 255;
    oct4 = address & mask1;
    address = address >> 8;
    oct3 = address & mask1;
    address = address >> 8;
    oct2 = address & mask1;
    address = address >> 8;
    oct1 = address & mask1;
}


networkType getNetworkType(ip address)
{
    octet oct1, oct2, oct3, oct4;
    extractOctets(address, oct1, oct2, oct3, oct4);
    if (oct1 >= 1 && oct1 <= 127)
    {
        if (oct1 == 10)
        {
            return APRIVATE;
        }
        if (oct1 == 127)
        {
            return LOCALHOST;
        }
        return CLASSA;
    }
    if (oct1 >= 128 && oct1 <= 191)
    {
        if (oct1 == 172)
        {
            if (oct2 >= 16 && oct2 <= 31)
            {
                return BPRIVATE;
            }
            return CLASSB;
        }
        return CLASSB;
    }
    if (oct1 >= 192 && oct1 <= 223)
    {
        if (oct1 == 192)
        {
            if (oct2 == 168)
            {
                return CPRIVATE;
            }
            return CLASSC;
        }
        return CLASSC;
    }
    if (oct1 >= 224 && oct1 <= 239)
    {
        return CLASSD;
    }
    if (oct1 > 239)
    {
        return CLASSE;
    }
    return INVALID;
}
