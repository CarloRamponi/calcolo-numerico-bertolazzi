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

    using Integration_Method = bool(double, double, int ,double(double), double&);
    // Forma comoda per esprimere una funzione che è un metodo di integrazione numerica definita

    bool adaptive_integration(double a, double b, double (*PFUN)(double), double tol, double &res,
                            Integration_Method (*integ1), Integration_Method (*integ2));
    /*Funzione che integra numericamente la funzione f
    tra gli estremi a e b, tramite integrazione adattiva;
    tol è la tolleranza (assoluta);
    il metodo utilizza 2 metodi di integrazione integ1 ed
    integ2 per ottenere una stima dell'errore di integrazione*/

    bool visualize_trapezes(double a, double b, int n_intervalli, double (*PFUN)(double), double &res);
    /*Funzione che integra numericamente la funzione f
    tra gli estremi a e b usando n_intervalli valutazioni
    della funzione, usando il metodo dei trapezi. Come peculiarità,
    questa funzione genera un file di testo atto a visualizzare
    l'integrale computato in un gnuplot script*/

    
}
