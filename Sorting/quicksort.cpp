#include <iostream>
using namespace std;

// QuickSort is doing in divide and conquer algorithm
// QuickSort : Has a pivot, which sometimes is the last or first element of the array.
// The key process in quickSort is partition(). Target of partitions is put x at its correct 
// position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x.

// Time Complexity: Average(O(nlogn)), Worst case(O(n^2)), Best case(O(nlogn))

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l-1;
	for(int j=l;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void QuickSort(int a[], int l, int r){
	if(l<r){
		int q = partition(a, l, r);
		QuickSort(a, l, q-1);
		QuickSort(a, q+1, r);
	}
}

int main(){
	int a[]{2,8,7,1,3,5,6,4};
	int l=0, r=sizeof(a)/sizeof(a[0])-1;
	QuickSort(a,l,r);
	for(int i:a)
		cout<<i<<" ";
	return 0;
}