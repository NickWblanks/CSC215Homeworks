#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

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


TEST_CASE("Insert - empty list")
{
    sortedSingle list;
    CHECK(list.insert(99) == true);
}

TEST_CASE("Insert - duplicate at front")
{
    sortedSingle list;
    list.insert(99);
    list.insert(90);
    CHECK(list.insert(90) == true);
    list.print(cout, ", ");
}

TEST_CASE("Insert - at front")
{
    sortedSingle list;
    list.insert(99);
    CHECK(list.insert(90) == true);
}

TEST_CASE("Insert - at end")
{
    sortedSingle list;
    list.insert(99);
    list.insert(90);
    CHECK(list.insert(100) == true);
}

TEST_CASE("Insert - middle")
{
    sortedSingle list;
    list.insert(99);
    list.insert(90);
    CHECK(list.insert(95) == true);
}

TEST_CASE("Print - cout")
{
    sortedSingle listC;
    listC.insert(1);
    listC.insert(2);
    listC.insert(4);
    listC.insert(8);
    listC.insert(16);
    listC.print(cout, ", ");
}

TEST_CASE("Print - fout")
{
    ofstream fout;
    fout.open("printText.txt");
    sortedSingle listC;
    listC.insert(1);
    listC.insert(2);
    listC.insert(4);
    listC.insert(8);
    listC.insert(16);
    listC.print(fout, ", ");
}

TEST_CASE("Print - sout")
{
    ostringstream sout;
    sortedSingle listC;
    listC.insert(1);
    listC.insert(2);
    listC.insert(4);
    listC.insert(8);
    listC.insert(16);
    listC.print(sout, ", ");
    REQUIRE(sout.str() == "1, 2, 4, 8, 16");
}

TEST_CASE("Remove - empty list")
{
    sortedSingle list;
    CHECK(list.remove(90) == false);
}

TEST_CASE("Remove - front of list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.remove(1);
    CHECK(list.size() == 3);
    CHECK(list.find(1) == false);
}

TEST_CASE("Remove - middle of list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.remove(3);
    CHECK(list.size() == 3);
    CHECK(list.find(3) == false);
}

TEST_CASE("Remove - end of list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.remove(4);
    CHECK(list.size() == 3);
}

TEST_CASE("Remove - not in list")
{
    sortedSingle list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.remove(5);
    CHECK(list.size() == 4);
}

TEST_CASE("Remove - last list")
{
    sortedSingle list;
    list.insert(1);
    list.remove(1);
    CHECK(list.empty() == true);
}

TEST_CASE("Clear - empty list")
{
    sortedSingle list;
    list.clear();
    CHECK(list.empty() == true);
}

TEST_CASE("Clear - list with 1 item")
{
    sortedSingle list;
    list.insert(1);
    list.clear();
    CHECK(list.empty() == true);
}

TEST_CASE("Clear - list with many items")
{
    sortedSingle list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.clear();
    CHECK(list.empty() == true);
}

TEST_CASE("copyConstructor - empty list") //should make a copy list that is empty
{
    sortedSingle list1;
    sortedSingle cList(list1);
    CHECK(cList.empty() == true);
}

TEST_CASE("copyConstructor - list with 1 item")
{
    sortedSingle list1;
    list1.insert(10);
    sortedSingle cList(list1);
    CHECK(cList.empty() == false);
    CHECK(cList.find(10) == true);
    CHECK(cList.size() == 1);
}

TEST_CASE("copyConstructor - list with 2 item")
{
    sortedSingle list1;
    list1.insert(10);
    list1.insert(20);
    sortedSingle cList(list1);
    CHECK(cList.empty() == false);
    CHECK(cList.find(10) == true);
    CHECK(cList.find(20) == true);
    CHECK(cList.size() == 2);
}

TEST_CASE("copyConstructor - list with many items")
{
    sortedSingle list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    sortedSingle cList(list1);
    cList.print(cout);
    CHECK(cList.size() == 6);
    cList.print(cout);
}



