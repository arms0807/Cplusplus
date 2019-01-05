#include <iostream>
#include <vector>
using namespace std;

// BubbleSort : Compare two adjacent elements if the order is wrong

// Time Complexity: Average(O(n^2)), Worst case(O(n^2)), Best case(O(n))

vector<int> BubbleSort(vector<int> a, int n){
	if(n==1)	return a;
	bool swapped = 0;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i], a[i+1]);
			swapped=1;
		}
	}
	if(swapped==0)	return a;
	return BubbleSort(a, n-1);
}

int main(){
	//vector<int> unsorted{6,3,5,2,9,10,1,8,4,7}, sorted;
	//vector<int> unsorted{6,3,5,2,1,10,1,7,7,7}, sorted;
	vector<int> unsorted{1,2,3,4,5,6,7,8,9,10}, sorted;
	sorted = BubbleSort(unsorted, unsorted.size());
	for(int i:sorted)
		cout<<i<<" ";
	return 0;
}