#include "metodi_iterativi.h"
#include <fstream>
#include <iostream>

/**
 * @brief Legge A e b fa file
 * @author Carlo Ramponi
 * 
 * @param input_file nome del file di input (formato definito sopra)
 * @return std::pair<Eigen::MatrixXd, Eigen::VectorXd> 
 */
std::pair<Eigen::MatrixXd, Eigen::VectorXd> read_input(const std::string &input_file) {
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Errore nell'apertura del file " << input_file << std::endl;
        exit(EXIT_FAILURE);
    }

    int n, m;

    //leggo le dimensioni della matrice A
    file >> n >> m;
    Eigen::MatrixXd A(n, m);
    Eigen::VectorXd b(n);

    //leggo la matrice A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> A(i, j);
        }
    }

    //leggo i termini noti b
    for(int i = 0; i < n; i++) {
        file >> b(i);
    }

    file.close();
    return std::make_pair(A, b);
}

Eigen::VectorXd cnum::jacobi(const std::string &input_file, const std::string &output_file, double tol, int max_iter) {

    //leggo A e b dal file di input
    std::pair<Eigen::MatrixXd, Eigen::VectorXd> input = read_input(input_file);

    //apro il file di output
    std::ofstream file(output_file);

    //cotrollo che il file di output sia stato aperto correttamente
    if(!file.is_open()) {
        std::cerr << "Errore nell'apertura del file " << output_file << std::endl;
        exit(EXIT_FAILURE);
    }

    Eigen::MatrixXd A = input.first;
    Eigen::VectorXd b = input.second;

    // Calcolo la matrice M di Jacobi (diagonale di A)
    Eigen::MatrixXd M = A.diagonal().asDiagonal();

    // Calcolo la matrice N di Jacobi
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione (in questo caso parto con x0 = b)
    Eigen::VectorXd x = b;
    Eigen::VectorXd x_old = b;

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
        std::cout << "Iterazione " << k << ": norma del residuo = " << norm_r_diff << std::endl;

        //scrivo nel file di output la norma del residuo dell'iterazione corrente
        file << k << " " << norm_r_diff << std::endl;

        k++;
    }

    file.close();

    return x;
}

//Metodo di Gauss-Seidel
Eigen::VectorXd cnum::gauss_seidel(const std::string &input_file, const std::string &output_file, double tol, int max_iter) {

    //leggo A e b dal file di input
    std::pair<Eigen::MatrixXd, Eigen::VectorXd> input = read_input(input_file);

    //apro il file di output
    std::ofstream file(output_file);

    //cotrollo che il file di output sia stato aperto correttamente
    if(!file.is_open()) {
        std::cerr << "Errore nell'apertura del file " << output_file << std::endl;
        exit(EXIT_FAILURE);
    }

    Eigen::MatrixXd A = input.first;
    Eigen::VectorXd b = input.second;

    // Calcolo la matrice M di Gauss seidel (matrice triangolare inferiore)
    Eigen::MatrixXd M = A.triangularView<Eigen::Lower>().toDenseMatrix();

    // Calcolo la matrice N di Gauss seidel (matrice triangolare superiore, con diagonale nulla)
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione (in questo caso parto con x0 = b)
    Eigen::VectorXd x = b;
    Eigen::VectorXd x_old = b;

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

        std::cout << "Iterazione " << k << ": norma del residuo = " << norm_r_diff << std::endl;

        //scrivo nel file di output la norma del residuo dell'iterazione corrente
        file << k << " " << norm_r_diff << std::endl;

        k++;
    }

    file.close();

    return x;
}

//Metodo SOR
Eigen::VectorXd cnum::sor(const std::string &input_file, const std::string &output_file, double tol, int max_iter, double w) {

    //leggo A e b dal file di input
    std::pair<Eigen::MatrixXd, Eigen::VectorXd> input = read_input(input_file);

    //apro il file di output
    std::ofstream file(output_file);

    //cotrollo che il file di output sia stato aperto correttamente
    if(!file.is_open()) {
        std::cerr << "Errore nell'apertura del file " << output_file << std::endl;
        exit(EXIT_FAILURE);
    }

    Eigen::MatrixXd A = input.first;
    Eigen::VectorXd b = input.second;

    // Calcolo la matrice M di Gauss seidel (matrice triangolare inferiore)
    Eigen::MatrixXd M = A.triangularView<Eigen::Lower>().toDenseMatrix();

    // Calcolo la matrice N di Gauss seidel (matrice triangolare superiore, con diagonale nulla)
    Eigen::MatrixXd N = A - M;

    // Vettore soluzione
    Eigen::VectorXd x = b;
    Eigen::VectorXd x_old = b;

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

        std::cout << "Iterazione " << k << ": norma del residuo = " << norm_r_diff << std::endl;

        //scrivo nel file di output la norma del residuo dell'iterazione corrente
        file << k << " " << norm_r_diff << std::endl;

        k++;
    }

    file.close();

    return x;
}