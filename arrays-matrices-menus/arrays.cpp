//Hernán Iruegas Villarreal
//Some basic functions using arrays

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;


//***********************************
//Display option menu and
//get user's option
//***********************************
int menu()
{
    //Variable declaration
    int iOption;
    
    //Display menu and get user's choice
    cout<<"Arrays\n"
        <<"1. Random Values\n"
        <<"2. Pattern 1\n"
        <<"3. Pattern 2\n"
        <<"4. Pattern 3\n"
        <<"5. Biggest number\n"
        <<"6. Smallest number\n"
        <<"7. Sum\n"
        <<"8. Average\n"
        <<"9. Find value\n"
        <<"10. Find position of a value\n"
        <<"11. Count Repetitions\n"
        <<"12. Copy backwards\n"
        <<"13. Copy exactly\n"
        <<"Enter a number: ";
    
    cin>>iOption;
    
    return iOption;
}


//***********************************
//Display arrays
//***********************************
void display(int iArrA[], int iSize)
{
    for(int iK=0; iK<iSize; iK++)
        cout<<"a["<<iK<<"]="<<iArrA[iK]<<endl;
}


//***********************************
//Display arrays that contain strings
//***********************************
void displayStrings(string sArrA[], int iSize)
{
    for (int iK=0; iK<iSize; iK++)
        cout<<"Array["<<iK<<"]="<<sArrA[iK]<<endl;
}


//***********************************
//Initialize an array with random values
//between a specific range
//a[0] = 67
//a[1] = 34
//a[2] = 89
//a[3] = 12
//***********************************
void randomValues(int iArrA[], int iSize)
{
    srand(time(NULL));//to generate a new seed each time it initializes
    for(int iK=0; iK<iSize; iK++)
        iArrA[iK]= rand()%100+1;//range: 1-100
}


//***********************************
//Initialize an array following this pattern
//0, 2, 4, 6,.....
//a[0] = 0
//a[1] = 2
//a[2] = 4
//a[3] = 6
//***********************************
void plusTwo(int iArrA[], int iSize)
{
    for(int iK=0; iK<iSize; iK++)
        iArrA[iK]= iK*2;
}


//***********************************
//Initialize an array taking into consideration its size.
//If it is 10, the pattern should be decremental as of 9,8,7...
//If its size is 4 the pattern should be 3,2,1,0
//a[0] = 3
//a[1] = 2
//a[2] = 1
//a[3] = 0
//***********************************
void decremental(int iArrA[], int iSize)
{
    for(int iK=0, iS=iSize-1; iK<iSize; iK++, iS--)
        iArrA[iK]=iS;
}


//***********************************
//Initialize an array following the next pattern:
//1, 2, 4, 8, 16, 32, etc.
//a[0] = 1
//a[1] = 2
//a[2] = 4
//a[3] = 8
//a[4] = 16
//***********************************
void exponential(int iArrA[], int iSize)
{
    //Variable declaration
    int iValue=1;
    
    for(int iK=0; iK<iSize; iK++)
    {
        iArrA[iK]= iValue;
        //update variable
        iValue= iValue*2;
    }
}


//***********************************
//Return the biggest number inside
//the array
//***********************************
int biggestNumber(int iArrA[], int iSize)
{
    //Variable declaration
    int iMax= INT_MIN;//is equal to the smallest whole number in order to force the first number of the array to be bigger
                      //so iMax will always have a value
    
    for(int iK=0; iK<iSize; iK++)
        if(iArrA[iK]>iMax)
            iMax=iArrA[iK];
    
    return iMax;
}


//***********************************
//Return the smallest number inside
//the array
//***********************************
int smallestNumber(int iArrA[], int iSize)
{
    //Variable declaration
    int iMin= INT_MAX;//is equal to the biggest whole number in order to force the first number of the array to be smaller
                      //so iMax will always have a value
    
    for(int iK=0; iK<iSize; iK++)
        if(iArrA[iK]<iMin)
            iMin=iArrA[iK];
    
    return iMin;
}


//***********************************
//Return the sum of all values inside
//the array
//***********************************
int sum(int iArrA[], int iSize)
{
    //Variable declaration
    int iAcum=0;
    
    for(int iK=0; iK<iSize; iK++)
        iAcum= iAcum + iArrA[iK];//sum value inside the array to the acummulator
    
    return iAcum;
}


//***********************************
//Return average of all numbers inside the array
//***********************************
double average(int iArrA[], int iSize)
{
    //Variable declaration
    int iAcum=0, iCounter=0;
    
    for(int iK=0; iK<iSize; iK++)
    {
        iAcum= iAcum+iArrA[iK];
        iCounter= iCounter+1;
    }
    
    return double(iAcum)/iCounter;//need a casting in order to return average with decimal value
}


//***********************************
//Return true if value used as parameter is inside the array
//Return false if it is not inside the array
//***********************************
bool findValue(int iArrA[], int iSize, int iValue)
{
    for(int iK=0; iK<iSize; iK++)
    {
        if(iArrA[iK]==iValue)
            return true;
    }
    
    return false;
}


//***********************************
//If the value is inside the array, return its position
//If it is not inside, return -1
//***********************************
int findPositionValue(int iArrA[], int iSize, int iValue)
{
    for(int iK=0; iK<iSize; iK++)
    {
        if(iArrA[iK]==iValue)
            return iK;
    }
    
    return -1;
}


//***********************************
//Return how many times a specific number exists inside an array
//***********************************
int countRepetitions(int iArrA[], int iSize, int iValue)
{
    //Variable declaration
    int iCounter=0;
    
    for(int iK; iK<iSize; iK++)
    {
        if(iArrA[iK]==iValue)
            iCounter=iCounter+1;
        
    }
        
    return iCounter;
}


//***********************************
//Copy an array backwards in another array
//Return true if it was possible, false if it was not
//***********************************
bool copyBackwards(int iArrA[], int iSizeA, int iArrB[], int iSizeB)
{
    //Verify that both arrays are the same size in order proceed to copy
    if (iSizeA!=iSizeB)
        return false;
    
    for(int iK=0, iS=iSizeB-1; iK<iSizeA; iK++, iS--)
    {
        iArrB[iK]=iArrA[iS]; //the first element of iArrB will be the last one in iArrA
                             //iArrB[0]=iArrA[iS]
    }
    
    return true;
}


//***********************************
//Copy an array into another one exactly as original
//Return true if it was possible, false if it was not
//***********************************
bool copyArray(int iArrA[], int iSizeA, int iArrB[], int iSizeB)
{
    //Verify that both arrays are the same size in order proceed to copy
    if (iSizeA!=iSizeB)
        return false;

    for(int iK=0; iK<iSizeB; iK++)
    {
        iArrB[iK]=iArrA[iK];
    }
    
    return true;
}


bool palindromeArreglo(int iArrA[], int iSA, int iArrB[], int iSB){
    
    //para checar si son del mismo tamaño
    if (iSA!=iSB)
        return false;
    
    //recorrer todo el arreglo
    for(int iK=0; iK<iSA; iK++){
        if(iArrA[iK] != iArrB[iK])//si 1 elemento es diferente, entonces ya no es un palindromo
            return false;
    }
    
    return true;
}




int main()
{
    int iArrA[]={7, 10,8,2,3,15,12,13,40,15};
    int iArrB[10];
    int iOption, iValue,iPrize, iTotal, iRepetitions;
    double dAverage;
    string sArrGuisados[]={
        "Trompo",
        "Barbacoa",
        "Arrachera",
        "Chicharron",
        "Tripa",
        "Deshebrada",
        "Picadillo",
        "Carnitas",
        "Papa",
        "Cabeza",
        "Lengua",
        "Sesos",
        "Machacado",
        "Rajas con Queso"};
    
    do
    {
        iOption = menu();
        switch (iOption) {
            case 0:
                cout<<"Bye!!!\n";
                break;
            case 1:
                randomValues(iArrA, 10);
                display(iArrA, 10);
                break;
            case 2:
                plusTwo(iArrA, 10);
                display(iArrA, 10);
                break;
            case 3:
                decremental(iArrA, 10);
                display(iArrA, 10);
                break;
            case 4:
                exponential(iArrA, 10);
                display(iArrA, 10);
                break;
            case 5:
                display(iArrA, 10);
                cout<<"The biggest number is ="<<biggestNumber(iArrA,10)<<endl;
                break;
            case 6:
                display(iArrA, 10);
                cout<<"The smallest number is ="<<smallestNumber(iArrA,10)<<endl;
                break;
            case 7:
                display(iArrA, 10);
                iTotal = sum(iArrA, 10);
                cout<<"Total= "<<iTotal<<endl;
                break;
            case 8:
                display(iArrA, 10);
                dAverage= average(iArrA, 10);
                cout<<"The average is: "<<dAverage<<endl;
                break;
            case 9:
                display(iArrA, 10);
                //Get value used to search in function
                cout<<"Enter your ticket number: ";
                cin>>iValue;
                //The condition returns a boolean value
                if(findValue(iArrA,10,iValue))
                    cout<<"Your ticket is in the list, congrats!!\n";
                else
                    cout<<"We could not find your ticket, buy another one\n";
                break;
            case 10:
                display(iArrA, 10);
                //Get value used to search in function
                cout<<"Enter your ticket number: ";
                cin>>iValue;
                //Give a prize if the number is inside the array
                iPrize= findPositionValue(iArrA,10,iValue);
                if(iPrize != -1)
                    cout<<"Your prize is number: "<<iPrize<<", which represent some delicious tacos of: "<<sArrGuisados[iPrize] <<endl;
                else
                    cout<<"You did not win a prize\n";
                break;
            case 11:
                display(iArrA, 10);
                cout<<"Enter your ticket number: ";
                cin>>iValue;
                iRepetitions= countRepetitions(iArrA,10,iValue);
                cout<<"Number of times repeated: "<<iRepetitions<<endl;
                break;
            case 12:
                //Display arrays
                cout<<"\nArray A\n";
                display(iArrA, 10);
                cout<<"\n\nArray B\n";
                display(iArrB, 10);
                //Condition will return a boolean value
                if (copyBackwards(iArrA, 10, iArrB, 10))
                {
                    cout<<"\nWe could copy the array!!\n";
                    cout<<"\nNew Array B\n";
                    display(iArrB, 10);
                }
                else
                {
                    cout<<"The procedure was not possible\n";
                }
                break;
            case 13:
                //Display arrays
                cout<<"\nArray A\n";
                display(iArrA, 10);
                cout<<"\n\nArray B\n";
                display(iArrB, 10);
                //Condition will return a boolean value
                if (copyArray(iArrA, 10, iArrB, 10))
                {
                    cout<<"\nWe could copy the array!!\n";
                    cout<<"\nNew Array B\n";
                    display(iArrB, 10);
                }
                else
                {
                    cout<<"The procedure was not possible\n";
                }
                break;
                
            default:
                break;
        }
    }while (iOption!= 0);
    
    return 0;
}


