/*
Stylianos Kalamaras 
CSCI 377 HW 1
Professor Jinwoo Kim
02/21/17

This program calculates/compares execution time for two sorting algorithms (merge sort, insertion sort) against three input sizes(10,100,1000) for efficiency. The results show that merge sort is much more efficient than insertion sort as the input grows.

***Implementation of merge-sort is from online sources and implementation of the insertion sort is textbook derived***
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int ten=10;
const int hundred = 100;
const int thousand = 1000;

void merge(int* input, int p, int r) {
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;
    // Temp array
    int temp[r-p+1];

    // Merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= r )
        if ( input[i2] < input[i3] )
            temp[i1++] = input[i2++];
        else
            temp[i1++] = input[i3++];

    // Merge the remaining elements in left array
    while ( i2 <= mid )
        temp[i1++] = input[i2++];

    // Merge the remaining elements in right array
    while ( i3 <= r )
        temp[i1++] = input[i3++];

    // Move from temp array to master array
    for ( int i = p; i <= r; i++ )
        input[i] = temp[i-p];
}//merge

void merge_sort(int* input, int p, int r) {
    if ( p < r ) {
        int mid = floor((p + r) / 2);
        merge_sort(input, p, mid);
        merge_sort(input, mid + 1, r);
        merge(input, p, r);
    }//if
}//merge sort

void fill_array(int* a, int size) {
	int sub=size;	
	for(int i=0;i<size;i++)
		a[i]=sub--;
}

void insertion_sort(int* a, int size) {
    for (int j=1;j<size;j++) {
	int key=a[j];
	int back=j-1;	
	while (a[back]>key) { //removed i>0
		a[back+1]=a[back];
		back=back-1;
	}//while
	a[back+1]=key;
    }//for
}//insertion sort

int main() {	
    clock_t start,end;
    //element count
    
    //arrays to store elements to be sorted
    int input[ten];
    int input1[hundred];
    int *thou = new int[thousand];

    //fill elements into array in reverse order, worst case
    fill_array(input,ten);  
    fill_array(input1,hundred);
    fill_array(thou,thousand);
   
    int timer[6];

    //times mergesort(10)
    start=clock();
    merge_sort(input, 0, 9);
    end = clock();
    timer[0]=end-start/CLOCKS_PER_SEC;
   
    //times mergesort(100)
    start=clock();
    merge_sort(input1, 0, 99);
    end = clock();
    timer[1]=end-start/CLOCKS_PER_SEC;
 
    //times mergesort(1000)
    start=clock();
    merge_sort(thou, 0, 999);
    end = clock();
    timer[2]=end-start/CLOCKS_PER_SEC;
    
    
    //refills elements in array worst case
    fill_array(input,ten);  
    fill_array(input1,hundred);
    fill_array(thou,thousand);
    
    //times insertion sort(10)
    start = clock();
    insertion_sort(input,ten);
    end = clock();
    timer[3]=end-start/CLOCKS_PER_SEC;
    
    //times insertion sort(100)
    start=clock();
    insertion_sort(input1,hundred);
    end = clock();
    timer[4] = end-start/CLOCKS_PER_SEC;

    //times insertion sort(1000)
    start=clock();
    insertion_sort(thou,thousand);
    end=clock();
    timer[5]=end-start/CLOCKS_PER_SEC;
    
    cout<<"Input Size\tMerge Sort(ms)\tInsertion Sort(ms)\n";
    cout<<"10\t\t"<<timer[0]<<"\t\t"<<timer[3]<<"\n"<<"100\t\t"<<timer[1]<<"\t\t"<<timer[4]<<"\n"<<"1000\t\t"<<timer[2]<<"\t\t"<<timer[5]<<"\n";
    delete []thou;
    
    
    return 0;
}

