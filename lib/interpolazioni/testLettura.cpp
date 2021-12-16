// PENCO SALVI GIACOMO

/* 
 *      SIMPLE INTERPOLATION EXAMPLE READING DATA FROM FILE:
 *          Reads data from "data.csv", computed the interpoled polynomial,
 *          creates file "output.txt" which can be executed with gnuplot.
 */

#include <iostream>
#include <Eigen/Dense>
#include "poly.h"
#include "interpol.hpp"

using namespace std;
using namespace Eigen;

int main(){

    MatrixXd matrice = readCSV("data.csv");
    VectorXd x = matrice.col(0);
    VectorXd fx = matrice.col(1);

    Poly pol = LagrangeInterpolation(x, fx);
    cout << "Lagrange interpoled polynomial: " << pol;

    // Gnuplot file maker:

    // getting ranges:
    int xmin = x(0), xmax = x(0);
    int fxmin = fx(0), fxmax = fx(0);
    for (int i=1; i<x.size(); i++){
        if (x(i) < xmin){
            xmin = x(i);
        }
        if (x(i) > xmax){
            xmax = x(i);
        }
        if (fx(i) < fxmin){
            fxmin = fx(i);
        }
        if (fx(i) > fxmax){
            fxmax = fx(i);
        }
    }

    xmin -= 1;
    xmax += 1;
    fxmin -= 1;
    fxmax += 1;

    string xrange = "set xrange [" + to_string(xmin) + ":" + to_string(xmax) + "]\n";
    string yrange = "set yrange [" + to_string(fxmin) + ":" + to_string(fxmax) + "]\n";

    const string head = "# GNUPLOT INTERPOLED POLYNOMIAL PLOTTER\n";
    string settings = "set terminal pdf size 8, 5 font \"Helvetica, 12\"\nset output \"plot.pdf\"\n";

    VectorXd polCoeff = pol.get_coef();
    string polynomial = printPolGnuplot(pol);
    string command = "plot P(x)";

    ofstream myfile("output.txt");
    myfile << head;
    myfile << settings;
    myfile << xrange;
    myfile << yrange;
    myfile << polynomial << endl;
    myfile << command;
    myfile.close();

    return 0;
}