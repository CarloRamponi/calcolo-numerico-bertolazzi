// PENCO SALVI GIACOMO

/* 
 *      SIMPLE INTERPOLATION EXAMPLES
 */

#include <iostream>
#include <Eigen/Dense>
#include "poly.h"
#include "interpol.hpp"

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
    printf("\n");
    
    // LAGRANGE:

    Poly pol = LagrangeInterpolation(x, fx);
    cout << "Lagrange interpoled polynomial: " << pol;

    // Check that the polynomial really passes through the given points
    for (int i=0; i<x.size(); i++)
        cout << "p(" << x(i) << ") = " << pol.eval(x(i)) << endl;

    // Evaluate the polynomial in x=10
    cout << "p(10) = " << pol.eval(10) << endl << endl;

    // NEWTON:
    pol = NewtonInterpolation(x, fx);
    cout << "Newton interpoled polynomial: " << pol;

    // Check that the polynomial really passes through the given points
    for (int i=0; i<x.size(); i++)
        cout << "p(" << x(i) << ") = " << pol.eval(x(i)) << endl;

    // Evaluate the polynomial in x=10
    cout << "p(10) = " << pol.eval(10) << endl;
    
    return 0;
}