// PENCO SALVI GIACOMO

/*
    LAGRANGE INTERPOLATION:
        given n points retrieve the lowest degree
        polynomial which passes through those points.
*/

#include <iostream>
#include <Eigen/Dense>
#include "poly.h"           //polynomials library

Poly LagrangeInterpolation(Eigen::VectorXd x, Eigen::VectorXd fx);