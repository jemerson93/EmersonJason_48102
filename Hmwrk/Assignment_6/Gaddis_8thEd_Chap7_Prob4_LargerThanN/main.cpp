/* 
 * File: main
 * Author: Jason Emerson
 * Created November 17th, 2016, 11:11PM
 * Purpose: Display all numbers in an array that are greater then the number n
*/  

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number generator
#include <cmath>      //Time
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void greaterNum(int [],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Set random number seed
    srand(static_cast<unsigned>(time(0)));

    //Declaration of Variables
    const int SIZE=5; //Size of the array
    int numbers[SIZE]; //Array to store the numbers
    int num;           //The input number
    
    //Input Values
    cout<<"Enter any number"<<endl;
    cin>>num;
    
    //Process Values
    for(int i=0;i<SIZE;i++){
        numbers[i]=rand()%90+10;
    }
    
    //Display Outputs
    for(int i=0;i<SIZE;i++){
        cout<<numbers[i]<<endl;
    }
    cout<<endl;
    cout<<"The numbers greater than "<<num<<" are ";
    greaterNum(numbers,SIZE,num);
    
    //Exit Program
    return 0;
}

/*********************************************************************
 *                          greaterNum                               *
 * Process: Calculates the numbers greater                           *
 * Input: None                                                       *
 * Output: Void                                                      *
 *********************************************************************/
void greaterNum(int a[],int p,int j){
    //Process Values
    for(int i=0;i<p;i++){
        if(a[i]>j)cout<<a[i]<<" ";
    }
}