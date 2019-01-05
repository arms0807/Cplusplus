#include <iostream>
using namespace std;

// Counting Sort : Counting sort is a sorting technique based on keys between a specific range.
// It is not a comparison based sorting. 
// It is often used as a sub-routine to another sorting algorithm like radix sort.

// Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
// Auxiliary Space: O(n+k)

void countingsort(int *unsorted, int n){
	int *max = max_element(unsorted, unsorted+n), *min = min_element(unsorted, unsorted+n);
	int index[*max+1], sorted[n+1];
	for(int i=0;i<n;i++){
		index[unsorted[i]]++;
	}
	for(int i=1;i<*max+1;i++){
		index[i] = index[i-1]+index[i];
	}
	for(int i=0;i<n;i++){
		sorted[index[unsorted[i]]] = unsorted[i];
		index[unsorted[i]]--;
	}
	for(int i=1;i<n+1;i++)
		cout<<sorted[i]<<" ";
}

int main(){
	int unsorted[]{2,8,7,1,3,5,6,4};
	int n = sizeof(unsorted)/sizeof(unsorted[0]);
	countingsort(unsorted, n);
	return 0;
}