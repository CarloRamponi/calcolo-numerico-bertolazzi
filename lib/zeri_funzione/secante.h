/*
    METODO DELLA SECANTE:
    data una funzionee un punto iniziale, trova lo zero più vicino
*/

#include <iostream>
#include <fstream> // to read and write files
#include <cmath>

bool zerosecant(double & x1, double & x2, double tol, int max_iter, double (*f)(double));