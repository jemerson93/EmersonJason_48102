/* 
   File:   main
   Author: Jason Emerson
   Created on October 10th, 2016, 11:25 AM
   Purpose: File I/O rudimentary Display/Game Interface
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //File I/O
#include <fstream>    //String Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    ifstream in;
    ofstream out;
    int rows,cols;
    string line;
    
    //Input values
    in.open("map.dat");
    in>>rows>>cols;
    cout<<"rows = "<<rows<<" cols = "<<cols<<endl;
    
    //Display Output / What is in the file to the output screen
    //In addition add in row numbers and column numbersfor the user
    getline(in,line);
    for(int row=1;row<=rows;row++){
        getline(in,line);
        cout<<row<<" "<<line<<endl;
    }
    cout<<"  ";
    for(int col=1;col<=cols;col++){
        cout<<col;
    }
    cout<<endl;
    
  //Where do you want to place the player
    int prow,pcol;
    cout<<"Where to position the player in row and column"<<endl;
    cin>>prow>>pcol;
    cout<<"Player position in Y = "<<prow<<" Player position in X = " <<pcol<<endl;
    
    //Read back in the file
    in.close();
    in.clear();
    
    //Input Values
    in.open("map.dat");
    in>>rows>>cols;
    cout<<"rows = "<<rows<<" cols = "<<endl;
    
    //Display Output and Write to the Player File
    out.open("player.dat");
    getline(in,line);
    for(int row=1;row<=rows;row++){
        getline(in,line);
        if(row==prow&&line[pcol-1]=='0')line[pcol-1]='P';
        cout<<row<<" "<<line<<endl;
        out<<line;
    }
    cout<<"  ";
    for(int col=1;col<=cols;col++){
        cout<<col;
    }
    cout<<endl;
    
    //Close the File
    in.close();
    out.close();

    //Exit Program
    return 0;
}