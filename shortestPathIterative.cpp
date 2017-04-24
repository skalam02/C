
/*
Stylianos Kalamaras
CS211 52B
HW #19 Shortest Path Problem
11/10/2016

This programs finds the shortest path through a matrix.
*/


#include<iostream> 
using namespace std; 
const int rows = 5; 
const int cols = 6;

//searches through cost array from current column to the three previous legal paths to find min and returns min row of the previous column
int rowSearch(int costArray[][cols],int rowcurrent,int cols) {
	int minVal=costArray[(rowcurrent+(rows-1))%rows][cols-1];
	int minRow=(rowcurrent+(rows-1))%rows;
	if(costArray[rowcurrent][cols-1]<minVal) {minRow=rowcurrent; minVal=costArray[rowcurrent][cols-1];}
	if(costArray[(rowcurrent+1)%rows][cols-1]<minVal) minRow=(rowcurrent+1)%rows;
	return minRow;
}//rowSearch	


//finds the min of three passed integer values
int minfunc(int up,int left, int down) {
	int minimum = up;
	if (left<minimum) minimum=left;
	if (down<minimum) minimum= down;	
	return minimum;
}//minfunc

//takes in weight matrix, and empty cost Array, and populates cost array with the cost matrix
void costfunc(int weight[][cols], int costArray[][cols], int rows, int cols){    // i is the row, j is the column 
	
	//sets values of cost matrix equal to values of weight matrix
	for(int i=0;i<rows;i++) {
		for (int c=0;c<cols;c++) {
			costArray[i][c]=weight[i][c];
		}//for
	}//for
	
	//creates the cost matrix 
	for (int c=1;c<cols;c++) {
		for (int r=0;r<rows;r++) {
			int mini= minfunc(costArray[(r+(rows-1))%rows][c-1], costArray[r][c-1], costArray[(r+1)%rows][c-1]);
			int i=costArray[r][c];
			costArray[r][c]=i+mini;
		}//for
	}//for

	//prints the cost matrix
	for(int i=0;i<rows;i++) {
		for (int c=0;c<cols;c++) {
			if(costArray[i][c]>=10)
				cout<<costArray[i][c]<<" ";
			else
				cout<<costArray[i][c]<<"  ";
		}//for
		cout<<endl;
	}//for
	cout<<endl;
}//costfunc
int main(){ 

	int weight[rows][cols]={ 
        {3,4,1,2,8,6}, 
        {6,1,8,2,7,4}, 
        {5,9,3,9,9,5}, 
        {8,4,1,3,2,6}, 
        {3,7,2,8,6,4}};  
	
	cout<<"Weight Matrix"<<endl;
	//prints weight matrix	
	for(int i=0;i<rows;i++) {
		for (int c=0;c<cols;c++) {
			cout<<weight[i][c]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//initalizing cost array
	int costArray[rows][cols]= {0};
	
	//calling costfunc to create cost matrix
	cout<<"Cost Matrix"<<endl;        
	costfunc(weight,costArray,rows,cols);

	//finds last column min starting point for shortest path
	int arrayMin=costArray[0][cols-1];
	int rpath[cols]={0};	
		for(int r=0, c=cols-1;r<rows;r++)
			if (costArray[r][c]<arrayMin) {arrayMin=costArray[r][c]; rpath[cols-1]= r;}
	
	//searches backwards through cost array to find min value of current row through (r-1,r,and r+1) (c-1) min and storing to rpath array	
	for (int c=5; c>0; c--) 
		rpath[c-1]=rowSearch(costArray,rpath[c],c);
	
	cout<<"Shortest Path"<<endl;	
	for(int i=0;i<cols;i++)
		cout<< rpath[i]<<" ";
	cout<<endl;			
	
return 0;
}   

