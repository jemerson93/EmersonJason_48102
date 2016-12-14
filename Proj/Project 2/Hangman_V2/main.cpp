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
#include <cmath>    //Math
using namespace std; //Name-space used in the System Library 

//User Libraries

//Global Constants
const int COLS = 100;

//Function Prototypes
int showMenu();
void printInstructions();
void playGame();
void drawBoard(int);
void readHighScore(float);
void highScore(float);
void setBoard(char [][COLS]);
void drawBoard(char [][COLS],int &);
void prntBoard(char [][COLS]);
void fillAry(string,string [],int&);
void fillAry(string,vector<float> &,int&);
void prntAry(string [],vector<float> &,int);
bool linSearch(int [],int,int);
void bubbSort(string [],vector<float> &,int=5);

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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   showMenu  ****************************************
//Purpose:  Show menu functionality for switch(showMenu) in main
//Inputs:   No input parameters - in game choice input between 1 - 4
//Output:   Output choice back to main
//******************************************************************************
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   printInstructions  *******************************
//Purpose:  Print the instructions of the game
//Inputs:   No input parameters - goBack input in game
//Output:   Void Output (no return) - Displays the cout'd instructions
//******************************************************************************
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
    cout<<setw(10)<<"• There is an unlimited amount of levels in this game."<<endl;
    cout<<setw(10)<<"• In each level, you have a total amount of 7 lives."<<endl;
    cout<<setw(10)<<"• When you complete each level, you gain 1 point."<<endl;
    cout<<setw(10)<<"• Once you have used all 7 lives, you will have a chance to gain an additional life. If you fail, you lose."<<endl;
    cout<<endl;
    cout<<"Press any key and enter to return to the Main Menu."<<endl;
    cin>>goBack;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   playGame  ****************************************
//Purpose:  Main game function for Hangman
//Inputs:   No input parameters - guess, chance - in game inputs
//Output:   Void Output (no return) - output points to highScore function
//******************************************************************************
void playGame(){
    //Set the Random Number Seed
    srand(static_cast<unsigned short>(time(0)));
    
    //Declaration of Variables
    const int SIZE=20; //Size of Linear Search array
    int rNum=0; //Random Number Generated
    int guess=0; //Players guess
    int max=10;   //Max Number for the Random Number Generator
    int guesses=0; //Number of GUesses Used
    float points=0.0;   //Players Score
    bool nxtLvl=true;   //If true, enter next level. If false, do not
    int maxG=7;  //Max number of guesses allowed
    int lvlInc=5; //Amount to increase the random number range by
    char board[4][COLS]; //Character hangman board - initial board
    int arr[SIZE]; //Linear Search Array
    int chance; //Chance for extra life
    bool exChance; //Flag for extra chance in each level
    
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
            
            //High Guess
            if(guess>rNum){
                cout<<"Guess is too high. Please try again."<<endl;
                guesses++;   //Increment guesses
                drawBoard(board,guesses); //Draw the hangman body part pending on the number of guesses user has
                prntBoard(board);         //Display the Hangman board and update after each guess
            
            //Low Guess
            }else if(guess<rNum){
                cout<<"Guess is too low. Please try again."<<endl;
                guesses++;   //Increment guesses
                drawBoard(board,guesses); //Draw the hangman body part pending on the number of guesses user has
                prntBoard(board);         //Display the Hangman board and update after each guess
            }

            //Correct Guess
            if(guess==rNum){
                cout<<"Correct! Increasing level."<<endl;
                max+=lvlInc; //Increase the max for the range by the initialization of lvlInc
                nxtLvl=true; //Set next level to true to initiate the loop
                points+=pow(2,2);  //Square the current points squared and add to the current points
            }
       
            //Players Extra Chance
            if(maxG-guesses==0&&exChance==true){
                exChance=false;
                cout<<"You have lost. You have a chance to get 1 more life to try to continue the game."<<endl;
                cout<<"Please input a number between 1 and 50. If it is in the list of numbers, you will have 1 more guess."<<endl;
                cout<<"If it is not, you will lose the game."<<endl;
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
                    cout<<"Sorry,the number you have entered was not in the array of numbers. You lose! Better luck next time."<<endl;
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   setBoard  ****************************************
//Purpose:  Set the initial char board array of ----
//Inputs:   board : char array of 4x3 ' - '
//Output:   Void Output (no return) - Displays initial hangman board
//******************************************************************************
void setBoard(char board[][COLS]){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            board[i][j]='-';
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   drawBoard  ***************************************
//Purpose:  Draw over the initial board pending how many guesses player has
//Inputs:   board   : char array with 4 rows and 3 columns
//          guesses : number of guesses coming from playGame referenced
//Output:   Void Output - no return - draw the body parts on the board array
//******************************************************************************
void drawBoard(char board[][COLS],int &guesses){
    //Declaration of Variables
    int maxG=7; //The max number of guesses to dignify guesses remaining
    
    //Guesses and Guesses Remaining
    cout<<"Guesses:"<<guesses<<endl;
    cout<<"Guesses Remaining:"<<maxG-guesses<<endl;
    
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   prntBoard      ***********************************
//Purpose:  Display both arrays as a Hangman Board
//Inputs:   board : Array set to 4 rows and 3 cols
//Output:   Print the two dimensional array in the function that calls it
//******************************************************************************
void prntBoard(char board[][COLS]){
    for(int i=0;i<4;i++){ //Rows
        for(int j=0;j<3;j++){ //Columns
            cout<<board[i][j];
            if(j==2){
                cout<<endl;
            }
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   readHighScore    *********************************
//Purpose:  Display the current high scores in the 2 files
//Inputs:   hScore : The current list of the top 5 high scores for my game
//Output:   Void Output (no return) - Display the high scores from high to low
//******************************************************************************
void readHighScore(float hScore){
    //Declaration of Variables
    const int SIZE=6; //Size =of array
    string names[SIZE]; //Name array
    vector<float> score(SIZE); //Score Vector
    int n; //Size names
    int m; //Size scores
    
    string fnNames="names.dat"; //Names
    string fnScores="scores.dat"; //Scores
    
    fillAry(fnNames,names,n); //Fill the names array from the file
    fillAry(fnScores,score,m); //Fill the scores array from the file

    //Bubble Sort
    bubbSort(names,score,n);
    
    //Display the High Scores
    cout<<"*******************************************************"<<endl;
    cout<<"                      High Scores:"<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<endl;
    
    //Output the scores from both arrays sorted
    prntAry(names,score,n);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   fillAry      *************************************
//Purpose:  Fill an array of names from the names.dat file
//Inputs:   fn : string of 5 names saved to the names.dat file
//          a  : Array of the names from the names.dat file
//          n  : Size of the array
//Output:   Fill the names array
//******************************************************************************
void fillAry(string fn,string a[],int &n){
    //Declaration of Variables
    ifstream in;
    string temp;
    n=0;
    
    //Open the stream
    in.open(fn);
    
    //Read in data
    while(in>>temp){
        a[n++]=temp;
    }
    
    //Close the file
    in.close(); //Close the file
    in.clear(); //Clear the file
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   fillAry      *************************************
//Purpose:  Fill an array of scores from the score.dat file
//Inputs:   fn : string of 5 scores saved to the score.dat file
//          a  : Vector array of the scores from the score.dat file
//          n  : Size of the array
//Output:   Fill the scores array
//******************************************************************************
void fillAry(string fn,vector<float> &a,int &n){
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   prntAry  *****************************************
//Purpose:  Print the high scores as 2 parallel arrays
//Inputs:   fn : String array of names saved to the names file
//          a  : Vector array of integer numbers saved to the score file
//          n  : Size of the arrays
//Output:   Void Output (no return) - Displays the high scores
//******************************************************************************
void prntAry(string fn[],vector<float> &a,int n){
    //Declaration of Variables
    int count=0; //counter
    
    //Output and Display the Array
    for(int i=0;i<n;i++){
        cout<<setw(25)<<fn[i]<<" "<<setw(20)<<a[i]<<endl;
        if((count++)%10==9)cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   highScore   **************************************
//Purpose:  Determine if the high score is new or note. If new, write to file
//Inputs:   points : points from game 
//Output:   void output (no return))
//******************************************************************************
void highScore(float points){
    //Declaration of Variables
    ofstream out; //Output File
    short hScore; //High Score
    int n;
    int m;
    string name; //Input name
    const int SIZE=100;  //Size of the arrays
    string names[SIZE]; //Name Array
    vector<float> score(SIZE); //Score Vector
    string fnNames="names.dat";
    string fnScores="scores.dat";
    
    //Fill arrays
    fillAry(fnNames,names,n); //Fill names array
    fillAry(fnScores,score,m); //Fill scores array
    
    //Bubble Sort
    bubbSort(names,score,n);
    
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
//*************************   linSearch   **************************************
//Purpose:  Use a linear search to give a chance at an extra life
//Inputs:   range : Array of 20 random numbers between 1-100
//          n     : Size of the array
//          key   : Chance in the game function
//Output:   Returns true or false depending if the number was found
//******************************************************************************
bool linSearch(int range[],int n,int key){
    //Linear Search
    for(int i=0;i<n;i++){
        if(key==range[i]){
            return true; //If number is found return true
        }
    }
    return false; //If number is not found return false
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   bubbSort  ***************************************
//Purpose:  Use a bubble sort to sort arrays
//Inputs:   names   : string array with names
//          score   : vector with scores 
//          n       : Size = 5
//Output:   Void Output - no return - Sort where called
//******************************************************************************
void bubbSort(string names[],vector<float> &score,int n){
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
        len--; //Post decrement
    }while(swap);
}