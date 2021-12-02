# Metodi di interpolazione polinomiale

In matematica, e in particolare in analisi numerica, per interpolazione si intende un metodo per individuare nuovi punti del piano cartesiano a partire da un insieme finito di punti dati, nell'ipotesi che tutti i punti si possano riferire ad una funzione f(x) di una data famiglia di funzioni di una variabile reale.

Nelle attività scientifiche e tecnologiche, e in genere negli studi quantitativi di qualsiasi fenomeno, accade molto spesso di disporre di un certo numero di punti del piano ottenuti con un campionamento o con apparecchiature di misura e di ritenere opportuno individuare una funzione che passi per tutti i punti dati o almeno nelle loro vicinanze.  ([Wikipedia](https://it.wikipedia.org/wiki/Interpolazione)).


Libreria `interpol.cpp` per interpolare polinomi con metodo di Lagrange e di Newton che si appoggia sulla libreria per gestire i polinomi `poly.cpp`.

Per utilizzarla modificare il valore della variabile EigenPath nel makefile con il proprio percorso per Eigen e dopo essersi spostati nella cartella `interpolazioni` effettuare il comando:

```bash
$ make
```

Per verificarne il funzionamento eseguire il test:

```bash
$ ./testInterpol
```

## Metodi trattati

- Interpolazione di Lagrange

```C++
// Retrieve the polynomial passing through (x[i], fx[i]) points using Lagrange interpolation
Poly LagrangeInterpolation(Eigen::VectorXd x, Eigen::VectorXd fx);
```

- Interpolazione di Newton

```C++
// Get Newton's divided difference coefficients
double NewtonDividedDiff(Eigen::VectorXd x, Eigen::VectorXd fx);


// Retrieve the polynomial passing through (x[i], fx[i]) points using Newton's divided differences interpolation
Poly NewtonInterpolation(Eigen::VectorXd x, Eigen::VectorXd fx);
```