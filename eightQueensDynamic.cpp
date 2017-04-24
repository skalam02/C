/*
Stylianos Kalamaras
CS211 52B
HW#14
10/07/16

This program uses the backtracking algorithm and dynamically allocated array to solve the n-Queens problem.
*/
#include <iostream>
#include <cmath>
using namespace std;

//Test function
bool tF(int q[], int column) {
        for (int i=0;i<column;i++) if (q[column]==q[i] || column-i == abs(q[column]-q[i])) return true;
        return false;
      }

int main() {

          cout<<"Enter number for n-Queens: ";
          int num;
          cin>>num;
          //iterates the backtracking algorithm n-times
          for (int b=1;b<=num;b++) {
            //creates new dynamic array
            int *q = new int[b];
            //places value of -1 in all spaces of array
            for(int i=0;i<b;i++)
              q[i]=-1;
            int column=0,count=0;
            while(column!=-1) {
              q[column]++; //next row
              if (q[column]==b) {q[column]=-1; column--; continue;}//Out of bounds
              if(tF(q,column)) continue;//test
              column++; //next column
              if(column==b) {++count;column--;} //print
            }//while
          
	  cout<<"There are "<<count<<" solutions to the "<<b<<" Queens problem."<<endl; //solutions counter
          delete [] q;//garbage collection
          q=NULL;
        }//outer for
  return 0;
}//main
