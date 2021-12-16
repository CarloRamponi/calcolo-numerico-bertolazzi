#include "roots.hpp"

using namespace std;

/* Alcuni esempi di funzioni per cui calcolare gli zeri.
    Sono funzioni relativamente poco interessanti, in quanto lo zero è facilmente
    calcolabile analiticamente, ma questo ci permette di verificare facilmente i risultati.
 */

/* Questa funzione è semplicemente una parabola spostata di -2 lungo l'asse y, 
    avente quindi uno 0 in -2 e uno in 2.
    Il risultato dipenderà quindi dal punto iniziale scelto nei metodi iterativi 
    per trovare le radici.
*/
double shifted_parabola(double x)   {
    return x*x -4;
}

/* In modo simile a quanto fatto con la parabola, questo è un coseno quadro 
    spostato di 0.5, in modo da avere zeri in tutti i punti πn - π/4 e πn - π*3/4.
    Invece di avere una funzione periodica qui abbiamo invece scelto di moltiplicarla
    per un'espressione che appiattisce il coseno all'infuori dell'intervallo [-π/2, +π/2]
    Questo significa che gli unici due zeri presenti saranno in -π/4 e +π/4, ma anche che 
    metodi basati sulla derivata della funzione, come il metodo di Newton, falliranno se 
    il punto di partenza delle iterazioni è fuori da questo intervallo.
*/
double cos2(double x)   {
    return cos(x)*cos(x) * (abs(x) < M_PI/2) - 0.5;
}

int main(int argc, char* argv[])
{
    bool result;
    double x1 = 0.;
    double x2 = 7.;
    result = bisection(x1, x2, 1e-6, 2000, shifted_parabola);

    x1 = 0.;
    x2 = 7.;
    result = secant(x1, x2, 1e-6, 2000, shifted_parabola);

    x1 = 0.;
    x2 = 7.;
    result = newton(x2, 1e-6, 2000, shifted_parabola);

    x1 = 0.;
    x2 = 1.;
    result = bisection(x1, x2, 1e-6, 2000, cos2);

    x1 = 0.;
    x2 = 1.;
    result = secant(x1, x2, 1e-6, 2000, cos2);

    x2 = 1.;
    result = newton(x2, 1e-6, 2000, cos2);

}