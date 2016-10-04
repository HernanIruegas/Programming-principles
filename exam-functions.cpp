//
//  main.cpp
//  Funciones del examen corregidas
//
//  Created by Hernán Iruegas Villarreal on 08/03/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int diasMes(int iMes)
{
    
    //validar que el mes sea correcto y desplegar el numero de dias que tiene
    if(iMes >= 1 && iMes <= 12)
    {
        if(iMes == 2)
            return 28;
        
        if(iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11)
            return 30;
        
        return 31;
    }
    return 0;
}

void estaciones(int iDia, int iMes, int iHemisferio){
    
    //declaración de variables
    int dDia;
    const int
    MARZO = 3,
    ABRIL = 4,
    MAYO = 5,
    JUNIO = 6,
    JULIO = 7,
    AGOSTO = 8,
    SEPTIEMBRE = 9,
    OCTUBRE = 10,
    NOVIEMBRE = 11,
    DICIEMBRE = 12;
    
    dDia = diasMes(iMes);
    
    if((iDia>=1 && iDia<=dDia)&&(iHemisferio==1 || iHemisferio==2)&& dDia!= 0)
    {
        
    if((iMes == MARZO && dDia > 20)|| (iMes == ABRIL) || (iMes == MAYO)  || (iMes == JUNIO && dDia < 21))
    {
        if(iHemisferio == 2)
            cout<<"Primavera\n";
        else
            cout<<"Otoño\n";
    }
    else
        
        if((iMes == JUNIO && dDia > 20)||(iMes == JULIO) ||(iMes == AGOSTO)  || (iMes == SEPTIEMBRE && dDia < 23))
        {
            if(iHemisferio == 2)
                cout<<"Verano\n";
            else
                cout<<"Invierno\n";
        }
    else
                
        if((iMes == SEPTIEMBRE && dDia > 22)||(iMes == OCTUBRE) ||(iMes == NOVIEMBRE)  || (iMes == DICIEMBRE && dDia < 21))
        {
            if(iHemisferio == 2)
                cout<<"Otoño\n";
            else
                cout<<"Primavera\n";
        }
    else
                    
        if(iHemisferio == 2)
            cout<<"Invierno\n";
        else
            cout<<"Verano\n";
    }
    
}

int ceiling(double dX){
    
    //declaración de variables
    int iX;
    
    iX = (int) dX;
    
    if(dX>iX)
        iX = iX+1;
    
    cout<<dX<<" se transforma a: "<<iX<<endl;
        
    return 0;
}

void formato12(int &iH, string &sF){
    
    //leer la hora
    cout<<"Ingrese la hora ";
    cin>>iH;
    
    if(iH>=0 && iH<=23)
    {
        if(iH==12)
            sF="PM";
        else
        {
            if(iH>=1 && iH<=11)
                sF="AM";
            else
            {
                if(iH>=13 && iH<=23)
                {
                    iH= iH-12;
                    sF="PM";
                }
                else
                {
                    sF="AM";//iH == 0
                }
            }
        }
    //desplegar la hora con el 0 en la izquierda dependiendo del numero; 0,10,11,22,23 son los casos en donde el 0 no va
        if(iH==0)
            cout<<"12:00"<<sF<<endl;
        else
        {
            if(iH==10||iH==11 ||iH==12 ||iH==22||iH==23)
                cout<<iH<<":00"<<sF<<endl;
            else
                cout<<"0"<<iH<<":00"<<sF<<endl;
        }
    }
    else
    {
        sF="ERROR";
        cout<<sF<<endl;
    }
}


void aprueba(int iFP1, int iFP2, int iCP1, int iCP2, int iTE, int iTS, bool &apruebaMateria){
    
    //declaración de variables
    int iTotFaltas;
    double dPromedioCal;
    
    iTotFaltas = iFP1 + iFP2;
    dPromedioCal = (iCP1 + iCP1)/2.0;
    
    apruebaMateria = !(iFP1>3 && iFP2>3 && dPromedioCal<70)||(iTotFaltas>9 && dPromedioCal<80)||(iTE<iTS);
}


int main(){
    
    
    
   

}















