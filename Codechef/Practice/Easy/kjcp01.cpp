#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class number{

	int data;
	int count;
	int index;

	number();

	number(int data,int count,int index){
		data = data;
		count = count;
		index = index;
	}

	bool operator < (number a,number b){

		if(a.count == b.count){
			return a.index < index;
		}else{
			return a.index < b.index;
		}
	}

};

int main(){
	
	int t;
	cin>>t;

	while(t--){

		int n;
		int m;
		cin>>n>>m;
		vector<number> nums(n,0);

		for(int i=0 ; i<n ; i++){
			int temp;
			cin>>temp;
		}

		sort(nums.begin(),nums.end());

		cout<<endl;

	}

	return 0;
}