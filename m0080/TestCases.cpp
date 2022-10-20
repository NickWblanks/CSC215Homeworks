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

TEST_CASE("Size - empty list")
{
    sortedSingle list;
    CHECK(list.empty() == true);
    CHECK(list.size() == 0);
}

TEST_CASE("Size - list with 1 item")
{
    sortedSingle list;
    list.insert(1);
    CHECK(list.empty() == false);
    CHECK(list.size() == 1);
}

TEST_CASE("Find - empty list")
{
    sortedSingle list;
    CHECK(list.find(10) == false);
}

TEST_CASE("Find - list without item")
{
    sortedSingle list;
    list.insert(10);
    list.insert(20);
    list.insert(40);
    CHECK(list.find(30) == false);
}

TEST_CASE("Find - list with item")
{
    sortedSingle list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    CHECK(list.find(30) == true);
}

TEST_CASE("retrievePosition - empty list")
{
    sortedSingle list;
    CHECK(list.retrievePosition(10) == 0);
}

TEST_CASE("retrievePosition - list without item")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    CHECK(list.retrievePosition(4) == 0);
}

TEST_CASE("retrievePosition - list with item")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    CHECK(list.retrievePosition(4) == 4);
}

TEST_CASE("retrievePosition - list with only the item")
{
    sortedSingle list;
    list.insert(99);
    CHECK(list.retrievePosition(99) == 1);
}
