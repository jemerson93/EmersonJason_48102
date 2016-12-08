/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jason
 *
 * Created on December 6, 2016, 11:42 AM
 */

#include <iostream>

using namespace std;
const int NUMCOLS=100;

void  fillArray(bool [][NUMCOLS],int=4,int=3);
void position(bool[][NUMCOLS], char[][NUMCOLS] int &, int &);
void fillchar(char [][NUMCOLS], int=4), int=3);

int main(int argc, char** argv) {
    bool a[][NUMCOLS];
    char hang[][NUMCOLS];
    filarray[a];
    fillchar[hang];
    int ccols=0;
    int crows=0;
    do{
       ccols+=1; 
       crows+=1;
       bool
    }while(a[4][3]==true);
    return 0;
}

void fillArray(bool a[][NUMCOLS], int n, int m){
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cout<<a[i][k]=true;
        }
    }
}

void position(bool a[][NUMCOLS], char b[][NUMCOLS], int n, int m){
    if((n==0 && m==1)&&a[n][m]==false){
        b[n][m]= 'O';
        n=1,m=1;
    }else if((n==1 && m==1)&&a[n][m]==false){
        b[n][m]= 'o|';
        n=1,m=0;
    }else if((n==1 && m==0)&&a[n][m]==false){
        b[n][m]= 'o';
        n=1,m=2;
    }else if((n==1 && m==2)&&a[n][m]==false){
        n=3,m=0;
    }else if((n==3 && m==0)&&a[n][m]==false){
        n=3,m=2;
    }
   
}


/*score[]
 name[]
 * cout<<name[]
 */