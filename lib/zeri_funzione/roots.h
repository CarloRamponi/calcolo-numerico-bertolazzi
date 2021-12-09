/*



*/

#include <iostream>
#include <fstream> // to read and write files
#include <cmath>

bool bisection(double & x1, double & x2, double tol, int max_iter, double (*f)(double));
/*
    METODO DELLA BISEZIONE:
    data una funzione e due punti iniziali, trova lo zero contenuto nell'intervallo fornito
*/

bool newton(double & x1, double & x2, double tol, int max_iter, double (*f)(double));
/*
    METODO DI NEWTON:
    data una funzione e due punti iniziali, trova lo zero contenuto nell'intervallo fornito
*/

bool secant(double & x1, double & x2, double tol, int max_iter, double (*f)(double));
/*
    METODO DELLA SECANTE:
    data una funzione e due punti iniziali, trova lo zero contenuto nell'intervallo fornito
*/

// five-point derivative
double der5_c(double (*f)(double), double x, double h);