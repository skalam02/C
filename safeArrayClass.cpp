//safe array

#include <iostream>
#include <cstdlib>
using namespace std;

class SA {

private:
int low;
int high;
int *p;

public:

//default constructor
	SA() {
		low=1;
		high=0;
		p=NULL;
	}
	SA(int x) {
	low=0;
	high=x-1;
	p=new int[high];	
	}

	SA(int lower,int upper) {
	if((upper-lower+1)<=0) {cout<<"Illegal bounds"<<endl; exit(1);}
	low=lower;
	high=upper;	
	int size=high-low+1;
	p=new int[size];
	}
	
	//copy constructor
	SA(const SA& s) {
		low=s.low;
		high=s.high;
		int size=high-low+1;
		p=new int[size];
		for(int i=0;i<size;i++) 
			p[i]=s.p[i];

	}
	
	~SA() {
	delete []p;
	}
	
	int& operator[](int x) {
		if(x<low||x>high) {cout<<"out of bounds index"<<endl; exit(1);}
		return p[x-low];

	}

	SA& operator=(const SA& s) {
	if(this==&s) return *this;
	high=s.high;
	low=s.low;
	delete []p;
	int size=high-low+1;	
	p =new int[size];
	for(int i=0;i<size;i++)
		p[i]=s.p[i];
	return *this;
	}

	friend ostream& operator<<(ostream& os, SA s);
	friend void Sort(SA& s, int size);
	
};//class


	ostream& operator<<(ostream& os, SA s) {
		int size=s.high-s.low+1;
		for(int i=0;i<size;i++) 
			os<<s.p[i];
		return os;
	};

	void Sort(SA& s, int size) {
	for(int i=0;i<size;i++) {
		int min=s.p[i];
		int index=i;
		for (int j=i;j<size;j++) {
			if(s.p[j]<min) {min=s.p[j]; index=j;}
		}//for
		int temp=s.p[i];
		s.p[i]=min;
		s.p[index]=temp;
	}//for

	}





int main() {

SA a(10), b(3,5);
b[3]=3; b[4]=4; b[5]=5;
int i;
for( i=0;i<10;i++)
	a[i]=10-i;
	cout<<"printing a the first time"<<endl; 
	cout<<a<<endl; 
	cout<<"printing using []"<<endl;
	for( i=0;i<10;i++)
	cout<<a[i]<<endl;
	// write your own sort
	Sort(a,10);
	cout<<"printing a the second time" <<endl;
	cout<<a<<endl;
	b[4]=12;
	cout<<"printing b "<<endl;
	cout<<b<<endl;

return 0;
}
