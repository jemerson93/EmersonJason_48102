/* 
   File:   main
   Author: Jason Emerson
   Created on October 6th, 2016, 12:25 PM
   Purpose: Play Rock Paper Scissors
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>   //Random number generator
#include <ctime>     //Name-space used in the System Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    char computr; //Computers choice
    char rPlay;  //Our rock/paper/scissors
    
    //Input Computer Values
    computr=rand()%4+80;
    while(computr=='Q'){
        computr=rand()%4+80;
    }
    
    //Input Our Rock, Paper, Scissors
    cout<<"Input your choice R-Rock, P-Paper, S-Scissors"<<endl;
    cin>>rPlay;
    switch(rPlay){
        case 'r':
        case 'R':rPlay='R';break;
        case 's':
        case 'S':rPlay='S';break;
        default:rPlay='P';break;
    }
    
    //Display Output
        cout<<"The computer generates a "<<computr<<endl;
        
   //Determine the winner and display
   if(computr==rPlay){
       cout<<"You both tied each other"<<endl;
   }else if(computr=='P'){
       if(rPlay=='S') cout<<"The player wins"<<endl;
       else cout<<"The computer wins"<<endl;
   }else if(computr=='S'){
       if(rPlay=='R')cout<<"The player wins"<<endl;
       else cout<<"The computer wins"<<endl;
   }else{
       if(rPlay=='P')cout<<"The player wins"<<endl;
       else cout<<"The computer wins"<<endl;
   }

    //Exit Program
    return 0;
}