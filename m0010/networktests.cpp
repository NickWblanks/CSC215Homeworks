#include "..\\catch.hpp"
#include "network.h"



//compressOctets -----------------------------------------------------------

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


TEST_CASE("compressOctets - testing another classb ip address")
{
    octet oct1 = 128;
    octet oct2 = 90;
    octet oct3 = 101;
    octet oct4 = 45;
    ip ipaddress = compressOctets(oct1, oct2, oct3, oct4);
    REQUIRE(ipaddress == 2153407789);
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


TEST_CASE("compressOctets - testing classc ip address")
{
    octet oct1 = 202;
    octet oct2 = 22;
    octet oct3 = 101;
    octet oct4 = 72;
    ip ipaddress = compressOctets(oct1, oct2, oct3, oct4);
    REQUIRE(ipaddress == 3390465352);
}



TEST_CASE("compressOctets - testing classD ip address")
{
    octet oct1 = 228;
    octet oct2 = 119;
    octet oct3 = 11;
    octet oct4 = 35;
    ip ipaddress = compressOctets(oct1, oct2, oct3, oct4);
    REQUIRE(ipaddress == 3833006883);
}


TEST_CASE("compressOctets - testing classE ip address")
{
    octet oct1 = 251;
    octet oct2 = 111;
    octet oct3 = 66;
    octet oct4 = 84;
    ip ipaddress = compressOctets(oct1, oct2, oct3, oct4);
    REQUIRE(ipaddress == 4218372692);
}

// extractOctets ----------------------------------------------------------


TEST_CASE("extractOctets - extracting class a address")
{
    ip address = 2102267168;
    octet oct1;
    octet oct2;
    octet oct3;
    octet oct4;

    extractOctets(address, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 125);
    CHECK(oct2 == 78);
    CHECK(oct3 == 13);
    CHECK(oct4 == 32);
}


TEST_CASE("extractOctets - extracting class b address - example test.")
{
    ip address = 2543783700;
    octet oct1;
    octet oct2;
    octet oct3;
    octet oct4;

    extractOctets(address, oct1, oct2, oct3, oct4);
    CHECK(oct1 == 151);
    CHECK(oct2 == 159);
    CHECK(oct3 == 15);
    CHECK(oct4 == 20);
}