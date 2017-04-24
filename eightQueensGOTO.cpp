#include <iostream>
using namespace std;


//This program solves the eight queens problem using backtracking and goto statements. It finds all possible
//solutions and prints the boards to screen when a solution is found by marking 1 in the position in where the 
//queen should be.

int main () {

	//Initialize and zero chess board
	int chessBoard[8][8], c=0, n=8,count=0,success=0;
	for (int r=0;r<n;r++) 
		for (int c=0;c<n;c++)
			chessBoard[r][c]=0;
	//****************************************
	chessBoard[0][0]=1; //Set starting queen
	NC: c++; //Move next column
	BT: int r=-1; //Go to row 0
	NR: r++;      //go to row 0
		if (r==8) goto BACKTRACK;
	TEST:
	count++; //Attempt counter
	//Row test
	for (int i=0;i<c;i++) {
		if(chessBoard[r][i]==1){
			goto NR; 
		}
	}
	//Upward Diagonal check
	for (int i=0 ; (r-i) >=0 && (c-i)>=0 ; i++) {
		if (chessBoard[r-i][c-i]==1) {
			goto NR;
		}
	}
	//Downward diagonal check
	for (int i=1; (r+i)<8 && (c-i) >=0 ; i++) {
		if (chessBoard[r+i][c-i]==1) {
			goto NR;
		}
	}

	chessBoard[r][c]=1; //Place queen at current position
	//For loop that prints a successful Eight Queen Chess Board
	if (c==7) {
	for (int r=0;r<n;r++) { 
		for (int c=0;c<n;c++){ 
                        cout <<chessBoard[r][c];
		}
	cout<<endl;
	}
	cout<<endl; //End of for loop

	success++; //Counter to check successful check
	}
	goto NC; //Goes to next column

	BACKTRACK: c--;  //Backtracking  loop
		if (c==-1){  //Terminating Condition
			cout <<"Tries: "<<count<<" Success: "<<success<<" Algo Efficiency: "<<success/(double)count<<endl;// Attempts/Success
			return 0;
		}
		r=0;
		while(chessBoard[r][c]!=1)
			r++;
			chessBoard[r][c]=0;
			goto NR;
}
