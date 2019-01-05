#include "iostream"
using namespace std;

int BinarySearch(int a[], int n, int t){
	int l = 0;
	while(l<=n){
		int m = (n-l)/2+l;
		if(a[m]>t){
			n = m-1;
		}else if(a[m]<t){
			l = m+1;
		}else{ 
			return m;
		}
	}
	return -1;
}

int main(){
	int arr[]{1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<BinarySearch(arr, n, 3)<<endl;
	return 0;
}
