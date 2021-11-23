#include "metodi_iterativi.h"

Eigen::VectorXd cnum::jacobi(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, double tol, int max_iter) {

    /**
     * x^(k+1) = x^k + (b - A*x^k)/(A*x^k)
     */

    // numero di righe della matrice A
    int n = A.rows();

    // vettore di appoggio che contiene il valore di x calcolato nell'iterazione precedente
    Eigen::VectorXd x_old = x0;

    // vettore di appoggio che contiene il valore di x calcolato nell'iterazione corrente
    Eigen::VectorXd x_new = x0;

    // residuo nell'iterazione precedente
    Eigen::VectorXd r_old = b - A * x0;

    // residuo nell'iterazione corrente
    Eigen::VectorXd r_new = b - A * x0;
    
    // eseguo la norma per ogni residuo (che verranno aggiornate nel ciclo)
    double norm_r_old = r_old.norm();
    double norm_r_new = r_new.norm();

    // differenza tra le norme del residuo corrente e precedente, il ciclo termina quando questa è minore della soglia di tolleranza (tol)
    // quindi partiamo con tol + 1 per effettuare la prima iterazione del ciclo
    double norm_r_diff = tol + 1;

    //k è il numero di iterazioni effettuate (non dobbiamo sforare il massimo passato alla funzione)
    int k = 0;
    while (norm_r_diff > tol && k < max_iter) {

        //setto il vettore ed il relativo residuo come quello dell'iterazione precedente
        x_old = x_new;
        r_old = r_new;
        norm_r_old = norm_r_new;

        //calcolo il vettore x_new
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A(i, j) * x_old(j);
                }
            }
            x_new(i) = (b(i) - sum) / A(i, i);
        }

        //calcolo il nuovo residuo
        r_new = b - A * x_new;
        norm_r_new = r_new.norm();

        //calolo la nuova differenza tra le norme dei residui
        norm_r_diff = norm_r_old - norm_r_new;

        k++;
    }
    return x_new;
}