#include <iostream>
#include <vector>
using namespace std;

// insertionsort : Sorting starts from the second elements, which is the key. Compare the previous
// elements with the key element. If the pre is larger than the key, swap them.

// Time Complexity: Average(O(n^2)), Worst case(O(n^2)), Best case(O(n))

int main(){
	vector<int> unsorted{6,3,5,2,9,10,1,8,4,7};
	//vector<int> unsorted{6,3,5,2,1,10,1,7,7,7};
	int key, j;
	for(int i=1;i<unsorted.size();i++){
		key = unsorted[i];
		j = i-1;
		while(j>=0 && unsorted[j]>key){
			unsorted[i--] = unsorted[j];
			j--;
		}
		unsorted[j+1]= key;
	}
	for(int i:unsorted)
		cout<<i<<" ";
	return 0;
}