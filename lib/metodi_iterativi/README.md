# Metodi iterativi

In analisi numerica un metodo numerico iterativo è un tipo di metodo numerico nel quale le successive approssimazioni della soluzione al problema matematico esaminato sono ottenute a partire dalle precedenti. Ciò comporta che un metodo numerico iterativo necessiti di una stima iniziale (valori di starting) sul quale innestarsi e la possibilità che le approssimazioni convergano solo alla soluzione, ovvero che non sia possibile giungere alla soluzione esatta in un numero finito di passi. ([Wikipedia](https://it.wikipedia.org/wiki/Metodo_iterativo))

In questa cartella verranno incluse varie funzioni che possono essere utilizzate per risolveere un problema utilizzando un metodo iterativo

Per utilizzare la libreria, includere il file `metodi_iterativi.h` e compilare il file `metodi_iterativi.cpp` con i propri sorgenti.

Un esempio di utilizzo della libreria si può trovare nel file `main.cpp`

Per compilare ed eseguire il test, eseguire questo comando (nella cartella `metodi_iterativi`):
```bash
$ g++ -o main main.cpp metodi_iterativi.cpp -I<Cartella contenente la libreria Eigen>
$ ./main
```

## Metodi trattati

- Metodo di Jacobi

  ```C++
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
  ```

- Metodo di Gauss-Seidel

  ```C++
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
  ```

- Successive Over Relaxation
  ```C++
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
  ```