/* 
   File:   main
   Author: Jason Emerson
   Created on October 18th, 2016, 7:09 PM
   Purpose: Calculate a persons pay in penny's throughout a number of days
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
    float day = 1; //Number of days
    float money = 1.0; //A penny
    float total=0.0; //Total paid
    float paypDay; //Pay per day
    
    //Input values
    cout<<"Please enter the number of days you have worked: "; //User inputs number of days worked
    cin>>day;
    
//Process values -> Map inputs to Outputs
      while (day < 1)
    {
        cout<<"Please enter a valid number of days greater then at least 1 or higher"<<endl; //If user inputs a 0, fail and request a new number
        cin>>day;
    }
    
    for (int i=1;i<=day;i++)
    {
        paypDay = money/100;
        cout<<"Day "<<i<<" you earned $"<<money/100<<endl;
        total+= paypDay;
        money+=2;
    }
    cout<<"The total earnings are $"<<total<<endl;
   
    
    
    
    //Display Output

    //Exit Program
    return 0;
}