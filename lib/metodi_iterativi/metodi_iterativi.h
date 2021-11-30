#include <Eigen/Dense>

namespace cnum {

    /**
        * @brief Metodo di Jacobi
        * @author Carlo Ramponi
        * @param A matrice dei coefficienti
        * @param b vettore dei termini noti
        * @param x0 vettore di partenza
        * @param tol errore massimo tollerato
        * @param max_iter massimo numero di iterazioni
        * @param file_name (opzionale) nome del file su cui scrivere le norme intermedie (per Gnuplot)
        * @return vettore soluzione
    */
    Eigen::VectorXd jacobi(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, const std::string &file_name = "");

    /**
     * @brief Metodo di Gauss-Seidel
     * @author Carlo Ramponi
     * @param A matrice dei coefficienti
     * @param b vettore dei termini noti
     * @param x0 vettore di partenza
     * @param tol errore massimo tollerato
     * @param max_iter massimo numero di iterazioni
     * @param file_name (opzionale) nome del file su cui scrivere le norme intermedie (per Gnuplot)
     * @return Eigen::VectorXd 
     */
    Eigen::VectorXd gauss_seidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, const std::string &file_name = "");

    /**
     * @brief Successive Over Relaxation
     * @author Carlo Ramponi
     * @param A matrice dei coefficienti
     * @param b vettore dei termini noti
     * @param x0 vettore di partenza
     * @param tol errore massimo tollerato
     * @param max_iter massimo numero di iterazioni
     * @param w parametro di rilassamento
     * @param file_name (opzionale) nome del file su cui scrivere le norme intermedie (per Gnuplot)
     * @return Eigen::VectorXd 
     */
    Eigen::VectorXd sor(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, double w, const std::string &file_name = "");

}