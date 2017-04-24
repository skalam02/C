/*
Stylianos Kalamaras
CS211 52B
Date Due: 10/21/16
Date Created: 10/14/16
HW#15 Towers of Hanoi
This program solves the towers of hanoi problem iteratively for both even and odd case discs.
*/

#include <iostream>
#include<cmath> 
#include<vector>
using namespace std;

int main(){
	vector <int> t[3]; // three towers A,B,C represented as an array of vectors
	int n, candidate,to, from, move=0; // move counts the move number
	cout<<"Please enter a number of rings to move: ";
	cin>>n;
	cout<<endl;

	//intitialize the 3 towers
	for(int i=n+1;i>=1;i--)
		t[0].push_back(i);
		t[1].push_back(n+1);
		t[2].push_back(n+1);

	// initialize towers and candidate
	if(n%2==1) {          	
		from=0;
		to=1;
		candidate=1;
	}//if
	else {
		from=0;
		to=2;
		candidate=1;
	}//else


	while(t[1].size()<n+1 && n%2==1){

		cout<<"move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<endl;
		t[to].push_back(t[from].back());
		t[from].pop_back();

		if(t[(to+1)%3].back()<t[(to+2)%3].back())
                	from=(to+1)%3;
                else
                        from=(to+2)%3;
                      
		
                if(t[(from+1)%3].back()<t[from].back())
                        to=(from+2)%3;
                else
                        to=(from+1)%3;
                
                candidate=t[from].back();
        }//while odd
	
	while(t[1].size()<n+1 && n%2==0){
                  
        	cout<<"move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<endl;
                t[to].push_back(t[from].back());
		t[from].pop_back();
                    
                if(t[(to+2)%3].back()<t[(to+1)%3].back())
                	from=(to+2)%3;
                else
                       	from=(to+1)%3;
                      
                if(t[(from+2)%3].back()<t[from].back())
                        to=(from+1)%3;
                else
                        to=(from+2)%3;

                candidate=t[from].back();// it’s on the top of the current “from tower”
	}//while even

return 0;
}//main
