#include <iostream>
using namespace std;

//This program finds the GCD using Euclidean Algortithm then prints out the GCD and prints the fraction in
//lowest terms
int main() {

	//find max of n,d
	int one;
	int two;
	cout<<"enter value 1: ";
	cin>>one;
	cout<<"enter value 2: ";
	cin>>two;
	int max=one;
	int min=two;
	if(two >max) {max=two;min=one;}
	int temp;
	while(min!=0) {
		temp=max;
		max=min;
		min=temp%min;
	}
	cout<< max<<endl;
	one=one/max;
	two=two/max;
	
	cout<<one<<"/"<<two<<endl;
return 0;
}
