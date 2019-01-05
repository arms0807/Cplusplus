#include <iostream>
#include <vector>
using namespace std;

// BubbleSort : Compare two adjacent elements if the order is wrong

// Time Complexity: Average(O(n^2)), Worst case(O(n^2)), Best case(O(n))

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	vector<int> unsorted{6,3,5,2,9,10,1,8,4,7};
	//vector<int> unsorted{6,3,5,2,1,10,1,7,7,7};
	int key, j;
	bool swapped = 0; 
	for(int i=0;i<unsorted.size();i++){
		for (int j = i+1; j < unsorted.size(); j++){
			if(unsorted[i]>unsorted[j]){
				swap(unsorted[i], unsorted[j]);
				swapped=1;
			}
		}
		if(swapped == 0)
			break;
	}
	for(int i:unsorted)
		cout<<i<<" ";
	return 0;
}