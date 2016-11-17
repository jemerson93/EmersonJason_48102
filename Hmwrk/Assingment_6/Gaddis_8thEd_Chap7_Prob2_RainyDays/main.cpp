/* 
   File:   main
   Author: Jason Emerson
   Created on November 10th, 2016, 12:00 PM
   Purpose: Calculate rainy days
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random
#include <ctime>     //Time
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
//Like PI, e, Gravity, or conversions
const int NUMDAYS=30;

//Function prototypes
void fillAry(char [][NUMDAYS],int);
void prntAry(char [][NUMDAYS],int);
void prntAry(int [][NMONTHS]);
void calcAry(char [][NUMDAYS],int [][NMONTHS]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    const int NMONTHS=3;
    char weather[NMONTHS][NUMDAYS];
    int stat[NMONTHS][NMONTHS]=();
    
    //Input values
    fillAry(weather,NMONTHS);
    
    //Display Output
    prntAry(weather,NMONTHS);
    
    //Process values -> Map inputs to Outputs
    
    //Display Output

    //Exit Program
    return 0;
}

void calcAry(char weather[][NUMDAYS],int stat[][NMONTHS]){
    for(int months=0;months<NMONTHS;months++){
        for(int days=0;days<NUMDAYS;days++){
        }
    }
}

void fillAry(char weather[NUMDAYS],int nMonths){
    //Declare an array of values
    char type[]={'R','C','S'};
    //Fill the array
    for(int days=0;days<NUMDAYS;days++){
        for(int months=0;months<=nMonths;months++){
            weather[months][days]=type[rand()%3];
        }
    }
}

void prntAry(int [][NMONTHS]);{
//Print the data set
    for(int months=0;months<NMONTHS;months++){
        for(int data=0;data<NMONTHS;data++){
            cout<<stat[months][data]<<" "<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(char weather[][NUMDAYS],int nMonths){
    //Print the data set
    for(int months=0;months<nMonths;months++){
        for(int days=0;days<NUMDAYS;days++){
            cout<<weather[months][days]<<" "<<endl;
        }
        cout<<endl;
    }
}