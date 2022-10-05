#pragma once

#include <cmath>
#include <functional>
#include <iostream>

using namespace std;


double newtonApprox(double guess, function<double(double)>funct,function<double(double)>functP, double epsilon);