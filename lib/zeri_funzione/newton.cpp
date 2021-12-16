#include "roots.hpp"

using namespace std;

// five-point derivative
double der_c(double (*f)(double), double x, double h)
{
    return (-f(x+2*h) + 8*f(x+h) - 8*f(x-h) + f(x-2*h))/(12*h);
}

// five-point second derivative [https://en.wikipedia.org/wiki/Five-point_stencil]
double der2_c(double (*f)(double), double x, double h)
{
    return (-f(x+2*h) + 16*f(x+h) -30*f(x) + 16*f(x-h) - f(x-2*h))/(12*h*h);
}


/* Metodo di Newton per trovare gli zeri di una funzione.
    Il primo argomento è il punto iniziale da cui far partire l'algoritmo.
    Il terzo argomento è la tolleranza data prima di considerare il punto trovato uno zero.
    Il quarto argomento è il numero massimo di iterazioni consentito, dopo il quale la funzione
    ritornerà 0.
    L'ultimo argomento è la funzione da passare di cui si sta cercando lo zero.
*/

bool newton(double & x, double tol, int max_iter, double (*f)(double))
{
    /*if (f(x1)*f(x2)>0) 
    {
        cout<<"The provided starting interval should be of opposing sign and contain one zero\n";
        return false;
    }*/

    ofstream iterations ("newtondata.csv");     // Opening file to print info to
    iterations << "x, f " << endl;          // Headings for file
    iterations << x << ", " << fabs(f(x)) << endl;

    
    for (int i=0; i<max_iter; i++)
    {
        x -= f(x) / der_c(f, x, 1e-7);

        // stampa dati iterazione
        iterations << x << ", " << fabs(f(x)) << ", " << der_c(f, x, 1e-7) <<", " << der2_c(f, x, 1e-7)<<endl;

        // se il valore assoluto della funzione in x2 è abbastanza vicino a 0 abbiamo trovato il punto cercato
        if (fabs(f(x))<tol) {
            cout<<"A zero of the function was found at "<< x <<", with value "<< f(x) <<"\n";
            iterations.close();
            return true;
        }
    }
    
    cout<<"A zero within the provided interval could not be found with the required tolerance\n";
    iterations.close();
    return false;
}
