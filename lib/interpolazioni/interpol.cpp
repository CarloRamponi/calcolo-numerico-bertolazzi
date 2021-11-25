// PENCO SALVI GIACOMO

/*
    POLYNOMIAL INTERPOLATION LIBRARY:
        given n points retrieve the lowest degree
        polynomial which passes through those points.
*/

#include "poly.h"           // Alice's polynomials library
#include "interpol.h"

using namespace std;
using namespace Eigen;


// Retrieve the polynomial passing through (x[i], fx[i]) points using Lagrange interpolation
Poly LagrangeInterpolation(VectorXd x, VectorXd fx){
    int n=x.size();     // number of points
    Poly f(n);
    double temp;
    
    for (int i=0; i<n; i++){
        VectorXd one(1);
        one(0)=1;               // Initialize fMult polynomial
        Poly fMult(one);        // to fMult(x) = 1

        VectorXd w(1);
        w(0) = fx(i);           // Initialize fAdd polynomial
        Poly fAdd(w);           // to fAdd(x) = f(x_i)

        for (int j=0; j<n; j++){

            if(i==j)            // Skip when i=j
                j++;
            if(j==n)            // Fix if we skip when i=j=n-1
                break;

            VectorXd v = VectorXd::Zero( 2 );
            temp = 1/(x(i)-x(j));
            v(0) = -temp*x(j);
            v(1) = temp;
            Poly fTemp(v);
            fMult = fMult * fTemp;
        }

        fAdd = fAdd * fMult;        
        f = f + fAdd;

    }

    return f;
}



// Get Newton's divided difference coefficients
double NewtonDividedDiff(VectorXd x, VectorXd fx){
    int n=x.size();     // number of points

    if (n==1)
        return fx(0);
    if (n==2)
        return ( fx(0)-fx(1) )/( x(0)-x(1) );
    
    VectorXd xMinusFirst(n-1), xMinusLast(n-1);
    VectorXd fxMinusFirst(n-1), fxMinusLast(n-1);
    for (int i=0;i<n-1;i++){
        xMinusFirst(i) = x(i+1);
        xMinusLast(i) = x(i);
        fxMinusFirst(i) = fx(i+1);
        fxMinusLast(i) = fx(i);
    }

    return ( NewtonDividedDiff(xMinusLast, fxMinusLast) - NewtonDividedDiff(xMinusFirst, fxMinusFirst) )/(x(0)-x(n-1));
}

// Retrieve the polynomial passing through (x[i], fx[i]) points using Newton's divided differences interpolation
Poly NewtonInterpolation(VectorXd x, VectorXd fx){
    int n=x.size();     // number of points
    Poly f(n);
    double temp;
    
    // TO BE CONTINUED

    return f;
}

