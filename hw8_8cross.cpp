/*
Stylianos Kalamaras
CS211 52B
HW #8
09/16/2016

This programs solves the Eight Cross Problem using the backtracking Algorithm.
The numbers printed from the are array indexed to the cross as follows-

	        **
	        12
	      *0347*
	        56
                **

*/

#include <iostream>
#include <cmath>
using namespace std;

//Checks to see if numbers are adjacent
bool ok(int q[8], int square){
    int adjacents[8][4]={{-1, -1, -1, -1},
                        {0, -1, -1, -1},
                        {1, -1, -1, -1},
                        {0, 1, 2, -1},
                        {1, 2, 3, -1},
                        {0, 3, 4, -1},
                        {3, 4, 5, -1},
                        {2, 4, 6, -1}};
    for(int i=0; i<square; i++){
        if(q[i]==q[square]) return true;
    }
    for(int j=0; adjacents[square][j]!=-1; j++){
        if(abs(q[square]-q[adjacents[square][j]])==1) return true;
    }
    return false;
};

int main() {

	int q[8]={0},column=0,counter=0, count=0; //Initalize cross array
	string lines="---------------------------------";
	
		while(column!=-1) {
			q[column]++; //next row
			if (q[column]==9) {q[column]=0; column--; continue;}//Out of bounds
			if(ok(q,column)) continue;//adjacent test
			//if(doubleTest(q,column)) continue;//reuse test
			column++; //next column
			if(column==8) {
				column--;//moves back a column
				counter++;//counts every time a solution is found
				for(int r=0;r<3;r++) {//nested for loop that prints out the cross with appropriate solution
					for (int c=0;c<4;c++) {
						if (r==0)
							if(c==1) cout<<q[1];
							else if (c==2) cout<<q[2];
							else cout<<" ";
						if (r==1)
							if(c==0) cout<<q[0];
							else if (c==1) cout<<q[3];
							else if (c==2) cout<<q[4];
							else cout<<q[7];
						if (r==2)
							if(c==1) cout <<q[5];
							else if (c==2) cout <<q[6];
							else cout<<" ";
					}//inner for loop
				cout <<endl;//print at new line
				}//outer for loop
				cout<<endl;//places new line between solutions
			}//if (print)
		}//while

	cout<<"Total Solutions: "<<counter<<endl; //solutions counter
return 0;
}//main
