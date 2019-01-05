#include <iostream>
using namespace std;

void countingsort(int unsorted[], int n, int exp){
	int index[10] = {0}, sorted[n];
	for(int i=0;i<n;i++){
		index[(unsorted[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++){
		index[i] = index[i-1]+index[i];
	}
	for(int i=n-1;i>=0;i--){
		sorted[index[(unsorted[i]/exp)%10]-1] = unsorted[i];
		index[(unsorted[i]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
		unsorted[i] = sorted[i];
}

void radixsort(int unsorted[], int n){
	int *m = max_element(unsorted, unsorted+n); // can't just use this function to get the maxium value
												// cuz after changing the index in the following for-loop
												// the maxium will change. So we need to initialize another
												// variable to store the maxium value.
	int max = *m;
	for(int exp=1;max/exp>0;exp*=10){
		countingsort(unsorted, n, exp);
	}
}

int main(){
	int unsorted[]{170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(unsorted)/sizeof(unsorted[0]);
	radixsort(unsorted, n);
	for(int i=0;i<n;i++)
		cout<<unsorted[i]<<" ";
	cout<<endl;
	return 0;
}