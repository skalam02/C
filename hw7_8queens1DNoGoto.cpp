
/*
Stylianos Kalamaras
CS211 52B
HW #7
09/15/2016

This programs solves the Eight Queens Problem using the backtracking Algorithm
without goto statements.

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

	int q[8]={-1},column=0,count=0; //set all postions to -1

		while(column!=-1) {
		q[column]++; //next row
		if (q[column]==8) {q[column]=-1; column--; continue;}//Out of bounds
		if(tF(q,column)) continue;//test
		column++; //next column
		if(column==8) {count++; for(int i=0;i<8;i++) cout<<q[i];cout<<endl;column--;} //print
		}
	cout<<"Total Solutions: "<<count<<endl; //solutions counter
	return 0;
}
