/* 
  File:   main
  Author: Jason Emerson
  Created on August 30, 2016, 11:50 AM
  Purpose: First Program Hello World
 */

//System Libraries
#include <iostream> //Standard Input Output Library
using namespace std; //Most system libraries under the standard name-space

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    short a,b,c; //Integers with range [-32789,32767] or [-2^15,2^15-]
    
    //Initialize or input values
    a=2;
    b=3;
    
    //Process the input by mapping to the output
    c=a+b;
    
    //Display information
    cout<<"Hello World -> First Program"<<endl;
    cout<<a<<" + "<<b<<" = "<<c<<endl;
    
    
    //Return from the function

    return 1;
}

