#include <iostream>
#include <cmath>
#include "integrazione.h"


/***** AUTHOR: Davide Micheli *****/

using namespace std;
using namespace cnum;

double sinsq(double x)
{
    return sin(x)*sin(x);
}

int main(){
    int n=20;
    double res;

    visualize_trapezes(0,2*3.1415,n,&sinsq,res);

    return 1;
}