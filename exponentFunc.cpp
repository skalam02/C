#include <iostream>


//recursive function to raise base to some power

using namespace std;

int f(int b, int e) {
	if (e==0) return 1;
	return f(b,e-1)*b;
}	

int main() {
cout<< "enter base,exp";
int b,e;
cin>>b;
cin>>e;
cout<<f(b,e)<<endl;

return 0;
}
