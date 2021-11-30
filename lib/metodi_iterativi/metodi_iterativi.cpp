#include "metodi_iterativi.h"

Eigen::VectorXd cnum::jacobi(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, const std::string &file_name) {

    // Calcolo la matrice M di Jacobi (diagonale di A)
    Eigen::MatrixXd M = A.diagonal().asDiagonal();

    // Calcolo la matrice N di Jacobi
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione
    Eigen::VectorXd x = x0;
    Eigen::VectorXd x_old = x0;

    // differenza tra le norme del residuo corrente e precedente, il ciclo termina quando questa è minore della soglia di tolleranza (tol)
    // quindi partiamo con INT32_MAX, che è il massimo numero intero rappresentabile con 32 bits per effettuare la prima iterazione del ciclo
    double norm_r_diff = INT32_MAX;

    //k è il numero di iterazioni effettuate (non dobbiamo sforare il massimo passato alla funzione)
    int k = 0;
    while (norm_r_diff > tol && k < max_iter) {

        // Salvo il valore della soluzione precedente (per il calcolo dell'errore)
        x_old = x;

        // Formula di Jacobi
        x = -M.inverse() * (N * x - b);

        norm_r_diff = (x - x_old).norm();

        k++;
    }
    return x;
}

//Metodo di Gauss-Seidel
Eigen::VectorXd cnum::gauss_seidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, const std::string &file_name) {
    // Calcolo la matrice M di Gauss seidel (matrice triangolare inferiore)
    Eigen::MatrixXd M = A.triangularView<Eigen::Lower>().toDenseMatrix();

    // Calcolo la matrice N di Gauss seidel (matrice triangolare superiore, con diagonale nulla)
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione
    Eigen::VectorXd x = x0;
    Eigen::VectorXd x_old = x0;

    // differenza tra le norme del residuo corrente e precedente, il ciclo termina quando questa è minore della soglia di tolleranza (tol)
    // quindi partiamo con INT32_MAX, che è il massimo numero intero rappresentabile con 32 bits per effettuare la prima iterazione del ciclo
    double norm_r_diff = INT32_MAX;

    //k è il numero di iterazioni effettuate (non dobbiamo sforare il massimo passato alla funzione)
    int k = 0;
    while (norm_r_diff > tol && k < max_iter) {

        // Salvo il valore della soluzione precedente (per il calcolo dell'errore)
        x_old = x;

        // Formula di Jacobi
        x = -M.inverse() * (N * x - b);

        norm_r_diff = (x - x_old).norm();

        k++;
    }
    return x;
}

Eigen::VectorXd cnum::sor(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter, double w, const std::string &file_name) {
    // Calcolo la matrice M di Gauss seidel (matrice triangolare inferiore)
    Eigen::MatrixXd M = A.triangularView<Eigen::Lower>().toDenseMatrix();

    // Calcolo la matrice N di Gauss seidel (matrice triangolare superiore, con diagonale nulla)
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione
    Eigen::VectorXd x = x0;
    Eigen::VectorXd x_old = x0;

    // differenza tra le norme del residuo corrente e precedente, il ciclo termina quando questa è minore della soglia di tolleranza (tol)
    // quindi partiamo con INT32_MAX, che è il massimo numero intero rappresentabile con 32 bits per effettuare la prima iterazione del ciclo
    double norm_r_diff = INT32_MAX;

    //k è il numero di iterazioni effettuate (non dobbiamo sforare il massimo passato alla funzione)
    int k = 0;
    while (norm_r_diff > tol && k < max_iter) {

        // Salvo il valore della soluzione precedente (per il calcolo dell'errore)
        x_old = x;

        // Formula di Jacobi
        x = -M.inverse() * (N * x - b);

        // Applico il metodo SOR
        x = w * x + (1 - w) * x_old;

        norm_r_diff = (x - x_old).norm();

        k++;
    }

    return x;
}