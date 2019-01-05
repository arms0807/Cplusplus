#include "iostream"
#include "vector"
using namespace std;

//MergeSort : It's a divide and conquer algorithms. It divides input into two halves. After conquering,
//then merge() function will merge the two halves into one output.

// Time Complexity: Average(O(nlogn)), Worst case(O(nlogn)), Best case(O(nlogn))

void merge(vector<int> &a, int l, int m, int r){
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
	int a1[n1], a2[n2];
	for(i=0;i<n1;i++)
		a1[i] = a[l+i];
	for(j=0;j<n2;j++)
		a2[j] = a[m+j+1];

	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(a1[i]<=a2[j]){
			a[k] = a1[i];
			i++;
		}else{
			a[k] = a2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k] = a1[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = a2[j];
		j++;
		k++;
	}
}

void MergeSort(vector<int> &a, int l, int r){
	if(l<r){
		int m=l+(r-l)/2; // same as (l+r)/2, but in this way it might get overflow if the l and r is too large
		MergeSort(a, l, m);
		MergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main(){
	vector<int> unsorted{6,3,5,2,9,10,1,8,4,7};
	//vector<int> unsorted{6,3,5,2,1,10,1,7,7,7};
	int l = 0, r = unsorted.size()-1;
	MergeSort(unsorted, l, r);
	for(int i:unsorted)
		cout<<i<<" ";
	return 0;
}