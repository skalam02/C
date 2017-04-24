#include <iostream>
using namespace std;


//Euclidean GCD with subtraction

int gcd(int x,int y) {

	if (x==y) return x;
	else if(x>y) return gcd(x-y,y);
	else return gcd(x,y-x);
}



int main() {


cout<<gcd(3,4)<<" "<<gcd(9,36)<<endl;

return 0;
}
