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