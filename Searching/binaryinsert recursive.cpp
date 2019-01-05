#include <iostream>
#include <vector>
using namespace std;

void Binaryinsert(vector<int> temp, int l, int r, vector<int> &temp2){
        if(l>r || r<0) return;
        int mid = l+(r-l)/2;
        temp2.push_back(temp[mid]);
        Binaryinsert(temp, l, mid-1, temp2);
        Binaryinsert(temp, mid+1, r, temp2);
        return;
    }

int main(){
	vector<int> temp{1,2,3,4,5};
    int l = 0, r = temp.size()-1, mid;
    vector<int> temp2;
    Binaryinsert(temp, l, r, temp2);
    for(auto i=temp2.begin();i!=temp2.end();i++)
     	cout<<*i<<" ";
	return 0;
}