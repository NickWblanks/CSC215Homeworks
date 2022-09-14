#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

enum trimType{ BOTH, FRONT, END};

void cTrim(char cstring[], trimType method);

void sTrim(string sString, trimType method);

