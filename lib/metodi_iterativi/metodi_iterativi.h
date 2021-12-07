#include <Eigen/Dense>

namespace cnum {

    /**
     * Il formato dei file di input è il seguente:
     * M N <- dimensione matrice
     * a11 a12 ... a1N
     * a21 a22 ... a2N
     * ...
     * aM1 aM2 ... aMN
     * b1 b2 ... bN
     */

    /**
     * @brief Metodo di Jacobi
     * @author Carlo Ramponi
     * 
     * @param input_file nome del file di input (formato definito sopra)
     * @param output_file nome del file di output
     * @param tol norma dei residui massima tollerata
     * @param max_iter massimo numero di iterazioni
     * @return Eigen::VectorXd vettore soluzione
     */
    Eigen::VectorXd jacobi(const std::string &input_file, const std::string &output_file, double tol, int max_iter);

    /**
     * @brief Metodo di Gauss-Seidel
     * @author Carlo Ramponi
     * 
     * @param input_file nome del file di input (formato definito sopra)
     * @param output_file nome del file di output
     * @param tol norma dei residui massima tollerata
     * @param max_iter massimo numero di iterazioni
     * @return Eigen::VectorXd vettore soluzione
     */
    Eigen::VectorXd gauss_seidel(const std::string &input_file, const std::string &output_file, double tol, int max_iter);

    /**
     * @brief Successive Over Relaxation
     * @author Carlo Ramponi
     *
     * @param input_file nome del file di input (formato definito sopra)
     * @param output_file nome del file di output
     * @param tol norma dei residui massima tollerata
     * @param max_iter massimo numero di iterazioni
     * @param w parametro di rilassamento
     * @return Eigen::VectorXd vettore soluzione
     */
    Eigen::VectorXd sor(const std::string &input_file, const std::string &output_file, double tol, int max_iter, double w);

}