#include "..\catch.hpp"
#include "newton.h"

double f(double x)
{
    return pow(x, 3) + 2;
}
double FP(double x)
{
    return 3 * pow(x, 2);
}

TEST_CASE("newtonApprox - x^3 +2")
{
    double epsilon = .001;
    double n = 2;
    double ans;
    ans = newtonApprox(n, f, FP, epsilon);
    REQUIRE(fabs(f(ans)) <= epsilon);
}

double h(double x)
{
    return 2 * x;
}

double HP(double x)
{
    return 2;
}

TEST_CASE("newtonApprox - 2x")
{
    double epsilon = .0001;
    double n = 3;
    double ans;
    ans = newtonApprox(n, h, HP, epsilon);
    REQUIRE(fabs(h(ans)) <= epsilon);
}