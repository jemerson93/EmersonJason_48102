/* 
 * File: main
 * Author: Jason Emerson
 * Created November 18th, 2016, 6:30PM
 * Purpose: Take numbers from a file and output the average
*/  

//System Libraries
#include <iostream>   //Input/Output objects
#include <fstream>    //File I/O
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    ifstream in;
    float avg=0;
    int SIZE=50;
    int array[SIZE]={0};
    
    //Open File
    in.open("num.dat");
    
    //Process Values
    for(int i=0;i<SIZE;i++){
        in>>array[i];
        avg+=array[i];
    }
    avg/=SIZE;
    
    //Display Outputs
    cout<<"This file contains the numbers from 1 to 50."<<endl;
    cout<<endl;
    cout<<"The average of this file is: "<<avg<<endl;
    
    //Exit Program
    return 0;
}