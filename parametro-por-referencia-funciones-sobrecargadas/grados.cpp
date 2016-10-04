//
//  main.cpp
//  Tarea6_funcion_CFK
//
//  Created by Hernán Iruegas Villarreal on 14/02/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

void conversionCFK(int iC, int &iF, int &iK){
    
    iF = (int)((9.0/5)*iC + 32);
    iK = (int)(iC + 273);
    
}

int main(){
    
    //declaración de variables
    int iC, iF, iK;
    
    cout<<"Ingrese los grados centigrados ";
    cin>>iC;
    
    conversionCFK(iC, iF, iK);
    
    //Mostrar resultados de la función
    cout<<"Grados Farenheit: "<<iF<<"ºF"<<"\nGrados Kelvin: "<<iK<<"ºK"<<endl;

    return 0;
}
