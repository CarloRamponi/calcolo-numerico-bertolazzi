#include "../metodi_iterativi.h"
#include <Eigen/Dense>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {


    // Eseguo il metodo iterativo di Jacobi
    Eigen::VectorXd x = cnum::jacobi("input.dat", "output.dat", 0.001, 100000);
    cout << "Soluzione calcolato con metodo di Jacobi:" << endl << x << endl << endl;
    system("gnuplot -c plot.gp output.dat jacobi.pdf");

    Eigen::VectorXd x1 = cnum::gauss_seidel("input.dat", "output.dat", 0.001, 100000);
    cout << "Soluzione calcolata con metodo di Gauss-Seidel:" << endl << x1 << endl << endl;
    system("gnuplot -c plot.gp output.dat gauss_seidel.pdf");

    Eigen::VectorXd x2 = cnum::sor("input.dat", "output.dat", 0.001, 100000, 0.5);
    cout << "Soluzione calcolata con SOR:" << endl << x2 << endl << endl;
    system("gnuplot -c plot.gp output.dat sor.pdf");

    return 0;
}