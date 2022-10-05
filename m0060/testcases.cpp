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

double g(double x)
{
    return log (2*x);
}
double GP(double x)
{
    return 1 / x;
}
TEST_CASE("newtoneApprox - ln(2x)")
{
    double epsilon = 0.001;
    double n = 1;
    double ans;
    ans = newtonApprox(n, g, GP, epsilon);
    REQUIRE(fabs(g(ans)) <= epsilon);
}

double a(double x)
{
    return (13 * pow(x, 2)) - (5 * x) - 2;
}
double AP(double x)
{
    return (26 * x) + 5;
}

TEST_CASE("newtonApprox - 13x^2 - 5x -2")
{
    double epsilon = 0.001;
    double n = 2;
    double ans;
    ans = newtonApprox(n, a, AP, epsilon);
    REQUIRE(fabs(a(ans)) <= epsilon);
}

double b(double x)
{
    return exp(x) - 3;
}
double BP(double x)
{
    return exp(x);
}

TEST_CASE("newtonApprox - e^x - 3")
{
    double epsilon = 0.001;
    double n = 1;
    double ans;
    ans = newtonApprox(n, b, BP, epsilon);
    REQUIRE(fabs(b(ans)) <= epsilon);
}

double c(double x)
{
    return sqrt(x);
}
double CP (double x)
{
    return (1 / sqrt(x));
}

TEST_CASE("netonApprox - sqrt(x)")
{
    double epsilon = 0.001;
    double n = 1;
    double ans;
    ans = newtonApprox(n, c, CP, epsilon);
    REQUIRE(fabs(c(ans)) <= epsilon);
}
