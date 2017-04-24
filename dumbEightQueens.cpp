/*
Stylianos Kalamaras 
CS211 52B
HW#9 Dumb 8 Queens Problem
09/25/16

This program does a brute force search and tests every single configuration (8^8) of the Eight Queens 
Problem for  a solution. It stores every configuration into an array that gets tested, and if it passes
the test, a print function is called which initializes a two dimensional array that is zeroed out, and
the indexes/values of the queens on the successful 1D are entered into the 2d array. The program then
prints out the two dimensional array with the queens placed on the chessboard.
*/


#include<cmath> 
#include<iostream>
using namespace std;

bool tF(int q[],int &testCount) {//tests to see if the array is a succesful solution
	testCount++;	
	for (int c=1;c<8;c++) 
		for (int i=0;i<c;i++) if (q[c]==q[i] || c-i == abs(q[c]-q[i])) return false;
	return true;
}
void printBoard(int q[], int &count) {//prints a 2D array solution. Increments count variable by referance
	count++;
	int q2[8][8]={0};	
	for (int i=0;i<8;i++)
		q2[q[i]][i]=1;
	for (int r=0;r<8;r++){
		for (int c=0;c<8;c++){
			cout <<q2[r][c];
		}
	cout<<endl;
	}
}
int  main( ) { 
int board[8][8]={0};
    int count = 0, testCount=0;
    for(int i0 =0; i0 <8; i0 ++)//column 0 
        for(int i1 =0; i1 <8; i1 ++)//column 1
            for(int i2 =0; i2 <8; i2 ++)//column 2
                for(int i3 =0; i3 <8; i3 ++)//column 3
                    for(int i4 =0; i4 <8; i4 ++)//column 4
                        for(int i5 =0; i5 <8; i5 ++) //column 5
                            for(int i6 =0; i6 <8; i6 ++)//column 6
                                for(int i7 =0; i7 <8; i7 ++){ //column 7
				     int q[] = {i0,i1,i2,i3,i4,i5,i6,i7};
					if(tF(q,testCount)) {printBoard(q,count); cout<<endl;} //test & print function
				}//column 7 for loop
	cout<<"Total solutions: "<<count<<endl<<"Total Tries: "<<testCount<<endl;                             
return 0;
}//main 

