/*
Stylianos Kalamaras
CS211 52B
HW#16 Stable Marriage Recursion
Date due: 10/21/16
Date created: 10/17/16

This program uses a recursive function to solve the Stable Marriage problem.
*/
#include <iostream> 
#include <cmath> 
#include <cstdlib>
using namespace std; 

bool ok(int *match,int mp[][3], int wp[][3], int column) {   
	//checks if women is already married
	for( int i=0;i<column;i++)
		if (match[column]==match[i]) return false;
	
	//preferance test 
	for (int i=0;i<column;i++) { 

		//if current women prefers other man over current man		
		if (wp[match[column]][i]< wp[match[column]][column] && mp[i][match[column]]< mp[i][match[i]])
			return false;

		//if current man prefers other woman over current woman
		if (mp[column][match[i]]<mp[column][match[column]] && wp[match[i]][column]<wp[match[i]][i])
			return false;
	}//for
	return true;//if passes all the conditions
}//ok 

//prints solution when found
void print(int *q) { 
	static int count =0; 
	cout<<++count<<". "; 
	for (int k=0; k<3; k++) 
        	cout<<q[k];
		cout<<endl;            
}//print
 
//takes match array, preferences and current position and recursively moves through the array for solutions to the problem
void move(int *match,int mp[][3], int wp[][3], int column) { 
            if(column==3) {            
            	print(match);            
                return;            
            }//if            

            for(int j=0;j<3;j++) { 
            	match[column]=j;            
		if(ok(match,mp,wp,column)) move(match,mp,wp,column+1); 
            }//for            
}//move 

int main() { 
            int q[3];            
            int mp[3][3]={{0,2,1},{0,2,1},{1,2,0}};//mans preferance
	    int wp[3][3]={{2,1,0},{0,1,2},{2,0,1}};//womens preferance
            move(q,mp,wp,0);            
            return 0;         
}//main 
