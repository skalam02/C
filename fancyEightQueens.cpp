/*
Stylianos Kalamaras
CS211 52B
HW #10
09/25/2016

This program solves the Eight Queens Problem using the backtracking Algorithm using a one dimensional array. 
It prints a fancy chessboard design of every solution found.

*/

#include <iostream>
#include <cmath>
using namespace std;
typedef char box[5][7];//box type


//Test function
bool tF(int q[], int column) {
	for (int i=0;i<column;i++) if (q[column]==q[i] || column-i == abs(q[column]-q[i])) return true;
	return false;
}//tF

//fills empty black and white boxes
void fillBoxes(char wb[][7], char bb[][7]) {
	int i,j;	
	for (i=0;i<5;i++)
		for (j=0;j<7;j++) {
			wb[i][j]=' ';
			bb[i][j]=char(219);
        	}//for
}//fillBoxes

//filles queen boxes
void fillQueen(char bq[][7],char wq[][7]) {
	for (int r=0;r<5;r++)
        	for (int c=0;c<7;c++) {
                        if (r==1 || r==2 || r==3)
				if (c==2|| c==4) {bq[r][c]=' '; wq[r][c]=char(' ');}
				else {bq[r][c]=char('x'); wq[r][c]=char(219);}
			else if (r==4) {bq[r][c]=char('x'); wq[r][c]=char(219);}			
			else {bq[r][c]=' '; wq[r][c]=char(219);}
		}//for
}//fillQueen

//prints finished chessboard
void finishedBoard(box *board[8][8]) {

//Print top border		
	cout<<"   ";
	for(int i=0;i<58;i++)
        	cout<<'_';
	cout<<endl;

//Print board
       	for(int i=0;i<8;i++) {
		for(int k=0;k<5;k++) {
			cout<<"     "<<char('|'); //print left border	
			for(int j=0;j<8;j++)
                       		for(int l=0;l<7;l++)
                               		cout<<(*board[i][j])[k][l];
		cout<<char('|')<<endl; // end of line bar
         	}//for loop
	}

//Print lower border       	
	cout<<"     ";
       	for(int i=0;i<58;i++)
		cout<<char('-');
       	cout<<endl;  

}//finishedBoard

int main() {

	box bb,wb,bq,wq,*board[8][8];
	fillBoxes(wb,bb); //fills black and white boxes
        fillQueen(bq,wq); //fills queens
	
	//fill empty board
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)        		
			if((i+j)%2==0) board[i][j]=&wb;
        		else board[i][j]=&bb;

	int q[8]={-1},column=0,count=0; //set all postions to -1
	
	while(column!=-1) {
		q[column]++; //next row
		if (q[column]==8) {q[column]=-1; column--; continue;}//Out of bounds
		if(tF(q,column)) continue;//test
		column++; //next column
		if(column==8) {
			cout<<++count;//prints solution number

			//sets queens on board		
			for (int i=0;i<8;i++) 
				if ((q[i]+i)%2==0) board[q[i]][i]=&bq;
				else board[q[i]][i]=&wq;	
			//prints board
			finishedBoard(board);
		}//if c==8
		
		//resets board				
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)        		
				if((i+j)%2==0) board[i][j]=&wb;
        			else board[i][j]=&bb;		
			
		q[column]=-1; //set row to -1
	}//while
		
	cout<<"Total Solutions: "<<count<<endl; //solutions counter
return 0;
}


