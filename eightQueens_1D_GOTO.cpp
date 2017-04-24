#include <iostream>
#include <cmath>
using namespace std;

//This program solves the eight queens problem using a 1D array and stores the row number of the queen in each column
//of the array. This program uses the backtracking algorithm to find the solutions and goto statements.

int main () {

	//Initialize chess board
	int q[8]={0}, c=0, n=8,count=0,success=0;

	//****************************************

	NC: c++; //Move next column
	if (c==8) {
		 success++;
		 goto PRINT;
	}
	q[c]=-1; //r=-1
	NR: q[c]++;      //go to next row r++
		if (q[c]==8) goto BACKTRACK;

	count++; //Attempt counter
	//TEST
	for (int i=0;i<c;i++)
		if (q[c]==q[i] || c-i == abs(q[c]-q[i])) goto NR;

	goto NC;
	PRINT: cout<<"Solution "<<success<<": ";for (int i=0;i<c;i++) cout<<q[i]; cout <<endl;
	BACKTRACK: c--;  //Backtracking  loop
		if (c==-1){  //Terminating Condition
			cout<<"Solutions: "<<success<<" Attempts: "<<count<<endl;
			return 0;
		}
		goto NR;
}
