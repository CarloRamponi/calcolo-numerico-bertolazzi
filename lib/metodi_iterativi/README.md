# Metodi iterativi

In analisi numerica un metodo numerico iterativo è un tipo di metodo numerico nel quale le successive approssimazioni della soluzione al problema matematico esaminato sono ottenute a partire dalle precedenti. Ciò comporta che un metodo numerico iterativo necessiti di una stima iniziale (valori di starting) sul quale innestarsi e la possibilità che le approssimazioni convergano solo alla soluzione, ovvero che non sia possibile giungere alla soluzione esatta in un numero finito di passi. ([Wikipedia](https://it.wikipedia.org/wiki/Metodo_iterativo))

In questa cartella verranno incluse varie funzioni che possono essere utilizzate per risolveere un problema utilizzando un metodo iterativo

Per utilizzare la libreria, includere il file [`metodi_iterativi.h`](metodi_iterativi.h) e compilare il file [`metodi_iterativi.cpp`](metodi_iterativi.cpp) con i propri sorgenti.

Un esempio di utilizzo della libreria si può trovare nel file [`test/main.cpp`](test/main.cpp)

Per compilare ed eseguire il test, eseguire questi comandi:
```bash
$ cd lib/metodi_iterativi/test
$ g++ -o main.out main.cpp ../metodi_iterativi.cpp -I<Cartella contenente la libreria Eigen>
$ ./main
```
Questo test esegue i tre metodi iterativi sull'input definito del file `intput.dat` e genera i tre rispettivi grafici.

Per generare un grafico, partendo da un file generato da una di queste funzioni, eseguire questi comandi:
```bash
$ gnuplot -c plot.gp "<file generato>" "<nome file di output (.pdf)>"
```

## Formato file di input

Tutte le funzioni in questa cartella prevedono un file di input in formato questo formato:

```
N M
A11 A12 ... A1N
A21 A22 ... A2N
...
AN1 AN2 ... ANN
b1 b2 ... bN
```

## Metodi trattati

- Metodo di Jacobi

  ```C++
  /**
   * @brief Metodo di Jacobi
   * @author Carlo Ramponi
   * 
   * @param input_file nome del file di input (formato definito sopra)
   * @param output_file nome del file di output
   * @param tol errore massimo tollerato
   * @param max_iter massimo numero di iterazioni
   * @return Eigen::VectorXd vettore soluzione
  */ 
  Eigen::VectorXd cnum::jacobi(const std::string &input_file, const std::string &output_file, double tol, int max_iter);
  ```

- Metodo di Gauss-Seidel

  ```C++
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
  ```

- Successive Over Relaxation
  ```C++
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
  ```