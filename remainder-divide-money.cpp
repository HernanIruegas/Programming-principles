//
//  main.cpp
//  Tarea3_convertir_dinero_a_unidades_pequeñas
//
//  Created by Hernán Iruegas Villarreal on 27/01/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

//Hernán Iruegas Villarreal
//A00817021
//El objetivo es convertir una cantidad de dinero especifica a unidades más pequeñas
#include <iostream>
#include <math.h>

using namespace std;
int main(){
    
    /*Declaración de variables*/
    int cantidad, billetes100, billetes50, billetes20, monedas10, monedas5, monedas2, monedas1;
    
    /*Escritura de mensajes en la pantalla y lectura de datos*/
    cout<<"Ingresa la cantidad que deseas convertir:";
    cin>> cantidad;
    
    /*Proceso para converitr la cantidad a unidades más pequeñas*/
    billetes100= cantidad/100;
    cantidad= cantidad%100;
    
    billetes50= cantidad/50;
    cantidad= cantidad%50;
    
    billetes20= cantidad/20;
    cantidad= cantidad%20;
    
    monedas10= cantidad/10;
    cantidad= cantidad%10;
    
    monedas5= cantidad/5;
    cantidad= cantidad%5;
    
    monedas2= cantidad/2;
    cantidad= cantidad%2;
    
    monedas1= cantidad/1;
    cantidad= cantidad%1;
    
    //esto es para regresar el valor de cantidad a su valor original (inicial)
    cantidad= (billetes100*100)+(billetes50*50)+(billetes20*20)+(monedas10*10)+(monedas5*5)+(monedas2*2)+(monedas1*1);
    
    /*Mostrar mensajes*/
    cout<<"El valor que ingresaste fue:"<< cantidad<<endl;
    cout<<"Billetes de 100:"<< billetes100<<endl;
    cout<<"Billetes de 50:"<< billetes50<<endl;
    cout<<"Billetes de 20:"<< billetes20<<endl;
    cout<<"Monedas de 10:"<< monedas10<<endl;
    cout<<"Monedas de 5:"<< monedas5<<endl;
    cout<<"Monedas de 2:"<< monedas2<<endl;
    cout<<"Monedas de 1:"<< monedas1<<endl;
    
    
    return 0;
}
