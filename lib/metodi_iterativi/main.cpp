#include "metodi_iterativi.h"
#include <Eigen/Dense>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(NULL));

    Eigen::MatrixXd A = Eigen::MatrixXd::Identity(3, 3);
    Eigen::VectorXd b = Eigen::VectorXd::Ones(3);
    Eigen::VectorXd x0 = Eigen::VectorXd::Random(3);

    cout << "A = " << endl << A << endl;
    cout << "b = " << endl << b << endl;
    cout << "x0:" << endl << x0 << endl;

    Eigen::VectorXd x = cnum::jacobi(A, b, x0, 0.001, 100000);

    cout << "Jacobi: " << endl << x << endl;

    return 0;
}