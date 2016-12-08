/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jason
 *
 * Created on December 6, 2016, 1:18 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fillAry(int [],int);
void prntAry(int [],int);
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    const int SIZE=100;
    int utilize=0;
    int arr[SIZE];
    int num=0;
    
    for(int i=SIZE;i<SIZE;i++){
        arr[i]=i+1;
    }    
    
    for(int i=0;i<20;i++){
        num=arr[(rand()%20+1)];
        cout<<num<<endl;
    }
    return 0;
}