#include "roots.h"

using namespace std;

/* Some example functions to test the root-finding methods */

double shifted_parabola(double x)   {
    return x*x -4;
}

double cos2(double x)   {
    return cos(x)*cos(x) - 0.5;
}

int main(int argc, char* argv[])
{
    bool result;
    double x1 = 0.;
    double x2 = 7.;

    result = bisection(x1, x2, 1e-6, 2000, shifted_parabola);
    result = secant(x1, x2, 1e-6, 2000, shifted_parabola);

    x1 = 0.;
    x2 = 2.;
    result = bisection(x1, x2, 1e-6, 2000, cos2);
    result = secant(x1, x2, 1e-6, 2000, cos2);

}