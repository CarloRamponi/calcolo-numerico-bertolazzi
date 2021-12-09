#include <iostream>
#include <fstream>
#include "integrazione.h"

/***** AUTHOR: Davide Micheli *****/


using namespace std;

bool cnum::linspace(double a, double b, int n, double out[]){
    double h=(b-a)/n;

    for(int i=0;i<n;i++)
        out[i]=a+i*h;
    
    return 1;
}

bool cnum::integrazione_Simpson(double a, double b, int n_intervalli, double (*PFUN)(double), double &res){
    if(n_intervalli%2==0)
        n_intervalli++;  //serve n_intervalli dispari per il metodo

    double h=(b-a)/n_intervalli;

    //Spazio di integrazione
    double x_num[n_intervalli];
    cnum::linspace(a,b,n_intervalli,x_num);

    //Computa la funzione nei punti
    double f_num[n_intervalli];
    for(int i=0;i<n_intervalli;i++)
        f_num[i]=PFUN(x_num[i]);

    //Computiamo effettivamente l'integrale
    res=f_num[0]+f_num[n_intervalli-1]; //Primo, penultimo ed ultimo elemento

    for(int i=1;i<n_intervalli-1;i+=2)
        res+=2*f_num[i]+4*f_num[i+1];

    res*=h/3;
    return 1;

}

bool cnum::integrazione_midpoint(double a, double b, int n_intervalli, double (*PFUN)(double), double &res){
    double h=(b-a)/n_intervalli;

    //Spazio di integrazione
    double x_num[n_intervalli];
    cnum::linspace(a,b,n_intervalli,x_num);
    for(int i=0;i<n_intervalli;i++)
        x_num[i]+=h/2;  //Spostiamo le x al centro degli intervalli

    //Computa la funzione
    double f_num[n_intervalli];
    for(int i=0;i<n_intervalli;i++)
        f_num[i]=PFUN(x_num[i]);

    //Computiamo effettivamente l'integrale
    res=0;

    for(int i=0;i<n_intervalli;i++)
        res+=f_num[i];

    res*=h;
    return 1;

}


bool cnum::adaptive_integration(double a, double b, double (*PFUN)(double), double tol, double &res,
                            Integration_Method (*integ1), Integration_Method (*integ2)){
    double res1, res2, err;

    int n=1;
    do{
        n*=10;   //Aumenta n
        if(integ1( a, b, n, *PFUN, res1 )==0) //Primo metodo
            return 0; //Esce in caso di errori
        if(integ2( a, b, n, *PFUN, res2 )==0) //Secondo metodo
            return 0;
        err=abs( res2 - res1 ) / 3.;
    }while(err>tol); //Se l'errore è troppo grande riesegui con una n più grande
    

    res=(res1+res2)/2;
    return 1;
}

bool cnum::visualize_trapezes(double a, double b, int n_intervalli, double (*PFUN)(double), double &res){
    double h=(b-a)/n_intervalli;

    //Spazio di integrazione
    double x_num[n_intervalli];
    cnum::linspace(a,b,n_intervalli,x_num);

    //Computa la funzione
    double f_num[n_intervalli];
    for(int i=0;i<n_intervalli;i++)
        f_num[i]=PFUN(x_num[i]);

    //Computiamo effettivamente l'integrale
    res=(f_num[0]+f_num[n_intervalli-1])*0.5; //Primo, penultimo ed ultimo elemento

    for(int i=1;i<n_intervalli-1;i++)
        res+=f_num[i];

    res*=h/3;



    //Ora creiamo le sequenze di punti da visualizzare
    ofstream	o( "plot_trapezi.txt" );     // file in cui salvo i trapezi
    ofstream	o2( "plot_funzione.txt" );     // file in cui salvo la funzione
    //Per tenere la funzione semplice, fisso il nome dei file
    //Normalmente questo sarebbe inserito come variabile target della funzione visualize_trapezes

    o.precision( 4 );        // imposta la precisione


    //Vogliamo creare n_intervalli trapezi nei punti in cui li stiamo integrando
    for(int i=0;i<n_intervalli-1;i++)
    {
        //Punti a sinistra
        o<<x_num[i]<< "\t" << f_num[i] << endl;
        o<<x_num[i]<< "\t" << 0 << endl;
        //Punti a destra
        o<<x_num[i+1]<< "\t" << 0 << endl;
        o<<x_num[i+1]<< "\t" << f_num[i+1] << endl;
        o<<x_num[i]<< "\t" << f_num[i] << endl;
        o<<"\n\n";
    }
    
    //Infine creiamo un plot della funzione che stiamo imitando
    int T=n_intervalli*100; //Voglio farla abbastanza precisa per vedere le differenze
    double x_num_2[T];
    cnum::linspace(a,b,T,x_num_2);
    for(int i=0;i<T;i++)
        o2<<x_num_2[i]<< "\t" << PFUN(x_num_2[i]) << endl;

    return 1;
}