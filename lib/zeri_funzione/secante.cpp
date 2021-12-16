#include "roots.hpp"

using namespace std;

/* Metodo della secanteper trovare gli zeri di una funzione.
    I primi due argomenti sono i punti da cui far partire il metodo iterativo, 
    e dato che non facciamo alcuna ricerca preliminare degli intervalli in cui il segno
    della funzione si inverte, è l'utente a dover scegliere un intervallo iniziale appropriato.
    Il terzo argomento è la tolleranza data prima di considerare il punto trovato uno zero.
    Il quarto argomento è il numero massimo di iterazioni consentito, dopo il quale la funzione
    ritornerà 0.
    L'ultimo argomento è la funzione da passare di cui si sta cercando lo zero.
*/
bool secant(double & x1, double & x2, double tol, int max_iter, double (*f)(double))
{
    if (f(x1)*f(x2)>0) 
    {
        cout<<"The provided starting interval should be of opposing sign and contain one zero\n";
        return false;
    }

    double x_;
    ofstream iterations ("secantdata.csv");     // Opening file to print info to
    iterations << "x, f " << endl;          // Headings for file
    iterations << x2 << ", " << fabs(f(x2)) << endl;

    
    for (int i=0; i<max_iter; i++)
    {
        x_ = x2;  // salviamo la x2 precedente in una variabile temporanea
        x2 = x2 - f(x2)*(x2-x1)/(f(x2)-f(x1));
        x1 = x_;

        // stampare dati iterazione
        iterations << x2 << ", " << fabs(f(x2)) << endl;

        // se il valore assoluto della funzione in x2 è abbastanza vicino a 0 abbiamo trovato il punto cercato
        if (fabs(f(x2))<tol) {
            cout<<"A zero of the function was found at "<<x2<<", with value "<<f(x2)<<"\n";
            iterations.close();
            return true;
        }
    }
    
    cout<<"A zero within the provided interval could not be found with the required tolerance\n";
    iterations.close();
    return false;
}

