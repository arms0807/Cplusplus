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
		if(a[r]>=a[j]){
			i++;
			swap(a[j], a[i]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;
}

void QuickSort(int a[], int l, int r){
	int stack[r-l+1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = r;
	while(top >= 0){
		r = stack[top--];
		l = stack[top--];

		int q = partition(a, l, r);

		if(q-1>l){
			stack[++top] = l;
			stack[++top] = q-1;
		}
		if(q+1<r){
			stack[++top] = q+1;
			stack[++top] = r;
		}
	}
}

int main(){
	int a[]{2,8,7,1,10,9,34,2,1,3,3,6,5,1,3,5,6,4};
	int l=0, r=sizeof(a)/sizeof(a[0])-1;
	QuickSort(a,l,r);
	for(int i:a)
		cout<<i<<" ";
	return 0;
}
// void QuickSort(int a[], int l, int r){
// 	if(l<r){
// 		int q = partition(a, l, r);
// 		while(l<q-1){
// 			q = partition(a, l, q-1);
// 		}
// 		while(q+1<r){
// 			q = partition(a, q+1, r);
// 		}
// 	}
// }

