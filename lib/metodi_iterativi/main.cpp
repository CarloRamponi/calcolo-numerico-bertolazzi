#include "metodi_iterativi.h"
#include <Eigen/Dense>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    // Inizializzo il generatore di numeri casuali
    srand(time(NULL));

    // Creo una matrice A di dimensione 3x3 (In questo caso la matrice identità)
    Eigen::MatrixXd A = Eigen::MatrixXd::Identity(3, 3);

    // Creo il vettore b (in questo caso [1, 1, 1])
    Eigen::VectorXd b = Eigen::VectorXd::Ones(3);

    // Creo il vettore di partenza x0, in questo caso con valori causali
    Eigen::VectorXd x0 = Eigen::VectorXd::Random(3);

    cout << "Matrice A:" << endl << A << endl << endl;
    cout << "Vettore b:" << endl << b << endl << endl;
    cout << "Vettore di partenza x0:" << endl << x0 << endl << endl;

    // Eseguo il metodo iterativo di Jacobi
    Eigen::VectorXd x = cnum::jacobi(A, b, x0, 0.001, 100000);

    cout << "Soluzione calcolato con metodo di Jacobi:" << endl << x << endl << endl;

    Eigen::VectorXd x1 = cnum::gauss_seidel(A, b, x0, 0.001, 100000);

    cout << "Soluzione calcolata con metodo di Gauss-Seidel:" << endl << x1 << endl << endl;

    Eigen::VectorXd x2 = cnum::sor(A, b, x0, 0.001, 100000, 0.5);

    cout << "Soluzione calcolata con SOR:" << endl << x2 << endl << endl;

    return 0;
}