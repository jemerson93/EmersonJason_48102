/* 
   File:   main
   Author: Jason Emerson
   Created on October 22th, 2016, 1:26 AM
   Purpose: Hangman with a number guessing game that gets increasingly more difficult
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number
#include <ctime>     //Set the random number seed
#include <fstream>   //File I/O
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int showMenu();
void printInstructions();
void playGame();
void drawBoard(int guesses);
void readHighScore();
void highScore(int score);

//Execution Begins Here!
int main(int argc, char** argv) {
	int mChoice;
	
    //Welcome
    cout<<"***************************************"<<endl;
    cout<<"      Welcome to Number Hangman!"<<endl;
    cout<<"***************************************"<<endl;
    
	//Display the main menu and get the user's choice.
	do{
                switch (showMenu()){ //Process the user's choice.
			case 1:
				mChoice=1;
                playGame();
            break;
            case 2:
				mChoice=2;
                printInstructions();
            break;
            case 3:
                readHighScore();
                                mChoice=3;
            break;
            case 4:               
			default:
				mChoice=4;
            break;
                }        
        }while(mChoice>0&&mChoice<4);
    
    return 0; //Exit Program
}

/************************************************
 *******************showMenu*********************
 *  Function: Show the menu                     *
 *  Input: Choice                               *
 *  Output: Choice to main                      *
 ************************************************
 *************************************************/

    int showMenu(){
        int choice = 0;
        do{
            cout<<"Press 1 to begin the game"<<endl;
            cout<<"Press 2 for instructions"<<endl;
            cout<<"Press 3 to display the high score"<<endl;
            cout<<"Press 4 to exit the game"<<endl;
            cin>>choice;
            if(choice<1||choice>4)
                cout<<"Invalid choice. Please enter a correct value"<<endl;
        }while(choice<1||choice>4);
        return choice;
    }
    
/************************************************
 ****************printInstructions***************
 *  Function: Show instructions                 *
 *  Input: None                                 *
 *  Output: void                                *
 ************************************************
 *************************************************/
    
    void printInstructions(){
        char goBack;
                
        cout<<endl;
        cout<<"************************************************"<<endl;
        cout<<"                  Instructions"<<endl;
        cout<<"************************************************"<<endl;
        cout<<"This is my version of hangman. Instead of guessing a random letter to attempt to complete a word";
        cout<<"instead you will guess a random number in a range of numbers. If the number is guessed"<<endl;
        cout<<"incorrectly you will lose a life.";
        cout<<"If the number is guessed correctly, you will move on to a higher range of numbers. The difficulty will continue to become"<<endl;
        cout<<"progressively difficult as the game goes on. You will receive a addition to your score whenever you guess a number correctly."<<endl;
        cout<<"You have 6 lives to get as high of a score as you can. At the end of the game when you exit, your score will be saved to be used next"<<endl;
        cout<<"time you play the game. Enjoy the game and remember to have fun!"<<endl;
        cout<<endl;
        cout<<"Game made by Jason Emerson for CSC 5 at Riverside Community College"<<endl;
		cout<<"Press any key and press enter to return to the menu"<<endl;
		cin>>goBack;
    }
	
/************************************************
 *********************playGame*******************
 *  Function: Game function - play the game     *
 *  Input: guess                                *
 *  Output: void                                *
 ************************************************
 *************************************************/
    
    void playGame(){
        //Set the random number seed
        srand(time(0));
        
        //Declare Variables
        int rnum, guess, max, guesses, score;
        bool nxtlvl; //Move on to the next level if true, do not if false
        int maxG = 6;  // The max number of guesses allowed.
        int lvlInc = 5; // The amount to increase the random number range by.
		
		//Initialize variables
		rnum=0;
		guess=0;
		max=10;
                score=0;
                nxtlvl=true; //Variable to be used to decide whether or not to continue to next level.
        
		while(nxtlvl){
			nxtlvl=false; //Set to false so loop doesn't iterate if player loses.
			guesses=1; //Set to zero, we started a new level.
			rnum=rand()%max+1; //Generate a number between 1 and max;
			cout<<"Your number range is between 1 and "<<max<<". Please input your guess."<<endl;
			cin>>guess;
			while(guess!=rnum && guesses < maxG){ // Guess was wrong and player has guesses left.
				guesses++;  // Increment guesses.
				if(guess>rnum){
					cout<<"Guess is too high. Please try again."<<endl;
				} else if(guess<rnum){
					cout<<"Guess is too low. Please try again."<<endl;
				}
				drawBoard(guesses);
				cin>>guess;
			}
			if(guess==rnum){ // Their guess was correct.
				cout<<"You guessed correctly. Increasing difficulty."<<endl;
				max+=lvlInc; //Increase the range by the constant.
				nxtlvl=true;
                                score+=maxG-guesses;
                        } else { // Guess was not correct. Exited loop giving them max guesses.
				cout<<"Sorry, better luck next time"<<endl;
				nxtlvl=false;
                                highScore(score);
			}
		}
	}
    
/************************************************
 *******************drawBoard********************
 *  Function: Draw the Hangman Board            *
 *  Input: None                                 *
 *  Output: void                                *
 ************************************************
 *************************************************/
	
	void drawBoard(int guesses){
            //Declare Variables
            int maxG = 6;  // The max number of guesses allowed.
		cout<<"guesses = "<<guesses<<endl;
		cout<<"guesses remaining ="<<maxG-guesses<<endl;
                
      //Each hangboard per guess
		switch(guesses)
		{
			case 0:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |        "<<endl;
			cout<<" |        "<<endl;
			cout<<" |        "<<endl;
			cout<<" |        "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 1:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |        "<<endl;
			cout<<" |        "<<endl;
			cout<<" |        "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 2:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |    |   "<<endl;
			cout<<" |    ^   "<<endl;
			cout<<" |        "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 3:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |   o|   "<<endl;
			cout<<" |    ^   "<<endl;
			cout<<" |        "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 4:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |   o|o  "<<endl;
			cout<<" |    ^   "<<endl;
			cout<<" |        "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 5:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |   o|o  "<<endl;
			cout<<" |    ^   "<<endl;
			cout<<" |   o    "<<endl;
			cout<<" +-------+"<<endl;
			break;
			case 6:
			cout<<" +----+   "<<endl;
			cout<<" |    !   "<<endl;
			cout<<" |    O   "<<endl;
			cout<<" |   o|o  "<<endl;
			cout<<" |    ^   "<<endl;
			cout<<" |   o o  "<<endl;
			cout<<" +-------+"<<endl;
			break; // No default case.
		}

	}
        
/************************************************
 ****************readHighScore*******************
 *  Function: Display the high score            *
 *  Input: file                                 *
 *  Output: high score                          *
 ************************************************
 *************************************************/
  
        void readHighScore(){
            //Declaration of Variables
            ifstream in;
            string line;
            string name;
            int score;
            
            //Input Values
            in.open("highscore.dat"); //Open High Score File
            
            //Display High Score
            cout<<"**********************************"<<endl;
            cout<<"           High Score:"<<endl;
            cout<<"**********************************"<<endl;
            getline(in,line);
            cout<<line;
            cout<<endl;
            getline(in,line);
            cout<<line;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            
            //Close the File
            in.close();
        }
        
/************************************************
 *******************highScore********************
 *  Function: Write to high score file          *
 *  Input: file                                 *
 *  Output: to file                                *
 ************************************************
 *************************************************/
        void highScore (int score){
            //Declaration of Variables
            ifstream in;
            ofstream out;
            string name;
            //get high score from file
            
            string line;
            
            //Read High Score
            in.open("highscore.dat"); //Open High Score Files
            static int hScore =20;
            in>>hScore;
               //If a new high score
            if(score>hScore){
            cout<<"Congratulations you have a new high score"<<endl;
            cout<<"Please enter your name."<<endl;
            cin>>name;
            out.open("highscore.dat"); //Write new score to file
            out<<name;            //Write to File
            out<<endl;
            out<<score;
                      //Close the File
            out.close();
            out.clear();
            
            cout<<"Saved to file!"<<endl;
            
            }else{
                in.open("highscore.dat");
                in>>hScore;
                
                cout<<"Sorry no new high score"<<endl;
            } 
        }