/* 
   File:   main
   Author: Jason Emerson
   Created on November 17th, 2016, 10:06 PM
   Purpose: Enter 10 values and display in an array the largest and smallest value  
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int min;               //Minimum value entered
    int max;              //Maximum value entered
    const int NUMBER=10;  //Constant for the array size
    int values[NUMBER];        //Array of 10 inputs
    
    //Input values
    cout<<"Please enter 10 numbers"<<endl;
    for(int i=0;i<10;i++){
        cout<<" "<<endl;
        cin>>values[i];
    }
    
    //Process values -> Map inputs to Outputs
    min=values[0];
    max=values[0];
    for(int i=1;i<10;i++){
        if(min>values[i]){
            min=values[i];
        }else if(max<values[i]){
            max=values[i];
        }
    }
    
    //Display Output
    cout<<"The minimum number entered is:"<<min<<endl;
    cout<<"The maximum number entered is:"<<max<<endl;

    //Exit Program
    return 0;
}


