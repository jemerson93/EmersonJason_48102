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
bool linSearch(int [],int ,int);

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
    const int SIZE=20; //Size of Linear Search array
    int rNum=0; //Random Number Generated
    int guess=0; //Players guess
    int max=10;   //Max Number for the Random Number Generator
    int guesses=0; //Number of GUesses Used
    int points=0;   //Players Score
   bool nxtLvl=true;   //If true, enter next level. If false, do not
    int maxG=7;  //Max number of guesses allowed
    int lvlInc=5; //Amount to increase the random number range by
    char board[4][COLS]; //Character hangman board - initial board
    int arr[SIZE]; //Linear Search Array
    int chance; //Chance for extra life
    bool exChance;
    
    //Beginning of Level
    while(nxtLvl){
        nxtLvl=false; //Set to false so loop doesn't activate if player loses
        guesses=0;    //Start guesses over for new level
        rNum=rand()%max+1; //Generate a random number between 1 and the max available
        setBoard(board);  //Initiate the hangman board as a 4x3 of '-'
        exChance=true; //Set extra chance to true
        
    //Players Guess
        cout<<"Your number range for this level is between 1 and "<<max<<". Please enter your guess now."<<endl;
        
    //Incorrect Guess
        do{
            cin>>guess;  //Players input guess
            while(guess<1){
                cout<<"Please enter a guess."<<endl;
                cin>>guess; //Players second input guess
            }
            guesses++;   //Increment guesses
            
            //High Guess
            if(guess>rNum){
                cout<<"Guess is too high. Please try again."<<endl;
            
            //Low Guess
            }else if(guess<rNum){
                cout<<"Guess is too low. Please try again."<<endl;
            }
            drawBoard(board,guesses); //Draw the hangman body part pending on the number of guesses user has
            prntBoard(board);         //Display the Hangman board and update after each guess
            
            //Correct Guess
            if(guess==rNum){
                cout<<"Correct! Increasing level."<<endl;
                max+=lvlInc; //Increase the max for the range by the intialization of lvlInc
                nxtLvl=true; //Set next level to true to initiate the loop
                points+=1;  //Add 1 point to the players score
            }
            
            //Players Extra Chance
            if(maxG-guesses==0&&exChance==true){
                exChance=false;
                cout<<"You have lost. You have a chance to get 1 more life to try to continue the game. Please input a number.";
                cout<<" If it is in the list of numbers, you will gain 1 life. If it is not, you will lose the game."<<endl;
                cin>>chance;
                
                //Randomize Array
                for(int i=0;i<SIZE;i++){
                    arr[i]=rand()%50+1;
                }
                
                if(linSearch(arr,SIZE,chance)){
                    guesses--;
                    cout<<"Congratulations! You have received another chance to guess the number."<<endl;
                    cout<<"Please enter your guess now."<<endl;
                }
                else{
                    cout<<"Sorry, you lose! Better luck next time."<<endl;
                    nxtLvl=false; //Set to false to break the loop
                    highScore(points); //Run highScore function and send points to function
                }
            }else if(exChance==false&&maxG-guesses==0){
                cout<<"Sorry, you lose! Better luck next time."<<endl;
                nxtLvl=false; //Set to false to break the loop
                highScore(points); //Run highScore function and send points to function
            }
        }while(guess!=rNum&&guesses<maxG);
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

/************************************************
 *                 readHighScore                *
 ************************************************
 *  Function: Display the high score            *
 *  Input: highscore.dat                        *
 *  Output: Void                                *
 *************************************************/

void readHighScore(int hScore){
    //Declaration of Variables
    const int SIZE=6; //Size =of array
    string names[SIZE]; //Name array
    vector<int> score(SIZE); //Score Vector
    int n;
    int m;
    
    string fnNames="names.dat"; //Names
    string fnScores="scores.dat"; //Scores
    
    fillAry(fnNames,names,n); //Fill the names array from the file
    fillAry(fnScores,score,m); //Fill the scores array from the file

    //Bubble Sort
    bool swap=false;
    int len=n-1;
    do{
        swap=false;
        for(int i=0;i<len;i++){
            if(score[i]<score[i+1]){
                string nameTemp=names[i];
                names[i]=names[i+1];
                names[i+1]=nameTemp;
                int scoreTemp=score[i];
                score[i]=score[i+1];
                score[i+1]=scoreTemp;
                swap=true;
            }
        }
        len--; //Post decremeent
    }
    while(swap);
    
    //Display the High Scores
    cout<<"*******************************************************"<<endl;
    cout<<"                      High Scores:"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<endl;
    
    //Output the scores from both arrays sorted
    prntAry(names,score,n);
}

//Names
void fillAry(string fn,string a[],int &n){
    //Declaration of Variables
    ifstream in;
    n=0;
    
    //Open the stream
    in.open(fn);
    
    //Read in data
    string temp;
    while(in>>temp){
        a[n++]=temp;
    }
    
    //Close the file
    in.close(); //Close the file
    in.clear(); //Clear the file
}

//Scores
void fillAry(string fn,vector<int> &a,int &n){
    //Declaration of Variables
    ifstream in;
    n=0;
    
    //Open the file
    in.open(fn);
    
    //Read in the data
    while(in>>a[n++]);
    n--;
    
    //Close the file
    in.close(); //Close the file
    in.clear(); //Clear the file
}

void prntAry(string fn[],vector<int> &a,int n){
    //Declaration of Variables
    int count=0; //counter
    
    //Output and Display the Array
    for(int i=0;i<n;i++){
        cout<<setw(25)<<fn[i]<<" "<<setw(4)<<a[i]<<endl;
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
    ofstream out; //Output File
    short hScore; //High Score
    int n;
    int m;
    string name; //Input name
    const int SIZE=100;  //Size of the arrays
    string names[SIZE]; //Name Array
    vector<int> score(SIZE); //Score Vector
    string fnNames="names.dat";
    string fnScores="scores.dat";
    
    //Fill arrays
    fillAry(fnNames,names,n); //Fill names array
    fillAry(fnScores,score,m); //Fill scores array
    
    //Bubble Sort
    bool swap=false;
    int len=n-1;
    do{
        swap=false;
        for(int i=0;i<len;i++){
            if(score[i]<score[i+1]){
                string nameTemp=names[i];
                names[i]=names[i+1];
                names[i+1]=nameTemp;
                int scoreTemp=score[i];
                score[i]=score[i+1];
                score[i+1]=scoreTemp;
                swap=true;
            }
        }
        len--; //Post decremeent
    }
    while(swap);
    
    //If New High Score
    if(points>score[4]){
        cout<<"Congratulations! You reached a new high score. Please enter your name below."<<endl;
        cin>>name;
        names[4]=name;
        score[4]=points;
        
        //Out new name replacing lowest score name
        out.open("names.dat");
        for(int i=0;i<5;i++){
            out<<names[i]<<endl;
        }
        out.close(); //Close the file
        out.clear(); //Clear the file
        
        //Output new score replacing lowest score 
        out.open("scores.dat");
        for(int j=0;j<5;j++){
            out<<score[j]<<endl;
        }
        out.close(); //Close the file
        out.clear(); //Clear the file
        
        cout<<"Saved to file!"<<endl; //Error check to make sure it saves to file
        cout<<endl;
    }
        
    //If Not a new High Score
    if(points<score[4]){
        //Display High Score
        cout<<"Sorry, not a new high score."<<endl;
        cout<<endl;
    }
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   linSearch   ****************************************
//Purpose:  Use a linear search to give a chance at an extra life
//Inputs:   range : Array of 20 random numbers between 1-100
//          n     : Size of the array
//          key   : Chance in the game function
//Output:   Returns true or false depending if the number was found
//******************************************************************************
bool linSearch(int range[],int n,int key){
    //Process Values
    for(int i=0;i<n;i++){
        if(key==range[i]){
            return true;
        }
    }
    return false;
}