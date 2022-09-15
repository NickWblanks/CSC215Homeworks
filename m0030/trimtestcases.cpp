#include "..//catch.hpp"
#include "trim.h"


//TEST_CASE("cTrim - testing c strings with no ws on either end")
//{
//    char theString[100] = "Catch with Sections!";
//    char theAnswer[100] = "Catch with Sections!";
//    CHECK(strcmp(theString, theAnswer) == 0);
//
//    SECTION("Front - just a phrase")
//    {
//        cTrim(theString, FRONT);
//        CHECK(strcmp(theString, theAnswer) == 0);
//    }
//    SECTION("End - just a phrase")
//    {
//        cTrim(theString, END);
//        CHECK(strcmp(theString, theAnswer) == 0);
//    }
//    SECTION("Both - just a phrase")
//    {
//        cTrim(theString, BOTH);
//        CHECK(strcmp(theString, theAnswer) == 0);
//    }
//}
//
//
TEST_CASE("sTrim - testing strings with no ws on either end")
{
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    REQUIRE(theString == theAnswer);
    
    SECTION("Front - just a phrase")
    {
        sTrim(theString, FRONT);
        REQUIRE(theAnswer == theString);
    }
    SECTION("End - just a phrase")
    {
        sTrim(theString, END);
        REQUIRE(theAnswer == theString);
    }
    SECTION("Both - just a phrase")
    {
        sTrim(theString, BOTH);
        REQUIRE(theAnswer == theString);
    }
}



TEST_CASE("cTrim - testing ws on front end")
{
    char str1[20] = "   four";
    char str2[20] = "four";
    char str3[20] = "   four";

    SECTION("Front - cstrings")
    {
        cTrim(str1, FRONT);
        CHECK(strcmp(str1, str2) == 0);
    }
    /*SECTION("End - cstrings")
    {
        cTrim(str1, END);
        CHECK(strcmp(str1, str3) == 0);
    }*/
    /*SECTION("Both - cstrings")
    {
        cTrim(str1, BOTH);
        CHECK(strcmp(str1, str2) == 0);
    }*/
}

TEST_CASE("cTrim - testing ws on end")
{
    char str1[20] = "ninetnine   ";
    char str2[20] = "ninetnine";
    char str3[20] = " boo ";
    char str4[20] = " boo";

    SECTION("End - cstrings")
    {
        cTrim(str1, END);
        REQUIRE(strcmp(str1, str2) == 0);
    }
}


TEST_CASE("sTrim - testing strings with ws on FRONT")
{
    string theString = "    pain";
    string theAnswer = "pain";
    string answer2 = "    pain";

    SECTION("Front - just a phrase")
    {
        sTrim(theString, FRONT);
        REQUIRE(theAnswer == theString);
    }
    SECTION("End - just a phrase")
    {
        sTrim(theString, END);
        REQUIRE(theString == answer2);
    }
    SECTION("Both - just a phrase")
    {
        sTrim(theString, BOTH);
        REQUIRE(theAnswer == theString);
    }
}

TEST_CASE("sTrim - front1")
{
    string str1 = "Star Wars    ";
    string str2 = "Star Wars    ";
    sTrim(str1, FRONT);
    REQUIRE(str1 == str2);
}

TEST_CASE("sTrim - front2")
{
    string str1 = "";
    string str2 = "";
    sTrim(str1, FRONT);
    REQUIRE(str1 == str2);
}

TEST_CASE("sTrim - front3")
{
    string str1 = "           ";
    string str2 = "";
    sTrim(str1, FRONT);
    REQUIRE(str1 == str2);
}