#include <iostream>
#include <vector>
using namespace std;

// insertionsort : Sorting starts from the second elements, which is the key. Compare the previous
// elements with the key element. If the pre is larger than the key, swap them.

// Time Complexity: Average(O(n^2)), Worst case(O(n^2)), Best case(O(n))

vector<int> InsertionSort(vector<int> a, int n){
	if(n==a.size()) return a;
	int key = a[n];
	int i=n-1;
	while(i>=0 && key<a[i]){
		a[n--] = a[i];
		i--;
	}
	a[i+1] = key;
	return InsertionSort(a, n+1);
}

int main(){
	//vector<int> unsorted{6,3,5,2,9,10,1,8,4,7}, sorted;
	vector<int> unsorted{6,3,5,2,1,10,1,7,7,7}, sorted;
	sorted = InsertionSort(unsorted, 1);
	for(int i:sorted)
		cout<<i<<" ";
	return 0;
}