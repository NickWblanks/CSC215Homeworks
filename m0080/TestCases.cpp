#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE("Contructor")
{
    sortedSingle list1;
    CHECK(list1.empty() == true);
    CHECK(list1.size() == 0);
}

TEST_CASE("Empty - Empty list")
{
    sortedSingle List1;
    CHECK(List1.empty() == true);
}

TEST_CASE("Empty - Not an empty list")
{
    sortedSingle list2;
    list2.insert(20);
    list2.insert(40);
    list2.insert(60);
    CHECK(list2.empty() == false);
    CHECK(list2.size() == 3);
}
