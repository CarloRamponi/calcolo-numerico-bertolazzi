// PENCO SALVI GIACOMO

/*
    POLYNOMIAL INTERPOLATION LIBRARY:
        given n points retrieve the lowest degree
        polynomial which passes through those points.
*/

#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include "poly.h"           //polynomials library

// Retrieve the polynomial passing through (x[i], fx[i]) points using Lagrange interpolation
Poly LagrangeInterpolation(Eigen::VectorXd x, Eigen::VectorXd fx);

// Get Newton's divided difference coefficients
double NewtonDividedDiff(Eigen::VectorXd x, Eigen::VectorXd fx);

// Retrieve the polynomial passing through (x[i], fx[i]) points using Newton's divided differences interpolation
Poly NewtonInterpolation(Eigen::VectorXd x, Eigen::VectorXd fx);

// Print the polynomial formatted for Gnuplot to a stream output (e.g. cout or fout)
std::string printPolGnuplot( Poly pol);

// Reads two columns of data from file into a two column matrix
Eigen::MatrixXd readCSV( std::string filename);