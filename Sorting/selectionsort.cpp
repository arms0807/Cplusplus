#include <iostream>
#include <vector>
using namespace std;

//selectionsort : find the minimum elements from an unsorted array and put it into the sorted array.
// Used index as the reference of smallest element and swap them in the end of for loop. 

// Time Complexity: Average(O(n^2)), Worst case(O(n^2)), Best case(O(n^2))

int main(){
	vector<int> unsorted{6,3,5,2,9,10,1,8,4,7};
	//vector<int> unsorted{6,3,5,2,1,10,1,7,7,7};
	int temp;
	for(int i=0;i<unsorted.size();i++){
		int min = i;
		for(int j=i+1;j<unsorted.size();j++){
			if(unsorted[j]<unsorted[min])
				min=j;
		}
		temp = unsorted[min];
		unsorted[min] = unsorted[i];
		unsorted[i] = temp;
	}
	for(int i:unsorted)
		cout<<i<<" ";
	return 0;
}