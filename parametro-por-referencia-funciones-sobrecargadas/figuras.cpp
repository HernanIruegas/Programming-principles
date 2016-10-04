//
//  main.cpp
//  Tarea6_funciones_parametro_por_referencia
//
//  Created by Hernán Iruegas Villarreal on 14/02/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;


//función por parametro de referencia para calcular el area y el semiperimetro de una figura
double calculaAreaSemi(int iA, int iB, int iC, double &dArea, double &dP)
{
        //caculos para el area y el semiperimetro de la figura
        dP = (iA + iB + iC) / (2.0);
        dArea = sqrt(dP*(dP-iA)*(dP-iB)*(dP-iC));
    
        return dArea;
}

int main(){
    
    //Declaración de variables
    int iA, iB, iC;
    double dArea, dP, area;
    
    cout<<"Ingresa a: ";
    cin>>iA;
    cout<<"Ingresa b: ";
    cin>>iB;
    cout<<"Ingresa c: ";
    cin>>iC;
    
    //Llamando a la función calculaAreaSemi por referencia
    area = calculaAreaSemi(iA, iB, iC, dArea, dP);
    
    //Mostrar resultados
    cout<<"El area es : "<<area<<"\nel semiperimetro es: "<<dP<<endl;

    return 0;
}
