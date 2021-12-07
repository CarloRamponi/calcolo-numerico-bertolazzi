#include <iostream>
#include <cmath>
#include "integrazione.h"


/***** AUTHOR: Davide Micheli *****/

using namespace std;
using namespace cnum;


int main(){
    cout<<"\n\n";
    int n=100;
    double res, real;


    cout<<"METODO DI SIMPSON\n\n";
    //Testiamo sulla funzione radice diretto dalla libreria cmath
    integrazione_Simpson(0,1,n,&sqrt,res);
    cout<<"f(x)=sqrt(x) integrata da 0 a 1\tI="<<res<<"\n";
    real=(double)2 /3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";

    integrazione_Simpson(1,4,n,&log,res);
    //Stessa cosa con logaritmo
    cout<<"f(x)=ln(x) integrata da 1 a 4\tI="<<res<<"\n";
    real=log(256)-3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";


    cout<<"\n\nMETODO MIDPOINT\n\n";
    //Testiamo sulla funzione radice diretto dalla libreria cmath
    integrazione_midpoint(0,1,n,&sqrt,res);
    cout<<"f(x)=sqrt(x) integrata da 0 a 1\tI="<<res<<"\n";
    real=(double)2 /3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";

    integrazione_midpoint(1,4,n,&log,res);
    //Stessa cosa con logaritmo
    cout<<"f(x)=ln(x) integrata da 1 a 4\tI="<<res<<"\n";
    real=log(256)-3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";


    cout<<"\n\nINTEGRAZIONE ADATTIVA\n\n";
    double tol=pow(10,-6);
    //Testiamo sulla funzione radice diretto dalla libreria cmath
    adaptive_integration(0,1,&sqrt,tol,res, integrazione_midpoint, integrazione_Simpson);
    cout<<"f(x)=sqrt(x) integrata da 0 a 1\tI="<<res<<"\n";
    real=(double)2 /3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";

    adaptive_integration(1,4,&log,tol,res, integrazione_midpoint, integrazione_Simpson);
    //Stessa cosa con logaritmo
    cout<<"f(x)=ln(x) integrata da 1 a 4\tI="<<res<<"\n";
    real=log(256)-3;
    cout<<"Valore reale \t\t\tI="<<real<<"\n";
    cout<<"Errore relativo="<<(res-real)/real<<"\n\n";



    return 1;
}