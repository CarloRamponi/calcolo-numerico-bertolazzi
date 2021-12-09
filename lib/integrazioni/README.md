# Metodi di integrazione numerica

Overview di alcuni dei metodi di integrazione trattati in classe. Ogni metodo trattato ha una funzione associata, ed i file header contiene una rapida descrizione di ogni metodo. Ci sono inoltre alcune funzioni di supporto all'integrazione.

Per utilizzare la libreria, includere il file `integrazione.h` e compilare il file `integrazione.cpp` con i propri sorgenti.

Un esempio di utilizzo della libreria si può trovare nel file `integrazione_test.cpp`

Per compilare ed eseguire il test, eseguire questo comando (nella cartella `integrazioni`):
```bash
$ g++ -o main integrazione.cpp integrazione_test.cpp
$ ./main
```

## Metodi trattati

- Integrazione di Simpson

  ```C++
  /**
   * @brief Integrazione di Simpson
   * @author Davide Micheli
   * @param a Limite inferiore integrazione
   * @param b Limite superiore integrazione
   * @param n_intervalli numero di sottodivisioni dell'intervallo
   * @param PFUN pointer alla funzione da integrare
   * @param res valore dell'integrale
   * @return bool indicante successo nell'esecuzione della funzione
   */
  bool integrazione_Simpson(double a, double b, int n_intervalli, double (*PFUN)(double), double &res);
  ```

- Integrazione con midpoint method

  ```C++
  /**
   * @brief Integrazione con metodo midpoint
   * @author Davide Micheli
   * @param a Limite inferiore integrazione
   * @param b Limite superiore integrazione
   * @param n_intervalli numero di sottodivisioni dell'intervallo
   * @param PFUN pointer alla funzione da integrare
   * @param res valore dell'integrale
   * @return bool indicante successo nell'esecuzione della funzione
   */
  bool integrazione_midpoint(double a, double b, int n_intervalli, double (*PFUN)(double), double &res);
  ```

- Adaptive integration

  ```C++
  /**
   * @brief Adaptive integration
   * @author Davide Micheli
   * @param a Limite inferiore integrazione
   * @param b Limite superiore integrazione
   * @param PFUN pointer alla funzione da integrare
   * @param tol tolleranza assoluta del risultato dell'integrazione
   * @param res valore dell'integrale
   * @param integ1 primo metodo di integrazione usato
   * @param integ2 secondo metodo di integrazione usato
   * @return bool indicante successo nell'esecuzione della funzione
   */
  bool adaptive_integration(double a, double b, double (*PFUN)(double), double tol, double &res, Integration_Method (*integ1), Integration_Method (*integ2));
  ```

- Visualizzazione metodi

  ```C++
  /**
   * @brief Metodo per 
   * @author Davide Micheli
   * @param a Limite inferiore integrazione
   * @param b Limite superiore integrazione
   * @param PFUN pointer alla funzione da integrare
   * @param n_intervalli numero di sottodivisioni dell'intervallo
   * @param res valore dell'integrale
   * @return bool indicante successo nell'esecuzione della funzione
   */
  bool visualize_trapezes(double a, double b, int n_intervalli, double (*PFUN)(double), double &res)
  ```
Per quest'ultimo metodo, si noti che i files di output vengono prodotti nella cartella stessa (è in linea di principio possibile riadattare le funzioni per scegliere cartella e nome dei target files). Da usare insieme a p_integ. La funziona mostra cosa succede quando si utilizza il metodo dei trapezi su una funzione fissata in main_plot_integrazione.cpp