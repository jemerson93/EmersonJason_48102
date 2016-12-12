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
#include <vector>   //Vector
using namespace std; //Name-space used in the System Library 

//User Libraries

//Global Constants
const int COLS = 100;

//Function Prototypes
int showMenu();
void printInstructions();
void playGame();
void drawBoard(int);
void readHighScore(int);
void highScore(int);
void setBoard(char [][COLS]);
void drawBoard(char [][COLS],int &);
void prntBoard(char [][COLS]);
void fillAry(string,string [],int &);
void fillAry(string,vector<int> &,int &);
void prntAry(string [],vector<int> &,int n);

//Execution Begins Here!
int main(int argc, char** argv){
    //Welcome
    cout<<"****************************************************************"<<endl;
    cout<<"             Welcome to Numerical Hangman!"<<endl;
    cout<<"           Created by Jason Emerson for CSC5"<<endl;
    cout<<"****************************************************************"<<endl;
    
    //Declaration of Variables
    short mChoice=0;
    int hScore;
    //char hangman[3][3];
    
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
                readHighScore(hScore);
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
        if(choice<1 || choice>4){ //Error checking
            cout<<"Invalid entry. Please enter a number between 1 - 4"<<endl;
        }
    }while(choice<1 || choice>4);
    
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
    cout<<setw(10)<<"• There are a total of 10 levels in this game."<<endl;
    cout<<setw(10)<<"• In each level, you have a total amount of 6 lives."<<endl;
    cout<<setw(10)<<"• If you complete all 10 levels, you win the game. If you use up all of your guesses, you lose the game."<<endl;  
    cout<<endl;
    cout<<"Press any key and enter to return to the Main Menu."<<endl;
    cin>>goBack;
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
    int rNum=0; //Random Number Generated
    int guess=0; //Players guess
    int max=10;   //Max Number for the Random Number Generator
    int guesses=0; //Number of GUesses Used
    int points=0;   //Players Score
   bool nxtLvl=true;   //If true, enter next level. If false, do not
    int maxG=7;  //Max number of guesses allowed
    int lvlInc=5; //Amount to increase the random number range by
    char board[4][COLS];
    
    //Beginning of Level
    while(nxtLvl){
        nxtLvl=false; //Set to false so loop doesn't activate if player loses
        guesses=0;    //Start guesses over for new level
        rNum=rand()%max+1; //Generate a random number between 1 and the max available
        setBoard(board);
        
    //Players Guess
        cout<<"Your number range for this level is between 1 and "<<max<<". Please enter your guess now."<<endl;
        
    //Incorrect Guess
        do{
            cin>>guess;
            while(guess<0){
                cout<<"Please enter a number greater than 0."<<endl;
            }
            guesses++;
            if(guess>rNum){
                cout<<"Guess is too high. Please try again."<<endl;
            }else if(guess<rNum){
                cout<<"Guess is too low. Please try again."<<endl;
            }else if(guess==rNum){
                cout<<"Correct! Increasing level."<<endl;
                max+=lvlInc;
                nxtLvl=true;
                points+=1;
            }
            drawBoard(board,guesses);
            prntBoard(board);
        }while(guess!=rNum&&guesses<maxG);
       
    //Game Loss
        if(maxG-guesses==0){
            //drawBoard(board,guesses);
            cout<<"Sorry, you lose! Better luck next time."<<endl;
            nxtLvl=false; //Set to false to break loop
            highScore(points);
        }
    }
}

void setBoard(char board[][COLS]){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            board[i][j]='-';
        }
    }
}
/************************************************
 *                 drawBoard                    *
 ************************************************
 *  Function: Draw the Hangman board            *
 *  Input: None                                 *
 *  Output: Void                                *
 *************************************************/

void drawBoard(char board[][COLS],int &guesses){
    //Declaration of Variables
    int maxG=7; //The max number of guesses to dignify guesses remaining
    
    //Guesses and Guesses Remaining
    cout<<"Guesses:"<<guesses<<endl;
    cout<<"Guesses Remaining:"<<maxG-guesses<<endl;
    
    //guesses++; //Increment guesses when wrong
    
    //Hangman Board Per Guess
    switch(guesses){
        case 7:
            board[3][2]='\\';
            break;
        case 6:
            board[3][0]='/';
            break;
        case 5:
            board[2][1]='^';
            break;
        case 4:
            board[1][2]='/';
            break;
        case 3:
            board[1][0]='\\';
            break;
        case 2:
            board[1][1]='|';
            break;
        case 1:
            board[0][1]='O';
            break;
    }
    cout<<endl;
}

void prntBoard(char board[][COLS]){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j];
            if(j==2){
                cout<<endl;
            }
        }
    }
    
}

//void fillArray()

/************************************************
 *                 readHighScore                *
 ************************************************
 *  Function: Display the high score            *
 *  Input: highscore.dat                        *
 *  Output: Void                                *
 *************************************************/

void readHighScore(int hScore){
    //Declaration of Variables
    const int SIZE=6; //Size = 100
    string names[SIZE]; //Name array
    vector<int> score(SIZE); //Score Vector
    int n;
    int m;
    
    string fnNames="names.dat";
    string fnScores="scores.dat";
    
    fillAry(fnNames,names,n);
    fillAry(fnScores,score,m);

    bool swap = false;
    int len = n - 1;
    do{
        swap = false;
        for ( int i = 0; i < len; i++ ) {
            if ( score[i] < score[i+1] ) {
                string nametemp = names[i];
                names[i] = names[i+1];
                names[i+1] = nametemp;
                int scoretemp = score[i];
                score[i] = score[i+1];
                score[i+1] = scoretemp;
                swap = true;
            }
        }
        len--;
    }
    while( swap );
     //Output Located Here
    prntAry(names,score,n);
}

void fillAry(string fn,string a[],int &n){
    //Declare variables+ and open the file
    ifstream in;
    n=0;
    
    //Open the stream
    in.open(fn);
    
    //Read in data
    string temp;
    while( in>>temp ){
        a[n++] = temp;
    }
//    n--;
    
    //Close the file
    in.close();
}

void fillAry(string fn,vector<int> &a,int &n){
    //Declare variables and open the file
    ifstream in;
    n=0;
    
    //Open the stream
    in.open(fn);
    
    //Read in data
    while(in>>a[n++]);
    n--;
    
    //Close the file
    in.close();
}

void prntAry(string fn[],vector<int> &a,int n){
    //Output Located Here
    int count=0;
    for(int i=0;i<n;i++){
        cout<<fn[i]<<" "<<a[i]<<endl;
        if((count++)%10==9)cout<<endl;
    }
    cout<<endl;
}


/************************************************
 *                 highScore                    *
 ************************************************
 *  Function: Save and write high score to file *
 *  Input: highscore.dat                        *
 *  Output: highscore.dat                       *
 *************************************************/

void highScore(int points){
    //Declaration of Variables
    const int SIZE=100; //Size = 100
    string names[SIZE]; //Name array
    vector<int> score(SIZE); //Score Vector
    int n;
    int m;
    string name;
    string fnNames="names.dat";
    string fnScores="scores.dat";
    ofstream out;
    short hScore;
    
    fillAry(fnNames,names,n);
    fillAry(fnScores,score,m);
    
    //Bubble Sort
    bool swap = false;
    int len = n - 1;
    do{
        swap = false;
        for ( int i = 0; i < len; i++ ) {
            if ( score[i] < score[i+1] ) {
                string nametemp = names[i];
                names[i] = names[i+1];
                names[i+1] = nametemp;
                int scoretemp = score[i];
                score[i] = score[i+1];
                score[i+1] = scoretemp;
                swap = true;
            }
        }
        len--;
    }
    while( swap );
    
    //If New High Score
    if(points>score[4]){
        cout<<"Congratulations! You reached a new high score. Please enter your name below."<<endl;
        cin>>name;
        names[4]=name;
        score[4]=points;
        out.open("names.dat");
        for(int i=0;i<5;i++){
            out<<names[i]<<endl;
        }
        out.close();
        out.clear();
        out.open("scores.dat");
        for(int j=0;j<5;j++){
            out<<score[j]<<endl;;
        }
        out.close();
        out.clear();
        
        cout<<"Saved to file!"<<endl;
    }
        
        //If Not High Score
    if(points<hScore){
        
     
    //Display High Score
        cout<<"Sorry, not a new high score."<<endl;
        cout<<endl;
    }
}