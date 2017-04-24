#include <iostream>
using namespace std;

//This program utilizies the binary search algorithm to find a target number in 1000 possibilities.


int main() {

int *a=new int[1000];

for(int i=0;i<1000;i++) {
	a[i]=i;
}


int target;

cout<<"Enter Target between 0 and 999: ";
cin>>target;

int l=0,h=999;

int guess=0;
while (l<=h) {
	int avg = l+(h-l)/2;
	guess++;
	if(a[avg]==target) {cout<<"found on guess "<<guess<<endl;delete[] a; return 0;}
	if(a[avg]<target) l=avg+1;
	else h=avg-1;
}


cout<<"not found"<<endl;
delete[] a;

return 0;
}
