#include "roots.h"

using namespace std;

// five-point derivative
double der5_c(double (*f)(double), double x, double h)
{
    return (-f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h))/(12*h);
}

// Newton's method with a function as input
