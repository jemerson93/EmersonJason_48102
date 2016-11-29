/* 
   File:   main
   Author: Jason Emerson
   Created on November 17th, 2016, 11:11PM
   Purpose: Using an array and File I/O get the lowest, highest, total and average numbers in an array
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Exit Return
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void highestNum(int numbers[],int SIZE,int &highest);
void lowestNum(int numbers[],int SIZE, int &lowest);
int getTot(int numbers[],int SIZE);
void getAverage(int numbers[],int SIZE,float &average);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int NUM=5;
    int sales[NUM];
    string name[NUM]={"Mild","Medium","Sweet","Hot","Zesty"};
    int totSold;
    int hiProd;
    int lowProd;
    
    //Input values
    for(int type=0;type<NUM;type++){
        cout<<"Jars sold last month of "<<name[type]<<": "<<endl;
        cin>>sales[type];
        while(sales[type]<0){
            cout<<"Jars sold must be 0 or more. Please enter a number again"<<endl;
            cin>>sales[type];
        }
    }
    
    //Process values -> Map inputs to Outputs
    totSold=getTotal(sales,NUM);
    lowProd=lowestSold(sales,NUM);
    hiProd=highestSold(sales,NUM);
    
    //Display Output
    cout<<endl;
    cout<<"     Salsa Sales Report:"<<endl;
    cout<<"Name              Jars Sold"<<endl;
    cout<<"______________________________"<<endl;
    cout<<endl;
    cout<<name[0]<<"                  "<<sales[0]<<endl;
    cout<<name[1]<<"                "<<sales[1]<<endl;
    cout<<name[2]<<"                 "<<sales[2]<<endl;
    cout<<name[3]<<"                   "<<sales[4]<<endl;
    cout<<name[4]<<"                 "<<sales[3]<<endl;
    cout<<endl;
    cout<<"Total Sales:   "<<totSold<<endl;
    cout<<"Highest Sold: "<<name[hiProd]<<endl;
    cout<<"Lowest Sold:  "<<name[lowProd]<<endl;

    //Exit Program
    return 0;
}

/*********************************************************************
 *                          getTotal                                 *
 * Process: Calculates and returns the total of the values stored in *
 * the array passed to the function.                                 *           
 * Input: None                                                       *
 * Output: total                                                     *
 *********************************************************************/
int getTotal(int array[],int numElts){
    //Declaration of Variables
    int total=0;
    
    //Process Values
    for(int type=0;type<numElts;type++)
        total+=array[type];
                
    return total;
}

/*********************************************************************
 *                          posOfSmallest                            *
 *                                                                   *
 * Process: Finds and returns the subscript of the array position    *
 * holding the smallest value in the array into the function.        *           
 * Input: None                                                       *
 * Output: indSma                                                    *
 *********************************************************************/
int lowestSold(int array[],int numElts){
    int indSmal=0;
    
    //Process Values
    for(int pos=1;pos<numElts;pos++){
        if(array[pos]<array[indSmal])
            indSmal=pos;
    }
    return indSmal;
}

/*********************************************************************
 *                          posOfLargest                             *
 * Process: Finds and returns the subscript of the array position    *
 * holding the largest value in the array into the function.         *           
 * Input: None                                                       *
 * Output: indLarg                                                   *
 *********************************************************************/
int highestSold(int array[],int numElts){
    //Declaration of Variables
    int indLarg=0;
    
    //Process Values
    for(int pos=1;pos<numElts;pos++){
        if(array[pos]>array[indLarg])
            indLarg=pos;
    }
    return indLarg;
}