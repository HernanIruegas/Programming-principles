//
//  main.cpp
//  funciones_sobrecargadas
//
//  Created by Hernán Iruegas Villarreal on 12/02/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;


//función que suma dos valores enteros

int suma(int iA, int iB){
    return iA + iB;
}

//función sobrecargada con el mismo nombre, pero ahora con un tercer argumento
int suma(int iA, int iB, int iC){
    return iA + iB + iC;
}

//función sobrecargada con el mismo nombre, pero ahora con un cuarto argumento
int suma(int iA, int iB, int iC, int iD){
    return iA + iB + iC + iD;
}

//paso de parametros por valor
int patito(int iA){
    iA = iA * 50;
    return iA;
}

//paso de parametros por referencia
int patito2(int &iA){
    iA = iA * 50;
    
    return iA;
}

//función void con parametros de referencia

void raices(int iA, int iB, int iC, double &dX1, double &dX2){
    //declaración de variables locales
    int iD;
    
    iD = iB*iB-4*iA*iC;
    
    dX1 = (-iB + sqrt(iD))/ (2*iA);
    dX2 = (-iB - sqrt(iD))/ (2*iA);
}

int main(){
    
    //Declaración de variables
    int iP, iA, iB, iC;
    double dX1, dX2;
    
    //llamar a la función void
    raices(3,-4,1,dX1,dX2);
    
    //desplegar resultados de la función void
    cout<<"Raiz1 = "<<dX1<<"\nRaiz2 = "<<dX2<<endl;
    
    //pedir valores para la funcion por valor o por parametro (depende a cuál se llama a continuación)
    cout<<"Teclea un valor: ";
    cin>>iP;
    
    //llamando la funcion por valor o por parametro (depende a cuál se llama a continuación)
    iA = patito2(iP);
    
    //desplegar resultados de la función por valor o por parametro (depende a cuál se llamo antes)
    cout<<"iA = "<<iA<<" iP = "<<iP<<endl;
    
    //llamar  a las funciones
    cout<<"Suma 1 + 2 = "<<suma(1,2)<<endl;
    cout<<"Suma 1 + 1 = "<<suma(1,1)<<endl;
    cout<<"Suma 1 + 2 + 3 = "<<suma(1,2,3)<<endl;
    cout<<"Suma 1 + 2 + 3 + 4 = "<<suma(1,2,3,4)<<endl;
    
    return 0;
}
