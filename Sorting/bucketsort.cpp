#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Bucketsort is like Countingsort which has a requirement, the input consists of integers in a small range.
// The range of the input of Bucketsort is from 0 to 1, not included.
// Worst-case performance : O(n^2)
// Best-case performance : Omega (n+k)
// Average performance : Theta (n+k)
// Worst-case space complexity : O(n dot k)

void Bucketsort(float a[], int n){
	vector<float> Bucket[n];
	for(int i=0;i<n;i++){
		Bucket[int(a[i]*n)].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		sort(Bucket[i].begin(), Bucket[i].end());
	}
	int index = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<Bucket[i].size();j++)
			a[index++] = Bucket[i][j];
}

int main(){
	float unsorted[]{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	int n = sizeof(unsorted)/sizeof(unsorted[0]);
	Bucketsort(unsorted, n);
	for(int i=0;i<n;i++)
		cout<<unsorted[i]<<" ";
	cout<<endl;
	return 0;
}