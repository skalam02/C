#include <iostream>
#include <cstdlib>
using namespace std;

//Creates a stack class and manipulates it

class  stack {

	int top; //index into array
	int *p; //p is pointer into the heap where the stack is
	int size;//size of the array

	public:

	stack() {
	top=-1;
	size=100;
	p=new int[size];
	}

	stack(int n) {
	top=-1;
	size=n;
	p=new int[n];
	}

	~stack() {
		delete []p;
	}

	bool empty() {
		return (top==-1);
	}

	void push(int x) {
		if (top==size-1) {cout<<"Stack is full"<<endl;exit(1);}
		p[++top]=x;
	}

	int pop() {
		if (empty()) {cout<<"stack is empty"<<endl;exit(1);}
		int temp=p[top--];
		return temp;
	}

};

int main()  {

stack s(10);
s.push(1);
s.push(2);
s.push(3);
for(int i=0;i<3;i++)
	cout<<s.pop()<<endl;

return 0;

}
