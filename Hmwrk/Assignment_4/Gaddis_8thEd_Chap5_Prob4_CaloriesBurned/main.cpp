/* 
   File:   main
   Author: Jason Emerson
   Created on September 13th, 2016, 10:00 AM
   Purpose: Number of calories burned after 5,10,15,20,25, and 30 minutes
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
    float calburn; //Calories burned total
    float calmin=3.9f; //You burn 3.9 calories per minute
    
    //Input values
    for (int i=10;i<=30;i+=5){
        calburn=i*calmin;
        
       
    //Process values -> Map inputs to Outputs
    
    //Display Output
        cout<<"In "<<i<<" minutes, you burned "<<calburn<<" calories"<<endl;
    }

    //Exit Program
    return 0;
}