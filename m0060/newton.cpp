#include "newton.h"

double newtonApprox(double guess, function<double(double)>funct, function<double(double)> functP, double epsilon)
{
    double ans;
    double funG = fabs(funct(guess));
    if (guess <= epsilon)
    {
        funG = fabs(funct(guess));
    }
    if (funG > epsilon)
    {
        ans = guess - funct(guess) / functP(guess);
        guess = newtonApprox(ans, funct, functP, epsilon);
    }
    return guess;
}