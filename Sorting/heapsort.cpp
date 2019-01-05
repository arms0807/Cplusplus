#include <iostream>
using namespace std;

// HeapSort : Based on binary heap data structure. It is similar to 
// selection sort where we first find the maximum element and place the maximum element at the end.

// Time Complexity: heapify is O(Logn), createAndBuildHeap() is O(n)

// Time Complexity: Average(O(nlogn)), Worst case(O(nlogn)), Best case(O(nlogn))

int Left(int index){
	return index*2+1;
}

int Right(int index){
	return index*2+2;
}

void Maxheapify(int a[], int index, int n){
	int largest = index;
	int l = Left(index);
	int r = Right(index);

	if(l<n && a[l] > a[largest]){
		largest = l;
	}
	if(r<n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != index){
		swap(a[index], a[largest]);
		Maxheapify(a, largest, n);
	}
}

void HeapSort(int a[], int n){
	for(int i=n/2-1;i>=0;i--)
		Maxheapify(a, i, n);
	for(int i=n-1;i>=0;i--){
		swap(a[i], a[0]);
		Maxheapify(a, 0, i);
	}
}

int main(){
	int unsorted[]{6,3,5,2,9,10,1,8,4,7};
	//int unsorted[]{6,3,5,2,1,10,1,7,7,7};
	int n = sizeof(unsorted)/sizeof(unsorted[0]);
	HeapSort(unsorted, n);
	for(int i:unsorted)
		cout<<i<<" ";
	return 0;
}