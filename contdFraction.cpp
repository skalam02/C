/*
Stylianos Kalamaras
CS211 52B
HW #21
12/01/2016

This program includes the continued fractions function.

*/
#include <iostream>
using namespace std;

class Rat{
	private:
	int w=NULL;
    	int n;
    	int d;
	
	//reduces rational number
	void reduce() {
		//step 1. Find max
		int a,b;
		if(n>d) {a=n,b=d;}
		else {a=d,b=n;}
		
		//step 2. Find GCD
		while(b!=0) {
			int temp=a;		
			a=b;
			b=temp%a;
		}//while

		//step 3. Divide by GCD
		n/=a;
		d/=a;	
		/*
		//step 4. Implement whole number if needed
		if (n>d) {
		w=n/d;
		n=n-(w*d);
		}//if
		*/
	}//reduce

	public:
    
	Rat(){
        	n=0;
        	d=1;
    	}//rat 0 args

    	// 2 parameter constructor
    	Rat(int i, int j){       	
		n=i;
        	d=j;
   	 }//rat 2 args

    	// conversion constructor
    	Rat(int i){        	
		n=i;
        	d=1;
    	}//rat converter

    	//accessor functions 
    	int getN(){ return n;}
    	int getD(){ return d;}
    	void setN(int i){ n=i;}
   	void setD(int i){ d=i;}
    
	//arithmetic operators
    	Rat operator+(Rat r){
        	Rat t;
        	t.n=n*r.d+d*r.n;
        	t.d=d*r.d;
		//t.reduce();
        	return t;
    	}//operator+

	Rat operator-(Rat r) {
		Rat t;
		t.n=n*r.d-d*r.n;
		t.d=d*r.d;
		t.reduce();
		return t;
 	}//operator-

	Rat operator*(Rat r) {
		Rat t;
		t.n= n*r.n;
		t.d=d*r.d;
		t.reduce();
		return t;
	}//operator*

	Rat operator/(Rat r) {
		Rat t;
		t.n=n*r.d;
		t.d=d*r.n;
		t.reduce();
		return t;
	}//operator/

  	// 2 overloaded i/o operators
    	friend ostream& operator<<(ostream& os, Rat r);
    	friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

	//output
	ostream& operator<<(ostream& os, Rat r){
		if(r.w!=NULL) {
			if(r.n==0) { os<<r.w<<endl;}
			else {os<<r.w<<" "<<r.n<<"/"<<r.d<<endl;}
		}
		else {
        		if(r.n==0) os<<0;
			else os<<r.n<<"/"<<r.d<<endl;
		}
        	return os;
	}//operator<<

	//input
	istream& operator>>(istream& is, Rat& r){
		is>>r.n>>r.d; 
   	return is;
	}//operator>>

//returns continued fraction as a double	
double fraction(int a[], int size) {
	double runningSum;
	runningSum= 1.0/(a[--size]);
	--size;
	while(size>0) 
	runningSum= 1.0/(a[size--]+runningSum);

	runningSum+=a[size];
	return runningSum;
}//double fraction

//stores continued fraction as n/d in an array of size two
void fraction(int a[], int size,int b[2]) {
	Rat runningSum(1,a[--size]),conv,one;
	one=1;
	--size;
	while(size>0) {
	conv=a[size--];
	runningSum= (one/(conv+runningSum));	
	}
	runningSum=runningSum+a[size];
	b[0]=runningSum.getN();
	b[1]=runningSum.getD();
	cout<<b[0]<<"/"<<b[1]<<endl;
}//void fraction


int  main(){
  
int array[]={9,7,5,3,1},pq[2],size=5;
double rat=fraction(array,size);
cout<<"Continued fraction as a double: "<<rat<<endl;
cout<<"Continued fraction as p/q SIMPLIFIED: ";fraction(array,size,pq);
return 0;
} 

