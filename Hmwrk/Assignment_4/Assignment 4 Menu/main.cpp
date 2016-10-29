/* 
 * File:   main.cpp
 * Author: Jason Emerson
 * Created on October 18, 2016, 11:00 PM
 * Purpose : Menu for Assignment 4
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
#include <cstdlib>    //Random number seed
#include <ctime>      //Seed the random number
#include <cmath>      //Log
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
float GRAVITY=6.673e-8f;     //Universal Gravity Constant cm^3/g/sec^2
float CNKGGRM=1000;         //Conversion from KG to Grams
float CNSGGRM=14593.9;     //Conversion from Slugs to Grams
float CNKMMET=1000;        //Conversion from KM to Meters
float CNMETCM=100;        //Conversion from Meters to Centimeters
float CNDYNLB=2.24809e-6f; //Conversion from Dynes to Pounds
float CNSGLBS=32.174f;     //Conversion from slugs to lbs which oddly acceleration of gravity in ft/sec^2

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Problem Gaddis_8thEd_Chap5_Prob1_SumofNumbers"<<endl;
        cout<<"2.  Type 2  for Problem Gaddis_8thEd_Chap5_Prob2_ASCIICode"<<endl;
        cout<<"3.  Type 3  for Problem Gaddis_8thEd_Chap5_Prob3_OceanLevels"<<endl;
        cout<<"4.  Type 4  for Problem Gaddis_8thEd_Chap5_Prob4_CaloriesBurned"<<endl;
        cout<<"5.  Type 5  for Problem Gaddis_8thEd_Chap5_Prob5_MembershipFee"<<endl;
        cout<<"6.  Type 6  for Problem Gaddis_8thEd_Chap5_Prob6_DistTraveled"<<endl;
        cout<<"7.  Type 7  for Problem Gaddis_8thEd_Chap5_Prob7_PennyPay"<<endl;
        cout<<"8.  Type 8  for Problem Gaddis_8thEd_Chap5_Prob9_HotelOccupancy"<<endl;
        cout<<"9.  Type 9  for Problem Gaddis_8thEd_Chap5_Prob20_GuessingGame"<<endl;
        cout<<"10. Type 10 for Problem Savitch_9thEd_Chap4_Prob7_WeighingIn"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:{
                cout<<"Inside Gaddis_8thEd_Chap5_Prob1_SumofNumbers"<<endl;
     //Declare all Variables Here
    short num, counter; //Enter variable for number inputted and the how many times the loop should repeat
    int sum;            //The end sum of all the numbers
    
    //Input or initialize values Here
    cout<<"Enter a positive number"<<endl; //Ask for a number
    cin>>num;
    
    while (num<0) //Check if positive number
    {
        cout<<"Enter a POSITIVE number"<<endl;
        cin>>num;
    }
    
    //Process/Calculations Here
    for (short counter; counter<=num; counter++) //Utilize for loop
    {
        sum+=counter;
    }
    //Output Located Here
    cout<<"The sum of all numbers within that number is"<<endl;
    cout<<sum<<endl;
                cout << endl;
                cout << endl;
                break;
            }
            case 2:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob2_ASCIICode"<<endl;
                //Declaration of Variables
    char letter;
    
    //Input values
    cout<<" I will display the characters for ASCII codes 0 through 127"<<endl;
    
    //Process values -> Map inputs to Outputs
    for (int count = 0; count <= 127; count++)
    {
        if (count%16==0)cout<<endl;
        
        cout<<letter<<" ";
        letter++;
    }
                cout << endl;
                break;
            }
            case 3:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob3_OceanLevels"<<endl;
                //Declare all Variables Here
    float rise=1.5e0f;
    float level;
    short years;
    
    //Process/Calculations Here
    for (years=0; years<=25; years++)
    {
        level+=rise;
        cout<<"The level of the sea after "<<years<<" years is "<<level<<endl;
    }
                cout << endl;
                break;
            }
            case 4:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob4_CaloriesBurned"<<endl;
                //Declaration of Variables
                //Declaration of Variables
    float calburn; //Calories burned total
    float calmin=3.9f; //You burn 3.9 calories per minute
    
    //Input values
    for (int i=10;i<=30;i+=5){
        calburn=i*calmin;
        cout<<"In "<<i<<" minutes, you burned "<<calburn<<" calories"<<endl;
    } 
                cout << endl;
                break;
            }
            case 5:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob5_MembershipFee"<<endl;
                //Declaration of Variables
                //Declare all Variables Here
    short numyers=6;    //Amount of years ahead
    float ppyear=2500;  //Dollars paid per year
    float prcrise=0.04; //Increase in price every year
    
    //Input or initialize values Here
    cout<<"Your initial price is "<<ppyear<<endl; //Display starting Price
    
    //Process/Calculations and Output
    for (short i=1; i<=numyers; i++) //Loop adding 4 percent to price per year
    {
        ppyear+=ppyear*prcrise;
        cout<<"The amount you pay for year "<<i<<" will be "<<ppyear<<endl; 
        
    }
                break;
            }
            case 6:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob6_DistTraveled"<<endl;
                //Declare all Variables Here
    float speed, distance;
    short time;
    short incrTime=1;
     
    //Input or initialize values Here
    cout<<"This program calculates distance based on speed and time."<<endl;
    cout<<"Enter the speed of the car in miles per hour."<<endl;
    cin>>speed;
    cout<<"Enter the amount of time it has traveled in hours."<<endl;
    cin>>time;
    
    while (speed<0){
        cout<<"Enter a positive speed"<<endl;
        cin>>speed;
    }
    while (time<1){
        cout<<"Enter a time longer than 1 hour"<<endl;
        cin>>time;
    }
    //Process/Calculations Here
    cout<<"Hour  Distance Traveled"<<endl;
    cout<<"----------------------------"<<endl;
    
    for (short i=1; i<=time; i++){
        distance=speed*incrTime;
        cout<<incrTime<<"             "<<distance<<" miles"<<endl;
        incrTime++;
    }
                break;
            }
            case 7:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob7_PennyPay"<<endl;
                //Declaration of Variables
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
                break;
            }
            case 8:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob9_HotelOccupancy"<<endl;
                //Declaration of Variables
    unsigned short numFlrs; //Number of floors
    unsigned short numRoom; //Number of rooms on each floor
    unsigned short numOpd; //Number of occupied rooms
    unsigned short totRoom=0; //Total number of rooms
    unsigned short totOpd=0; //Total number of occupied rooms
    float roomOcc; //Number of rooms occupied
    
    //Input Rooms
    cout<<"How many floors are in the hotel?";
    cin>>numFlrs;
    
    while (numFlrs < 1)
    {
        cout<<"Number of floors must be 1 or above. Please enter again";
        cin>>numFlrs;
    }
    
    //Process values -> Map inputs to Outputs
    for (int i = 1; i <=numFlrs; i++) {
        if (i==13){
            i++;
        }
        cout<<"Floor "<<i<<endl;
        cout<<"Please enter the number of rooms:"<<endl;
        cin>>numRoom;
        
        cout<<"Please enter the number of rooms occupied:"<<endl;
        cin>>numOpd;
        
        while (numOpd<10){
            cout<<"The number of rooms must be 10 or above. Please enter again";
            cin>>numOpd;
        }
        
        totRoom+=numRoom;
        totOpd+=numOpd;
    }
    
    roomOcc=static_cast<float>(totOpd)/totRoom*100;
    
    //Display Output
    cout<<"Total number of floors          : "<<numFlrs<<endl;
    cout<<"Total number of rooms           : "<<totRoom<<endl;
    cout<<"Total number of occupied rooms  : "<<totOpd<<endl;
    cout<<"The percentage of rooms occupied: "<<roomOcc<<"%"<<endl;
                break;
            }
            case 9:{
                cout<<"Inside Problem Gaddis_8thEd_Chap5_Prob20_GuessingGame"<<endl;
                //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    int range,nGuess;
    int number,answer;
    
    //Input values
    cout<<"This is the guessing game"<<endl;
    cout<<"Choose a range for the number to guess"<<endl;
    cin>>range;
    
    //Process values -> Map inputs to Outputs
    nGuess=log(range)/log(2)+1;
    cout<<"You have "<<nGuess<<" guesses to find the random number"<<endl;
    number=rand()%(range+1); //[0,range]
    
    //Display Results of each Guess
    for(int guess=1;guess<=nGuess;guess++){
       cout<<"Input your guess"<<endl;
       cin>>answer;
       if(answer>number)cout<<"Guess to High"<<endl;
       else if(answer<number)cout<<"Guess to Low"<<endl;
       else{
           cout<<"You guessed the number"<<endl;
           exit(0);
       }
    }
    cout<<"Sorry too many guesses"<<endl;
                break;
            }
            case 10:{
                cout<<"Inside Problem Savitch_9thEd_Chap4_Prob7_WeighingIn"<<endl;
                 //Declaration of Variables
    float msEarth=5.972e24; //Google lookup -> Kilograms
    float msMark=6;        //Mass of Mark -> Slug
    float rdEarth=6371.0f; //Google radius of the earth
    float weight;          //Force of attraction from Physics
    
    //Conversion of Inputs
    msEarth*=CNKGGRM;      //Convert mass of the earth to grams
    msMark*=CNSGGRM;       //Convert mass of mark to grams
    rdEarth*=CNKMMET*CNMETCM; //Convert the radius of the earth to centimeters
    
    //Process values -> Map inputs to Outputs
    weight=GRAVITY*msMark*msEarth/rdEarth/rdEarth; //Weak force attraction due to Gravity
    weight*=CNDYNLB;        //Convert dynes to pounds
    
    //Display Output
    cout<<"According to the Weak Force of Gravity Mark weighs = "<<weight<<" lbs"<<endl;
    cout<<"As a check Mark weights = "<<6*CNSGLBS<<" lbs"<<endl;
    cout<<"The percentage error in the Radius of Earth = +-"<<100.0f*18/6371<<"%"<<endl;
    cout<<"The margin of error for the weight = "<<(weight-6*CNSGLBS)/weight*100.0f<<"%"<<endl;
                break;
            }//End Case
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}
