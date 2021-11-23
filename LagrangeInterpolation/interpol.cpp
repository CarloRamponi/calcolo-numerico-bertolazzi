// PENCO SALVI GIACOMO

/*
    LAGRANGE INTERPOLATION:
        given n points retrieve the lowest degree
        polynomial which passes through those points.
*/

#include "poly.h"           // Alice's polynomials library
#include "interpol.h"

using namespace std;
using namespace Eigen;

Poly LagrangeInterpolation(VectorXd x, VectorXd fx){
    int n=x.size();
    Poly f(n);
    double temp;
    for (int i=0; i<n; i++){
        VectorXd one(1);
        one(0)=1;
        Poly fMult(one);
        VectorXd w(1);
        w(0) = fx(i);
        Poly fAdd(w);
        for (int j=0; j<n; j++){
            if(i==j)
                j++;
            if(j==n)
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