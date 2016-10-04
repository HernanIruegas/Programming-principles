//
//  main.cpp
//  desplegar_menu
//
//  Created by Hernán Iruegas Villarreal on 19/02/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h> //para el null
#include <time.h> //para que la secuencia de random no se repita
#include <stdlib.h> //para el srand() y rand()
using namespace std;


//*************************************************
//Display Menu and get user's option
//*************************************************
int menu(){
    
    //Variable declaration
    int iOption;
    
    cout<<"Menú de opciones\n"
    <<"1. Días mes\n"
    <<"2. Calculadora\n"
    <<"3. Calcula el imc\n"
    <<"4. Día siguiente\n"
    <<"5. Zodiaco\n"
    <<"6. Nivel de grasa corporal\n"
    <<"7. Piedra, papel o tijera\n"
    <<"8. Estaciones\n"
    <<"0. Salir\n"
    <<"Teclea la opción: ";
    
    cin>>iOption;
    
    return iOption;
}


//*************************************************
//Relate each month with the number of days in it
//*************************************************
int daysMonth(int iMonth)
{
    
    //Relate each month with the number of days in it
    if(iMonth >= 1 && iMonth <= 12)
    {
        switch(iMonth)
        {
            case 2:
                return 28;
                break;
            case 4: case 6: case 9: case 11:
                return 30;
                break;
            default:
                return 31;
                break;
        }
    }
    return 0;
}


void calculadora(int iA, char cSigno, int iB){
    
    switch(cSigno)
    {
            
        case '+':
            cout<<iA<<" + "<<iB<<" = "<<(iA + iB)<<endl;
            break;
        case '-':
            cout<<iA<<" - "<<iB<<" = "<<(iA - iB)<<endl;
            break;
        case '*':
            cout<<iA<<" * "<<iB<<" = "<<(iA * iB)<<endl;
            break;
        case '/':
            if(iB != 0)
                cout<<iA<<" / "<<iB<<" = "<<(iA / iB)<<endl;
            else
                cout<<"Operación incorrecta\n";
            break;
        case '%':
            if(iB != 0)
                cout<<iA<<" % "<<iB<<" = "<<(iA % iB)<<endl;
            else
                cout<<"Operación incorrecta\n";
            break;
        default:
            cout<<"Operación incorrecta\n";
    }
}


void diaSiguiente(int iDia, int iMes, int iAño){
    
    //declaracion de variables
    int iDMes = diasMes(iMes);
    
    //desplegar fecha siguiente
    if(iDia>=1 && iDia<=iDMes && iDMes!=0 && iAño>=0)
    {
        //caso 1: cambia el día
        if(iDia < iDMes)
            iDia = iDia + 1;
        else
        {
            iDia = 1;
            
            //Caso 2: cambia el día y el mes
            if (iMes != 12)
                iMes = iMes + 1;
            else  //caso 3: cambia el dia, mes y el año
                iMes = 1;
            iAño = iAño +1;
        }
        
        cout<<iDia<<"/"<<iMes<<"/"<<iAño<<endl;
    }
    else
        cout<<"Fecha incorrecta!\n";
    
}

void zodiaco(int iZodiaco){
    
    //declaración de variables
    string sCategoria;
    
    //Pedir el numero del zodiaco
    cout<<"Signo\n"
    <<"1. Aries\n"
    <<"2. Tauro\n"
    <<"3. Géminis\n"
    <<"4. Cáncer\n"
    <<"5. Leo\n"
    <<"6. Virgo\n"
    <<"7. Libra\n"
    <<"8. Escorpión\n"
    <<"9. Sagitario\n"
    <<"10. Capricornio\n"
    <<"11. Acuario\n"
    <<"12. Piscis\n"
    "\n"
    <<"Teclea el número del signo: ";
    
    //leer el numero del zodiaco
    cin>>iZodiaco;
    
    switch(iZodiaco)
    {
        case 1: case 5: case 9:
            cout<<"Tu signo es de: "<<"Fuego"<<endl;
            break;
        case 2: case 6: case 10:
            cout<<"Tu signo es de: "<<"Tierra"<<endl;
            break;
        case 3: case 7: case 11:
            cout<<"Tu signo es de: "<<"Aire"<<endl;
            break;
        case 4: case 8: case 12:
            cout<<"Tu signo es de: "<<"Agua"<<endl;
            break;
        default:
            cout<<"ERROR "<<iZodiaco<<" no está asociado a nungún signo."<<endl;
            break;
    }
}

void piedraPapelTijera(int iTJ){
    
    //Declaración de variables
    int iTC;
    const int iPIEDRA = 1, iPAPEL = 2, iTIJERA = 3;
    
    //Leer tiro del jugador
    cout<<"Ingresa un valor 1.Piedra 2.Papel 3.Tijera = ";
    cin>>iTJ;
    
    //generar el tiro de la computadora de manera random
    srand(time(NULL));
    iTC = rand() % 3 + 1;
    
    //Asociar el tiro de la computadora con un valor del juego
    switch(iTC)
    {
        case iPIEDRA:
            cout<<"La computadora eligio PIEDRA!!\n";
            break;
        case iPAPEL:
            cout<<"La computadora eligio PAPEL!!\n";
            break;
        case iTIJERA:
            cout<<"La computadora eligio TIJERA!!\n";
            break;
        default:
            cout<<"La computadora hizo TRAMPA!!\n";
            break;
    }
    
    //Verificar casos de gane
    if(
       (iTJ == iPIEDRA && iTC == iTIJERA) ||
       (iTJ == iPAPEL && iTC == iPIEDRA) ||
       (iTJ == iTIJERA && iTC == iPAPEL)
       )
        cout<<"Ganaste un Output!!\n";
    else
        if(iTJ == iTC)
            cout<<"Empate!! suerte para la proxima\n";
        else
            cout<<"Gano la computadora, suerte para la proxima\n";
}

void estaciones(int iDia, int iMes, int iHemisferio){
    
    //declaración de variables
    int dDia;
    const int MARZO = 3,
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



/**************************************************************************/
/**************************************************************************/
/**************************************************************************/




int main(){
    
    //Variable Declaration
    int iOption, iMonth, iA, iB, iDia, iAño, iZodiaco, iTJ, iHemisferio, cSigno;
    
    //Save user's choice in variable
    iOption = menu();
    
    do{
        switch(iOption)
        {
            case 1:
                daysMonth(iMonth);
                break;
            case 2:
                calculadora(iA, cSigno, iB);
                break;
            case 4:
                diaSiguiente(iDia, iMonth, iAño);
                break;
            case 5:
                zodiaco(iZodiaco);
                break;
            case 7:
                piedraPapelTijera(iTJ);
                break;
            case 8:
                estaciones(iDia, iMonth, iHemisferio);
                break;
            default:
                cout<<"Opción Incorrecta\n";
                break;
        }
    }while(iOption!=0);
    
    return 0;
}
