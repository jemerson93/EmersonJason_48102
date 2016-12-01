/* 
   File:   main
   Author: Jason Emerson
   Created on November 30th, 2016, 4:30 PM
   Purpose: Version 2 of Numerical Hangman
 */

//System Libraries
#include <iostream>  //Input/Output Objects
#include <cstdlib>   //Random Number
#include <ctime>    //Random Number Seed
#include <fstream>  //File I/O
#include <string>   //Strings
#include <iomanip>  //Formatting
using namespace std; //Name-space used in the System Library 

//User Libraries

//Global Constants

//Function Prototypes
int showMenu();
void printInstructions();
void playGame();
void drawBoard(int guesses);
void readHighScore();
void highScore(int score);

//Execution Begins Here!
int main(int argc, char** argv){
    //Welcome
    cout<<"****************************************************************"<<endl;
    cout<<"             Welcome to Numerical Hangman!"<<endl;
    cout<<"           Created by Jason Emerson for CSC5"<<endl;
    cout<<"****************************************************************"<<endl;
    
    //Declaration of Variables
    short mChoice=0;
    
    //Display the Main Menu and Get User's Choice
    do{
        switch(showMenu()){
            case 1:
                mChoice=1;
                playGame();
                break;
            case 2:
                mChoice=2;
                printInstructions();
                break;
            case 3:
                mChoice=3;
                readHighScore();
                break;
            default:
                mChoice=4;
                break;
        }
    }while(mChoice>0&&mChoice<4);
    
    //Exit Program
    return 0;
}

/************************************************
 *                   showMenu                   *
 ************************************************
 *  Function: Show the main menu                *
 *  Input: Choice                               *
 *  Output: Choice to main                      *
 *************************************************/

int showMenu(){
    //Declaration of Variables
    int choice=0; //Player's main menu choice
    
    //Input Choice and Return To Main
    do{
        cout<<"Press 1 to begin the game"<<endl;
        cout<<"Press 2 for instructions"<<endl;
        cout<<"Press 3 to display the high score"<<endl;
        cout<<"Press 4 to exit the game"<<endl;
        cin>>choice;
        if(choice<1||choice>4){ //Error checking
            cout<<"Invalid entry. Please enter a number between 1 - 4"<<endl;
        }
    }while(choice<1||choice>4);
    
    //Exit Function and Return Choice
    return choice;
}

/************************************************
 *               printInstructions              *
 ************************************************
 *  Function: Show the instructions             *
 *  Input: None                                 *
 *  Output: Void                                *
 *************************************************/

void printInstructions(){
    //Declaration of Variables
    char goBack; //Return to Main Menu
    string levels="• There are a total of 10 levels in this game.";
    string lives="• In each level, you have a total amount of 6 lives."<<endl;
    string endGame="• If you complete all 10 levels, you win the game. If you use up all of your guesses, you lose the game."<<endl;
    
    //Instructions
    cout<<"*******************************************************"<<endl;
    cout<<"                      Instructions"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<endl;
    cout<<"This version of Hangman is quite different from the Hangman we all know and love. Instead of guessing letters or words, your objective is to guess the number the game has generated."<<endl;
    cout<<"If you guess the correct number, the game level will increase. If you do not guess the correct number within' the amount of applicable guesses, you will lose the game."<<endl;
    cout<<"Below are some quick facts on the game. Good luck and remember to have fun!"<<endl;
    cout<<endl;
    cout<<setw(50)<<"Quick Facts:"<<endl;
    cout<<setw(10)<<" "<<levels<<endl;
    cout<<setw(10)<<" "<<lives<<endl;
    cout<<setw(10)<<" "<<endGame<<endl;  
    cout<<endl;
    cout<<"Press any key and enter to return to the Main Menu."<<endl;
    cin>>goBack;
    
    //Exit Function
    return void;
}

/************************************************
 *                 playGame                     *
 ************************************************
 *  Function: Game Function                     *
 *  Input: Guess                                *
 *  Output: Void                                *
 *************************************************/

void playGame(){
    //Set the Random Number Seed
    srand(static_cast<unsigned short>(time(0)));
    
    //Declaration of Variables
    short rNum=0; //Random Number Generated
    short guess=0; //Players guess
    short max=0;   //Max Number for the Random Number Generator
    short guesses; //Number of GUesses Used
    short score=0;   //Players Score
    bool nxtLvl=true;   //If true, enter next level. If false, do not
    short maxG=6;  //Max number of guesses allowed
    short lvlInc=5; //Amount to increase the random number range by
    
    //Beginning of Level
    while(nxtLvl){
        nxtLvl=false; //Set to false so loop doesn't activate if player loses
        guesses=1;    //Start guesses over for new level
        rNum=rand()%max+1; //Generate a random number between 1 and the max available
        
    //Players Guess
        cout<<"Your number range for this level is between 1 and "<<max<<". Please enter your guess now."<<endl;
        cin>>guess;
        
    //Incorrect Guess
        while(guess!=rNum&&guesses<maxG){
            guesses++; //Increment guesses
            if(guess>rNum){
                cout<<"Guess is too high. Please try again."<<endl;
            }else if(guess<rNum){
                cout<<"Guess is too low. Please try again."<<endl;
            }
            drawBoard(guesses);
            cin>>guess;
        }
        
    //Correct Guess
        if(guess==rNum){
            cout<<"Correct! Increasing level."<<endl;
            max+=lvlInc; //Increase the range by the constant
            nxtLvl=true; //Set to true so activates loop for next level
            score+=maxG-guesses; //Add the number of guesses left to score
            
    //Game Loss
        }else{
            cout<<"Sorry, you lose! Better luck next time."<<endl;
            nxtLvl=false; //Set to false to not use nxtLvl loop
            highScore(score);
        }
    }  
    
    //Exit Function
    return void;
}