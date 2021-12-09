#include "secante.h"
#include "bisezione.h"


using namespace std;


double shifted_parabola(double x)   {
    return x*x -4;
}
int main(int argc, char* argv[])
{
    double x1 = 0.;
    double x2 = 7.;
    bool result = bisection(x1, x2, 1e-6, 2000, shifted_parabola);
}