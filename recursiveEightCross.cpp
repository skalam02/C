/*
Stylianos Kalamaras
CS211 52B
Date due: 10/21/16
Date created: 10/17/16

This program solves the 8 number in a cross problem recursively and prints all the solutions.
*/
#include <iostream>
#include <cmath>
using namespace std;
//checks to see if there is a conflict with the current number and the adjacent numbers
bool test(int q[8],int col){
         int adjacency[8][4]={
           {-1,-1,-1,-1},//index 0
           {0,-1,-1,-1},//index 1
           {1,-1,-1,-1},//index 2
           {0,1,2,-1},//index 3
           {1,2,3,-1},//index 4
           {0,3,4,-1},//index 5
           {3,4,5,-1},//index 6
           {2,4,6,-1}};//index 7
         for(int i=0;i<col;i++)
            if(q[i]==q[col]) return false;//same number test
         for(int i=0; adjacency[col][i]!=-1;i++)//adjaceny test
            if(abs(q[col]-q[adjacency[col][i]])==1) return false;
         return true;
}//test

//prints the solution when found
void print(int q[8]){
    static int count=0;
    cout <<"Cross "<<++count<<endl;
    cout <<" "<<q[1]<<q[2]<<endl<<q[0]<<q[3]<<q[4]<<q[7]<<endl<<" "<<q[5]<<q[6]<<endl<<endl;
}//print

//recursively moves through the array until all solutions are found
void move(int* q, int i){
    if(i==8){
        print(q);
        return;
    }//if

    for(int j=1; j<=8; j++){
        q[i]=j;
        if(test(q,i)) move(q,i+1);
    }//if
}//move

int main(){
    int q[8];
    move(q,0);
    return 0;
}//main
