/*
Stylianos Kalamaras
CS211 52B
HW #18 n Bishops
11/10/2016

This programs solves the n Bishops problem using the backtracking algorithm for n board sizes 
and 1-n bishop configurations.
*/
#include <iostream>
#include <cmath>
using namespace std;

//Test function
bool ok(int q[], int col, int n){
    
    int crow = q[col]/n, ccol = q[col]%n, irow, icol;

    for(int i=0; i<col; i++){ //for every bishop
        irow = q[i]/n;
        icol = q[i]%n;
        //diagonal test
        if(abs(crow-irow)==abs(ccol-icol)) return true;
	if(q[i]<q[col]) return true;
    }

    return false;
};

int main() {

	cout<<"Enter number for n-Bishops: ";
	int num;
	cin>>num;
	//iterates the backtracking algorithm num-times (this creates the board size from 1-num)
	for (int b=1;b<=num;b++) {

		//this forloop creates the 1d bishop solution array for size 1-board size
		for (int c=1;c<=b;c++) {

			//initializes 1d solution array for bishiops and sets vals to -1
			int *q = new int[c];
			for(int i=0;i<c;i++)
              			q[i]=-1;
			int column=0,count=0;

			//backtracking algorithm
			while(column!=-1) {
				q[column]++; //next row
				if (q[column]==(b*b)) {q[column]=-1; column--; continue;}//Out of bounds
				if (ok(q,column,b)) continue;//test
				column++; //next column
				if (column==c) {++count;column--;} //print
			}//while

			cout<<"There are "<<count<<" solutions to the "<<c<<" Bishops problem on the "<<b<<"by"<<b<<"board"<<endl; //solutions counter
			delete [] q;//garbage collection
			q=NULL;
		}//inner for
		cout<<endl;
        }//outer for
return 0;
}//main
