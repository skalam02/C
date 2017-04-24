// Eight Queens Using the STL next_permutation algorithm
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

	void print(int q[], int c){
		cout<<"Solution # "<<c<<":   ";
		for(int i=0; i<8; i++)
			cout<<q[i]<<" ";
			cout<<endl;
		return;
		}

	bool ok(int* k){
		for(int col=7; col>0; col--)
			for(int i=0; i<col; i++)
				if((abs(k[col]-k[i]) == col-i))
					return false;
		return true;
	}

int main () {
	int q[] = {0,1,2,3,4,5,6,7};
	int count=0;
	do {
	if(ok(q))
	print(q,++count);
	} while ( next_permutation (q,q+8) );

return 0;
}


