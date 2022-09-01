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
    return INVALID;
}

