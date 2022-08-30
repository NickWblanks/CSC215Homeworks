#include "..\\catch.hpp"
#include "network.h"


TEST_CASE("compressOctets - testing classb ip adress")
{
    octet oct1 = 151;
    octet oct2 = 159;
    octet oct3 = 15;
    octet oct4 = 20;
    ip ipaddress;
    ipaddress = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(ipaddress == 2543783700);
}


TEST_CASE("compressOctets - testing classa ip address")
{
    octet oct1 = 125;
    octet oct2 = 78;
    octet oct3 = 13;
    octet oct4 = 32;
    ip ipaddress = compressOctets(oct1, oct2, oct3, oct4);
    REQUIRE(ipaddress == 2102267168);
}

