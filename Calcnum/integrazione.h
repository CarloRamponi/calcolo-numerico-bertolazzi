#include <iostream>


/***** AUTHOR: Davide Micheli *****/

namespace cnum{
    bool linspace(double a, double b, int n, double out[]);
    /*funzione che ritorna un array di dimensione n con elementi
    equispaziati tra i valori di a e b-h (inclusi); la spaziatura
    sarà quindi h=(b-a)/n */

    bool integrazione_Simpson(double a, double b, int n_intervalli, double (*PFUN)(double), double &res);
    /*Funzione che integra numericamente la funzione f
    tra gli estremi a e b, usando n_intervalli valutazioni
    della funzione, usando il metodo Simpson*/

    bool integrazione_midpoint(double a, double b, int n_intervalli, double (*PFUN)(double), double &res);
    /*Funzione che integra numericamente la funzione f
    tra gli estremi a e b, usando n_intervalli valutazioni
    della funzione, usando il metodo midpoint*/

    
}
