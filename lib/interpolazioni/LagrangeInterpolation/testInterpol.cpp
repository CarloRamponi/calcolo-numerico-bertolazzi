#include <iostream>
#include <Eigen/Dense>
#include "poly.h"
#include "interpol.h"

using namespace std;
using namespace Eigen;

int main(){
    VectorXd x(4), fx(4);
    x(0) = 5;
    fx(0) = 12;

    x(1) = 6;
    fx(1) = 13;

    x(2) = 9;
    fx(2) = 14;

    x(3) = 11;
    fx(3) = 16;

    cout << "x | f(x)" << endl;
    for (int i=0; i<x.size(); i++){
        cout << x(i) << " | " << fx(i) << endl;
    }

    Poly pol = LagrangeInterpolation(x, fx);
    cout << "Interpoled polynomial: " << pol;

    cout << "p(10) = " << pol.eval(10) << endl;

    return 0;
}