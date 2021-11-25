#include <Eigen/Dense>

namespace cnum {



    /**
        * @brief Metodo di Jacobi
        * @author Carlo Ramponi
        * @param A matrice dei coefficienti
        * @param b vettore dei termini noti
        * @param x0 vettore vettore di partenza
        * @param tol errore
        * @param max_iter massimo numero di iterazioni
        * @return vettore soluzione
    */
    Eigen::VectorXd jacobi(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter);

}