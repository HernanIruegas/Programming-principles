//Hernán Iruegas Villarreal
//Some basic functions using matrices



#include <iostream>
#include <limits.h>
#include <time.h>
using namespace std;

//Global constants declaration
const int iCOLUMNS=5, iROWS=5;


//*****************************************
//Display menu and get user's option
//*****************************************
int menu()
{
    //Variable declaration
    int iOption;
    
    cout<<" Matrices\n"
        <<"1.  Zeroes\n"
        <<"2.  Pattern 1\n"
        <<"3.  Pattern 2\n"
        <<"4.  Counter Row\n"
        <<"5.  Counter Column\n"
        <<"6.  Biggest number\n"
        <<"7.  Smallest number\n"
        <<"8.  Sum\n"
        <<"9.  Average\n"
        <<"10. Find a number\n"
        <<"11. Count repetitions of a number\n"
        <<"12. Copy matrix\n"
        <<"13. Copy backwards\n"
        <<"14. Biggest number in each row\n"
        <<"15. Initialize matrix with random values without repetition\n"
        <<"16. Tic Tac Toe\n"
        <<"0.  Leave\n"
        <<"Enter a number:";
    
    cin>>iOption;
    
    return  iOption;
}


//*****************************************
//Display matrix
//*****************************************
void display(int iMatA[][iCOLUMNS], int iReng, int iCol)
{
    cout<<"    ";
    for(int iC=0; iC<iCol; iC++)
        cout << iC <<"\t";
    cout<<"\n";
    for(int iC=0; iC<iCol; iC++)
        cout << "_____";
    cout<<"\n";
    for (int iR=0; iR<iReng; iR++)
    {
        cout<<iR<<"|";
        for(int iC=0; iC<iCol; iC++)
            cout <<"\t"<< iMatA[iR][iC];
        cout<<"\n";
    }
}


//*****************************************
//Initialize matrix with zeroes
//*****************************************
void zeroes(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    for (int iR=0; iR<iRows; iR++)
        for (int iC=0; iC<iColumns; iC++)
            iMatA[iR][iC]=0;
}


//*****************************************
//Initialize matrix with the following pattern:
//with column value
//01234
//01234
//01234
//*****************************************
void pattern1(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    for (int iR=0; iR<iRows; iR++)
        for (int iC=0; iC<iColumns; iC++)
            iMatA[iR][iC]=iC;
}


//*****************************************
//Initialize matrix with the following pattern:
//with row value
//00000
//11111
//22222
//*****************************************
void pattern2(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    for (int iR=0; iR<iRows; iR++)
        for (int iC=0; iC<iColumns; iC++)
            iMatA[iR][iC]=iR;
}


//*****************************************
//Initialize matrix with consecutive values
//using a counter
//travel matrix by rows
//01234
//56789
//.....
//*****************************************
void counterRow(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    for (int iR=0, iCounter=0; iR<iRows; iR++)
        for (int iC=0; iC<iColumns; iC++)
            iMatA[iR][iC]=iCounter++;
}


//*****************************************
//Initialize matrix with consecutive values
//using a counter
//travel matrix by columns
//0369
//147..
//258..
//*****************************************
void counterCol(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    for (int iC=0, iCounter=0; iC<iColumns; iC++)
        for (int iR=0; iR<iRows; iR++)
            iMatA[iR][iC]=iCounter++;
}


//***********************************
//Return the biggest number inside
//the matrix
//***********************************
int biggestNumber(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    //Variable declaration
    int iMax=INT_MIN;//is equal to the smallest whole number in order to force the first number of the matrix to be bigger
                     //so iMax will always have a value
    
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            if(iMatA[iR][iC]>iMax)
                iMax=iMatA[iR][iC];
        }
    }
    
    return iMax;
}


//***********************************
//Return the smallest number inside
//the matrix
//***********************************
int smallestNumber(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    //Variable declaration
    int iMin= INT_MAX;//is equal to the biggest whole number in order to force the first number of the matrix to be smaller
                      //so iMax will always have a value
    
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            if(iMatA[iR][iC]<iMin)//si el valor es menor al valor de iMin, entonces
                iMin=iMatA[iR][iC];//se guarda el valor en iMin
        }
    }
    
    return iMin;
}


//***********************************
//Return the sum of all values inside
//the matrix
//***********************************
int sum(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    //Variable declaration
    int iAcum=0;
    
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            iAcum= iAcum + iMatA[iR][iC];
        }
    }
    
    return iAcum;
}


//***********************************
//Return average of all numbers inside the matrix
//***********************************
double average(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    //Variable declaration
    int iAcum, iCounter;
    
    iAcum=0;
    iCounter=0;
    
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            iAcum= iAcum + iMatA[iR][iC];
            iCounter= iCounter+1;
        }
    }
    
    return double(iAcum)/iCounter;
}


//***********************************
//Return true if value used as parameter is inside the matrix
//Return false if it is not inside the matrix
//***********************************
bool findValue(int iMatA[][iCOLUMNS], int iRows, int iColumns, int iValue)
{
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            if(iMatA[iR][iC]==iValue)//if the value equals the one in the matrix return true
                return true;
        }
    }

    return false;
}


//***********************************
//Return how many times a specific number exists inside the matrix
//***********************************
int countRepetitions(int iMatA[][iCOLUMNS], int iRows, int iColumns, int iValue)
{
    //Variable declaration
    int iCounter= 0;
    
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            if(iMatA[iR][iC]==iValue)
                iCounter= iCounter+1;
        }
    }
    
    return iCounter;
}


//***********************************
//Copy a matrix into another one exactly as original
//Return true if it was possible, false if it was not
//***********************************
bool copyMatrix(int iMatA[][iCOLUMNS], int iRowsA, int iColumnsA, int iMatB[][iCOLUMNS], int iRowsB, int iColumnsB)
{
    
    //Verify that both matrices are the same size in order proceed to copy
    if(iRowsA!=iRowsB || iColumnsA!=iColumnsB)
        return false;
    
    //Copy elements from matrix M to matrix B
    for(int iR=0; iR<iRowsB; iR++)
    {
        for(int iC=0; iC<iColumnsB; iC++)
        {
            iMatB[iR][iC]=iMatA[iR][iC];
        }
    }
    //End of copying
    return true;
}


//***********************************
//Copy a matrix backwards in another matrix
//Return true if it was possible, false if it was not
//***********************************
bool copyBackwards(int iMatA[][iCOLUMNS], int iRowsA, int iColumnsA, int iMatB[][iCOLUMNS], int iRowsB, int iColumnsB)
{
    
    //Verify that both matrices are the same size in order proceed to copy
    if(iRowsA!=iRowsB || iColumnsA!=iColumnsB)
        return false;
    
    //Copy elements from matrix A to matrix B backwawrds
    for(int iR=0, iRows=iRowsA-1; iR<iRowsA; iR++, iRows--)//A variable is created to locate us on the last row
    {
        for(int iC=0, iCol=iColumnsA-1; iC<iColumnsA; iC++, iCol--)//A variable is created to locate us on the last column
        {
            iMatB[iR][iC]=iMatA[iRows][iCol];//Value [0][0] is equal to value [1][3]
        }
    }
    //End of copying
    return true;
}


//***********************************
//Return the biggest number of each row
//inside the matrix, with its corresponding position
//Store both values in another matrix
//***********************************
void biggestForEachRow(int iMatA[][iCOLUMNS], int iRowsA, int iColumnsA, int iMatB[][iCOLUMNS])
{
    for(int iR=0; iR<iRowsA; iR++)
    {
        //Variable declaration
        int iMax= INT_MIN;//is equal to the smallest whole number in order to force the first number of the matrix to be                                  bigger
                          //so iMax will always have a value
        
        for(int iC=0; iC<iColumnsA; iC++)
        {
            if(iMatA[iR][iC]>iMax)//Verify if number is greater than iMax
            {
                iMax=iMatA[iR][iC];//Store value in iMax
                iMatB[iR][1]= iC;//Store iMax index number on second column of new matrix
            }
        }
        iMatB[iR][0]= iMax;//Store iMax on firt column of new matrix
    }
    
}


//***********************************
//Initialize a matrix with random values
//Do not repeat any number inside the matrix
//***********************************
void randomValuesNoRepetition(int iMatA[][iCOLUMNS], int iRows, int iColumns)
{
    //Variable declaration
    int iValue;
    
    srand(time(NULL));
    //Initialize matrix with zeroes(a value that is not inside the range of 1 - 54)
    //So that the function "findValue" will not be capable of finding a repeated value inside the matrix when it even has not been initialized with random values
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            iMatA[iR][iC]= 0;
        }
    }
    
    //Now its time to initialize the matrix with random values
    //without any number to be repeated
    for(int iR=0; iR<iRows; iR++)
    {
        for(int iC=0; iC<iColumns; iC++)
        {
            iValue= rand()%54+1;
            while(findValue(iMatA, iROWS, iCOLUMNS, iValue))//if function did finds a repeated number, then generate another
            {
                iValue= rand()%54+1;
            }
            
            iMatA[iR][iC]= iValue;
        }
    }
}


//***********************************
//TIC TAC TOE
//Return true if user wins by any case:
//Main and secondary diagonals
//Any row or column
//Return false if user did not wins
//***********************************
bool ticTacToe(int iMatA[][iCOLUMNS], int iRows, int iColumns, int iValue)
{
    //Variable declaration
    bool bWin;
    
    //Verify if matrix is square
    if (iRows==iColumns)
    {
        bWin = true;
        //Verify if user wins in main diagonal
        for (int iK=0; iK<iRows; iK++)
            if (iMatA[iK][iK] != iValue)
                bWin = false;
        if(bWin)
        {
            cout<<"You won through the main diagonal!!\n";
            return true;
        }
        
        //Verify if user wins in secondary diagonal
        bWin=true;
        for (int iR=0, iC=iColumns-1; iR<iRows; iR++, iC--)
            if (iMatA[iR][iC] != iValue)
                bWin = false;
        if(bWin)
        {
            cout<<"You won through the secondary diagonal!!\n";
            return true;
        }
        
        //Verify if user wins in any row
        for (int iR=0; iR<iRows; iR++)
        {
            bWin=true;
            for (int iC=0; iC<iColumns; iC++)
            {
                if (iMatA[iR][iC] != iValue)
                    bWin = false;
            }
            if(bWin)
            {
                cout<<"You won through a row!!\n";
                return true;
            }
        }
        
        //Verify if user wins in any column
        for (int iC=0; iC<iColumns; iC++)
        {
            bWin=true;
            for (int iR=0; iR<iRows; iR++)
            {
                if (iMatA[iR][iC] != iValue)
                    bWin = false;
            }
            if(bWin)
            {
                cout<<"You won through a column!!\n";
                return true;
            }
        }
        //If none of the wining scenarios are true, then you lost
        cout<<"You did not win\n";
        return false;
    }
    //If matrix is not squared
    cout<<"Matrix is not squared\n";
    return false;
}


int main() {
    
    int iMatB[iROWS][iCOLUMNS];
    
    int iOption, iResp, iValue;
    double dResp;
    
    int  iMatA[][iCOLUMNS]=
    {   {1,10,20,21,1},
        {34,12,10,0,90},
        {3,12,1,4,4},
        {56,23,12,2,34},
        {156,23,12,12,3}
    };
    
    //TIC TAC TOE wins through main diagonal
    int  iMatA1[][iCOLUMNS]=
    {   {1,0,0,0,1},
        {0,1,0,0,1},
        {0,0,1,0,1},
        {0,0,0,1,1},
        {0,0,0,0,1}
    };
    //TIC TAC TOE wins through a column
    int  iMatA2[][iCOLUMNS]=
    {   {0,0,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,1},
        {0,1,1,1,1},
        {1,0,0,0,1}
    };
    //TIC TAC TOE wins through a row
    int  iMatA3[][iCOLUMNS]=
    {
        {0,1,0,0,0},
        {0,0,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {1,0,0,0,1}
    };
    //TIC TAC TOE wins through secondary diagonal
    int  iMatA4[][iCOLUMNS]=
    {   {0,0,0,0,1},
        {0,1,0,1,0},
        {0,0,1,0,0},
        {0,1,0,1,1},
        {1,0,0,0,1}
    };
    //TIC TAC TOE loser
    int  iMatA5[][iCOLUMNS]=
    {   {10,30,40,50,15},
        {10,41,40,51,10},
        {30,40,51,60,80},
        {30,31,30,31,31},
        {31,30,40,50,61}
    };
    
    
    do
    {
        //Initialize and update variable
        iOption = menu();
        
        switch (iOption)
        {
            case 0:
                cout<<"Bye!!!\n";
                break;
            case 1:
                //Initialize with zeroes
                zeroes(iMatA,iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 2:
                //Initialize with column value
                pattern1(iMatA,iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 3:
                //Initialize with row value
                pattern2(iMatA,iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 4:
                //Initialize with consecutive values (rows)
                counterRow(iMatA,iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 5:
                //Initialize with consecutive values (columns)
                counterCol(iMatA,iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 6:
                //Return biggest number
                display(iMatA,iROWS, iCOLUMNS);
                iResp=biggestNumber(iMatA,iROWS, iCOLUMNS);
                //Desplegar el mayor
                cout<<"The biggest number is ="<<iResp<<endl;
                break;
            case 7:
                //Return smallest number
                display(iMatA,iROWS, iCOLUMNS);
                iResp=smallestNumber(iMatA,iROWS, iCOLUMNS);
                //Desplegar el menor
                cout<<"The smallest number is ="<<iResp<<endl;
                break;
            case 8:
                //Sum of all values
                display(iMatA,iROWS, iCOLUMNS);
                iResp=sum(iMatA,iROWS, iCOLUMNS);
                //Display sum
                cout<<"The sum is = "<<iResp<<endl;
                break;
            case 9:
                //Return average
                display(iMatA,iROWS, iCOLUMNS);
                dResp=average(iMatA,iROWS, iCOLUMNS);
                //Display average
                cout<<"The average is = "<<dResp<<endl;
                break;
            case 10:
                display(iMatA,iROWS, iCOLUMNS);
                //Get value
                cout<<"Enter a number: ";
                cin>>iValue;
                //Search value
                if(findValue(iMatA,iROWS, iCOLUMNS, iValue))
                    cout<<"Your number is inside!!\n";
                else
                    cout<<"We could not find your number\n";
                break;
            case 11:
                //Get value
                cout<<"Enter a number: ";
                cin>>iValue;
                //Count repetitions
                dResp=countRepetitions(iMatA,iROWS, iCOLUMNS, iValue);
                //Display repetitions
                cout<<"The number is repeated "<<dResp<<" times inside the matrix"<<endl;
                break;
            case 12:
                //Copy matrix
                //Display matrices
                cout<<"\nMATRIX A\n"<<endl;
                display(iMatA,iROWS, iCOLUMNS);
                cout<<"\n\nMATRIX B\n\n";
                display(iMatB,iROWS, iCOLUMNS);
                //Verify if procedure was possible
                if (copyMatrix(iMatA, iROWS, iCOLUMNS, iMatB, iROWS, iCOLUMNS))
                {
                    cout<<"\nWe could copy the matrix!!\n";
                    cout<<"\nNew B matrix\n\n";
                    display(iMatB,iROWS, iCOLUMNS);
                }
                else
                    cout<<"Procedure was not possible, sizes are different\n";
                break;
            case 13:
                //Copy backwards
                //Display matrices
                cout<<"\nMATRIX A\n"<<endl;
                display(iMatA,iROWS, iCOLUMNS);
                cout<<"\n\nMATRIX B\n\n";
                display(iMatB,iROWS, iCOLUMNS);
                //Verify if procedure was possible
                if(copyBackwards(iMatA, iROWS, iCOLUMNS, iMatB, iROWS, iCOLUMNS))
                {
                    cout<<"\nWe could copy the matrix!!\n";
                    cout<<"\nNew B matrix\n\n";
                    display(iMatB,iROWS, iCOLUMNS);
                }
                else
                    cout<<"Procedure was not possible, sizes are different\n";
                break;
            case 14:
                //Return biggest number for each row
                biggestForEachRow(iMatA, iROWS, iCOLUMNS, iMatB);
                display(iMatA, iROWS, iCOLUMNS);
                display(iMatB, iROWS, 2);
                break;
            case 15:
                //randomValuesNoRepetition
                randomValuesNoRepetition(iMatA, iROWS, iCOLUMNS);
                display(iMatA,iROWS, iCOLUMNS);
                break;
            case 16:
                //Win tic tac toe
                //Include all tests
                //Main diagonal with iMatA1
                display(iMatA1,iROWS, iCOLUMNS);
                if (ticTacToe(iMatA1, iROWS, iCOLUMNS, 1))
                    cout<<"Congrats!!\n";
                else
                    cout<<"Sorry, better luck next time!!\n";
                //Win by column with iMatA2
                display(iMatA2,iROWS, iCOLUMNS);
                if (ticTacToe(iMatA2, iROWS, iCOLUMNS, 1))
                    cout<<"Congrats!!\n";
                else
                    cout<<"Sorry, better luck next time!!\n";
                //Win by row with iMatA3
                display(iMatA3,iROWS, iCOLUMNS);
                if (ticTacToe(iMatA3, iROWS, iCOLUMNS, 1))
                    cout<<"Congrats!!\n";
                else
                    cout<<"Sorry, better luck next time!!\n";
                //Secondary diagonal with iMatA4
                display(iMatA4,iROWS, iCOLUMNS);
                if (ticTacToe(iMatA4, iROWS, iCOLUMNS, 1))
                    cout<<"Congrats!!\n";
                else
                    cout<<"Sorry, better luck next time!!\n";
                //No win iMatA5
                display(iMatA5,iROWS, iCOLUMNS);
                if (ticTacToe(iMatA5, iROWS, iCOLUMNS, 1))
                    cout<<"Congrats!!\n";
                else
                    cout<<"Sorry, better luck next time!!\n";
                break;
            default:
                break;
        }
    }while (iOption != 0);
    
    return 0;
}
