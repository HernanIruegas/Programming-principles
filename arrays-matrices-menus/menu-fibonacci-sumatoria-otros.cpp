//
//  main.cpp
//  acumulador_ciclos
//
//  Created by Hernán Iruegas Villarreal on 11/03/16.
//  Copyright © 2016 Hernán Iruegas Villarreal. All rights reserved.
//

#include <iostream>
using namespace std;

void menu()
{
    cout<<"Menú de opciones\n"
        <<"1. Sumatoria 1 + 2+ 3 +...+ n\n"
        <<"2. Cuenta Positivos Negativos Ceros de n valores\n"
        <<"3. Tabla de Multiplicar del número x\n"
        <<"4. Promedio de n números\n"
        <<"5. Encuentra el Mayor de n números\n"
        <<"6. Cuenta Categorías Zodiacos\n"
        <<"7. Estadísticas de grasa corporal\n"
        <<"8. Encuentra el Menor de n números\n"
        <<"9. Sucesión de Fibonacci\n"
        <<"10. Adivina el siguiente número de la serie\n"
        <<"11. Encuentra el Menor, el Mayor y el Promedio de n valores\n"
        <<"12. Encuentra el Menor, el Mayor y el Promedio hasta que teclee 0\n"
        <<"13. Encuentra el Mayor hasta que teclee 0\n"
        <<"14. Encuentra el Menor hasta que teclee 0\n"
        <<"15. Encuentra el Promedio hasta que teclee 0\n"
        <<"0. Salir\n"
        <<"Teclea la opcion: ";
}


void sumatoria()
{
    
    //Declaración de variables
    int iK, iN, iAcum;
    
    iAcum = 0;
    
    cout<<"Este programa suma los numeros de 1 a n\n";
    cout<<"teclea el valor de n ";
    cin>>iN;
    
    iK=1;
    
    while(iK<=iN){
        iAcum = iAcum + iK;
        iK = iK + 1;
    }
    
    cout<<"Total = $"<<iAcum<<endl;
}


void cuentaPNC(int iN){
    
    //declaración de variables
    int iK, iNum, iCP, iCN, iCC; //iCP, iCN, iCC, son los acumuladores que se incrementan con 1, funcionan como contadores también
    
    if(iN>0)
    {
        //los acumuladores se inician en 0, porque al comienza hay 0 numeros positivos, negativos o ceros
        iCP = 0;
        iCN = 0;
        iCC = 0;
        
        //es la variable controladora del ciclo (vcc)
        iK = 1;
    
        while(iK<=iN)
        {
        
            //leer los números que teclea el usuario
            cout<<"Teclea un número: ";
            cin>>iNum;
        
            //actualizar la vcc
            iK = iK + 1;
        
            //analizar el valor que se teclea
            if(iNum>0)//es positivo
                iCP = iCP + 1;
            else
                if(iNum<0)
                    iCN = iCN + 1;//es negativo
                else
                    iCC = iCC + 1;//es cero
        }
        cout<<"Positivos: "<<iCP<<"\n"<<"Negativos: "<<iCN<<"\n"<<"Ceros: "<<iCC<<"\n"<<endl;
    }
    else
        cout<<"ERROR\n";
}

void tablaMultiplicar(int iN){
    
    //declaración de variables
    int iK;
    
    //variable controladora del ciclo
    iK = 10;
    
    //crear la tabla de multiplicación de manera decreciente
    while(iK>=1){
        cout<<iN<<" X "<<iK<<" = "<<(iN*iK)<<endl;
        iK = iK - 1;
    }
}

void promedioValores(int iN){
    
    //declaración de variables
    int iK, iNum, iAcumSuma, iAcumnumero;
    double dPromedio;
    
    iAcumSuma = 0;//acumulador de los números ingresados por el usuario
    iAcumnumero = 0;//contador de números ingresados por el usuario
    iK = 1;
    
    while(iK<=iN){
        //leer n
        cout<<"Teclea un valor: ";
        cin>>iNum;
        
        iAcumSuma = iAcumSuma + iNum;
        iAcumnumero = iAcumnumero + 1;
        
        iK = iK +1;
    }
    
    dPromedio = double(iAcumSuma)/iAcumnumero;//se divide el total sobre la cantidad de números que se ingresaron
    
    cout<<"El promedio es = "<<dPromedio<<endl;
}

void mayor(int iN){
    //declaración de variables
    int iK, iNum, iMayor;
    
    if(iN>0)
    {
        //inicio de la variable controladora de ciclo
        iK = 1;
        iMayor = INT_MIN; //se pone este número pequeño para que el numero del usuario a fuerza sea mayor
    
        while(iK<=iN)
        {
            //leemos el número que entra el usuario
            cout<<"Teclea el número: ";
            cin>>iNum;
            
            //se analiza el numero más grande disponible
            if(iNum>iMayor)
                iMayor = iNum;
        
            //actualizamos la vcc
            iK = iK + 1;
        }
        cout<<"El número más grande es = "<<iMayor<<endl;
    }
    else
        cout<<"ERROR\n";
    
}

void menor(int iN){
    //declaración de variables
    int iK, iNum, iMenor;
    
    if(iN>0)
    {
        //inicio de la variable controladora de ciclo
        iK = 1;
        iMenor = INT_MAX; //se pone este número grande para que el numero del usuario a fuerza sea menor
        
        while(iK<=iN)
        {
            //leemos el número que entra el usuario
            cout<<"Teclea el número: ";
            cin>>iNum;
            
            //se analiza el numero más grande disponible
            if(iNum<iMenor)
                iMenor = iNum;
            
            //actualizamos la vcc
            iK = iK + 1;
        }
        cout<<"El número más pequeño es = "<<iMenor<<endl;
    }
    else
        cout<<"ERROR\n";
    
}

void fibo(int iN){
    //declaración de variables
    int iK, iN1, iN2, iN3;
    
    if(iN>0)
    {
        if(iN==1)
            cout<<"0";
        else
            cout<<"0,1";
    
        //iniciar la variable controladora de ciclo
        iK = 3;
    
        //iniciar los primeros 2 numeros de la serie de fibonacci
        iN1 = 0;
        iN2= 1;
    
        while(iK<=iN)
        {
            //despliego la suma de los dos valores anteriores
            iN3 = iN1 + iN2;
            cout<<","<<iN3;
        
            //actualizo los dos valores que voy a sumar
            iN1 = iN2;
            iN2 = iN3;
    
            //actualizo la variable controladora de ciclo
            iK = iK + 1;
        }
    }
    else
        cout<<"ERROR\n";
}

void cuentaCategoriasZodiacos(int iN){
    //declaración de variables
    int iAcumFuego, iAcumTierra, iAcumAire, iAcumAgua, iSigno, iK;
    
    if(iN>0)
    {
        //variable controladora de ciclo
        iK = 1;
        
        //acumuladores (en este caso sirven como contadores)
        iAcumFuego = 0;
        iAcumTierra = 0;
        iAcumAire = 0;
        iAcumAgua = 0;
        
        while(iK<=iN)
        {
            //desplegar lista y leer signo
            cout<<"Signo\n"
                <<"1. Aries\n"
                <<"2. Tauro\n"
                <<"3. Géminis\n"
                <<"4. Cáncer\n"
                <<"5. Leo\n"
                <<"6. Virgo\n"
                <<"7. Libra\n"
                <<"8. Escorpión\n"
                <<"9. Sagitario\n"
                <<"10. Capricornio\n"
                <<"11. Acuario\n"
                <<"12. Piscis\n"
                <<"Teclea el número del signo: ";
            cin>>iSigno;
            
            //valida que el número de signo esté dentro de la lista, pedirlo hasta que esto se efectue
            while(iSigno<1||iSigno>12)
            {
                cout<<"ERROR\n";
                cout<<"Ingrese un número de signo valido: ";
                cin>>iSigno;
            }
            
            if(iSigno==1 || iSigno==5 || iSigno==9)
                iAcumFuego = iAcumFuego + 1;
            else
                if(iSigno==2 || iSigno==6 || iSigno==10)
                    iAcumTierra = iAcumTierra + 1;
            else
                if(iSigno==3 || iSigno==7 || iSigno==11)
                    iAcumAire = iAcumAire + 1;
            else
                    iAcumAgua = iAcumAgua + 1;
            
            //actualizar la variable controladora de ciclo
            iK = iK + 1;
        }
        cout<<"Cantidad de personas en la categoría de Fuego: "<<iAcumFuego<<endl;
        cout<<"Cantidad de personas en la categoría de Tierra: "<<iAcumTierra<<endl;
        cout<<"Cantidad de personas en la categoría de Aire: "<<iAcumAire<<endl;
        cout<<"Cantidad de personas en la categoría de Agua: "<<iAcumAgua<<endl;
    }
    else
    {
        cout<<"ERROR\n";
    }
}

void estadisticasNivelesGrasa(int iN){
    //declaración de variables
    int iK, iEdad, iCintura, iAcumBajo, iAcumNormal, iAcumAlto, iAcumMuyAlto, iAcumH;
    char iSexo;
    double dFormulaGrasaH, dPorcHBajo, dPorcHNormal, dPorcHAlto, dPorcHMuyAlto;
    
    //variable controladora de ciclo
    iK = 1;
    
    //acumuladores para cada nivel de grasa corporal
    iAcumBajo =0;
    iAcumNormal =0;
    iAcumAlto =0;
    iAcumMuyAlto =0;
    iAcumH = 0;
    
    while(iK<=iN)
    {
        //leer información del paciente
        cout<<"Ingresa la medida de tu cintura(cm): ";
        cin>>iCintura;
        
        cout<<"Ingresa tu edad: ";
        cin>>iEdad;
        
        cout<<"Ingresa tu sexo: ";
        cin>>iSexo;

        //
        if(iSexo=='H' && (iEdad>=20 && iEdad<=39))
        {
            iAcumH = iAcumH + 1;
            
            //formula para calcular la grasa corporal en hombres
            dFormulaGrasaH = (0.567 * iCintura)+(0.101 * iEdad) - 31.8;
            
            //colocar el resultado de grasa corporal con su respectivo acumulador
            if(dFormulaGrasaH<8.0)
            {
                iAcumBajo = iAcumBajo + 1;
                cout<<"Tu grasa corporal es BAJA\n";
            }
            else
            {
                if(dFormulaGrasaH<20.0)
                {
                    iAcumNormal = iAcumNormal +1;
                    cout<<"Tu grasa corporal es NORMAL\n";
                }
                else
                {
                    if(dFormulaGrasaH<25.0)
                    {
                        iAcumAlto = iAcumAlto +1;
                        cout<<"Tu grasa corporal es ALTA\n";
                    }
                    else
                    {
                        iAcumMuyAlto = iAcumMuyAlto +1;
                        cout<<"Tu grasa corporal es MUY ALTA\n";
                    }
                }
            }
        }
        
        iK = iK + 1;
    }
    
    //calcular porcentaje de hombres en cada categoria
    dPorcHBajo =  ((double)iAcumBajo / iAcumH)*100;
    dPorcHNormal = ((double)iAcumNormal / iAcumH)*100;
    dPorcHAlto = ((double)iAcumAlto / iAcumH)*100;
    dPorcHMuyAlto = ((double)iAcumMuyAlto / iAcumH)*100;
    
    //desplegar los resultados
    cout<<"Estadisticas para hombres:\n";
    cout<<"Nivel de grasa Bajo: "<<dPorcHBajo<<"%"<<endl;
    cout<<"Nivel de grasa Normal: "<<dPorcHNormal<<"%"<<endl;
    cout<<"Nivel de grasa Alto: "<<dPorcHAlto<<"%"<<endl;
    cout<<"Nivel de grasa Muy Alto: "<<dPorcHMuyAlto<<"%"<<endl;
    cout<<"No hubo estadísticas para Mujeres\n";
  
}

void promedio(){
    //declaración de variables
    int iNum, iAcum, iContador;
    double dPromedio;
    
    //pedir la variable controladora del ciclo centinela
    cout<<"Ingresa el número entero: ";
    cin>>iNum;
    
    iAcum= 0;//acumulador para sumar los valores enteros
    iContador=0;//acumulador para contar el número de valores enteros que se ingresan
    
    while(iNum!=0)
    {
        //actualizar los acumuladores
        iAcum = iAcum + iNum;
        iContador = iContador + 1;
        
        //actualizar la variable controladora del ciclo centinela
        cout<<"Ingresa el número entero: ";
        cin>>iNum;
    }
    
    if(iContador>0)
    {
        dPromedio = (double)iAcum / iContador;
        cout<<"El promedio es: "<<dPromedio<<endl;
    }
    else
        cout<<"No se procesaron valores\n";
}


void comboLocoCentinela(){
    //declaración de variables
    int iNum, iAcum, iContador, iMax, iMin;
    double dPromedio;
    
    //pedir la variable controladora del ciclo centinela
    cout<<"Ingresa el número entero: ";
    cin>>iNum;

    iAcum= 0;//acumulador para sumar los valores enteros
    iContador=0;//acumulador para contar el número de valores enteros que se ingresan
    iMax = INT_MIN;
    iMin = INT_MAX;
    
    while(iNum!=0)
    {
        //actualizar los acumuladores
        iAcum = iAcum + iNum;
        iContador = iContador + 1;
    
        if(iNum>iMax)//verificar si el número es el mayor
            iMax = iNum;
        if(iNum<iMin)//verificar si el número es el menor
            iMin = iNum;
            
        //actualizar la variable controladora del ciclo centinela
        cout<<"Ingresa el número entero: ";
        cin>>iNum;
    }
    //calcular el promedio de los números
    dPromedio = (double)iAcum / iContador;
        
    //desplegar resultados
    cout<<"El promedio es: "<<dPromedio<<endl;
    cout<<"El número mayor es: "<<iMax<<endl;
    cout<<"El número menor es: "<<iMin<<endl;
}


int main(){
    
    //Declaración de variables
    int iN, iOpcion;
    
    menu();
    cin>>iOpcion;
    
    while(iOpcion!=0)
    {
        switch(iOpcion)
        {
            case 1:
                sumatoria();
                break;
            
            case 2:
                //Leer iN
                cout<<"Teclea la cantidad de valores a procesar: ";
                cin>>iN;
                cuentaPNC(iN);
                break;
            
            case 3:
                //leer iN
                cout<<"Ingrese el número para crear su tabla de multiplicación: ";
                cin>>iN;
                tablaMultiplicar(iN);
                break;
                
            case 4:
                //leer iN
                cout<<"Ingresa la cantidad de números para calcular su promedio: ";
                cin>>iN;
                promedioValores(iN);
                break;
                
            case 5:
                //leer iN
                cout<<"Ingresa la cantidad de números: ";
                cin>>iN;
                mayor(iN);
                break;
                
            case 6:
                //leer iN
                cout<<"Ingresa la cantidad de personas a leer su signo de zodiaco: ";
                cin>>iN;
                cuentaCategoriasZodiacos(iN);
                break;
                
            case 7:
                //leer iN
                cout<<"Ingresa la cantidad de personas: ";
                cin>>iN;
                estadisticasNivelesGrasa(iN);
                break;
            
            case 8:
                //leer iN
                cout<<"Ingresa la cantidad de números: ";
                cin>>iN;
                menor(iN);
                break;
            
            case 9:
                //leer iN
                cout<<"Ingresa la cantidad de números de la serie que deseas que se desplieguen: ";
                cin>>iN;
                fibo(iN);
                break;
                
            case 12:
                comboLocoCentinela();
                break;
                
            case 15:
                promedio();
                break;
            
            
                
        }
        cout<<"\n";
        menu();//para que se despliegue el menu otra vez
        cin>>iOpcion;//para que el usuario escoga la función de nuevo o pueda salirse
    }
    cout<<"Gracias por usar nuestro Software con Calidad!!\n";
}
