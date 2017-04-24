/*
Stylianos Kalamaras
CS211 52B
HW #11
10/07/2016
This program solves the Stable Marriage Problem using the backtracking Algorithm.
*/

#include <iostream>
#include <cmath>
using namespace std;

//Checks if person is already engaged
bool alreadyProposed(int match[], int column) {
	for( int i=0;i<column;i++)
	if (match[column]==match[i]) return true;// checks if women is already with another man
	return false;
}

//checks if current man prefers other woman over current woman
bool problem(int mp[][3], int wp[][3], int match[], int column) {
	for (int i=0;i<column;i++) { //loops through people

		//if current women prefers other man over current man		
		if (wp[match[column]][i]< wp[match[column]][column] && mp[i][match[column]]< mp[i][match[i]])
			return true;
		//if current man prefers other woman over current woman
		if (mp[column][match[i]]<mp[column][match[column]] && wp[match[i]][column]<wp[match[i]][i])
			return true;
	}//outer for
	return false;//if passes all the conditions
}//problem


int main() {
	int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};//mans preferance
	int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};//womens preferance

	int q[3]={-1},column=0,count=0; //set all postions to -1

		while(column!=-1) {		
		q[column]++; //next row
		if (q[column]==3) {q[column]=-1; column--; continue;}//Out of bounds
		if(alreadyProposed(q,column)) continue;//checks if person is engaged
		if(problem(mp,wp,q,column)) continue;//checks if man or women prefer other man or women
		column++; //next column
		if(column==3) {cout<<++count<<". "; for(int i=0;i<3;i++) cout<<q[i];cout<<endl;column--;} //print
		}
	cout<<"Total Solutions: "<<count<<endl; //solutions counter
	return 0;
}


