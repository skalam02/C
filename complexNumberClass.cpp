#include <iostream>
using namespace std;

class complex {

	double r;
	double i;
	
	public:
	
	complex() {
	r=0;
	i=0;
	}
	complex(double a,double b) {
	r=a;
	i=b;
	}
	complex operator+(complex c) {
		complex n;
		n.r=r+c.r;
		n.i=i+c.i;
		return n;
	}

	complex operator-(complex c) {
		complex n;
		n.r=r-c.r;
		n.i=i-c.i;
		return n;
	}
	
	complex operator*(complex c) {
		complex n;
		n.r=(r*c.r)-(i*c.i);
		n.i=(i*c.r)+(r*c.i);
		return n;
	}

	complex operator/(complex c) {
		complex n;
		n.r= ((r*c.r)+(i*c.i))/((c.r*c.r)+(c.i*c.i));
		n.i=((i*c.r)-(r*c.i))/((c.r*c.r)+(c.i*c.i));
		return n;
	}

	void setR(double real) {
		r=real;
	}
	void setI(double img) {
		i=img;
	}

	double getR() {
		return r;
	}

	double getI() {
		return i;
	}

	friend ostream& operator<<(ostream& os, complex c);
	friend istream& operator>>(istream& is, complex c);
};

	ostream& operator<<(ostream& os, complex c) {
		if(c.i<0) {os<<c.r<<c.i<<"i"; return os;}
		os<<c.r<<"+"<<c.i<<"i";
		return os;
	}

	istream& operator>>(istream& is, complex c) {
		is>>c.r>>c.i;
		return is;
	}


int main() {
complex c(3,5), d(1,2), f(6,7);
complex r;
cout<<c<<endl;
c=c+d;
cout<<c<<endl;
complex g;
g=d*c;
cout<<g<<endl;
cout<<r<<endl;
r.setI(-1);
cout<<r<<endl;

return 0;
}
