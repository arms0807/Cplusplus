#include <iostream>
#include <vector>
using namespace std;

//MergeSort : It's a divide and conquer algorithms. It divides input into two halves. After conquering,
//then merge() function will merge the two halves into one output.

// Time Complexity: Average(O(nlogn)), Worst case(O(nlogn)), Best case(O(nlogn))

void merge(vector<int> &a, int l, int m, int r){
	int n1 = m - l + 1; 
    int n2 =  r - m; 
	int L[n1], R[n2];
	int i, j, k;
	for(i=0;i<n1;i++)
		L[i] = a[i+l];
	for(j=0;j<n2;j++)
		R[j] = a[j+m+1];
	i = 0; j = 0; k = l;
	while(i<n1 && j<n2){
		if(L[i]>R[j]){
			a[k] = R[j];
			j++;
		}else{
			a[k] = L[i];
			i++;
		}
		k++;
	}
	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr, int n) 
{ 
   int curr_size;  // For current size of subarrays to be merged 
                   // curr_size varies from 1 to n/2 
   int left_start; // For picking starting index of left subarray 
                   // to be merged 
  
   // Merge subarrays in bottom up manner.  First merge subarrays of 
   // size 1 to create sorted subarrays of size 2, then merge subarrays 
   // of size 2 to create sorted subarrays of size 4, and so on. 
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) 
   { 
       // Pick starting point of different subarrays of current size 
       for (left_start=0; left_start<n-1; left_start += 2*curr_size) 
       { 
           // Find ending point of left subarray. mid+1 is starting  
           // point of right 
           int mid = left_start + curr_size - 1; 
  
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
           merge(arr, left_start, mid, right_end); 
       } 
   } 
}

int main(){
	vector<int> unsorted{6,3,5,2,9,10,1,8,4,7};
	int n = unsorted.size();
	mergeSort(unsorted, n);
	for(auto i:unsorted)
		cout<<i<<" ";
	return 0;
}