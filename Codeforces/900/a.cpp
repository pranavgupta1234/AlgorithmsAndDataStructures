#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int left = 0;
	int right = 0;
	for(int i=0 ; i<n ; i++){
		int x,y;
		cin>>x>>y;
		if(x < 0){
			left++;
		}
		if(x > 0){
			right++;
		}
	}

	if(left - 1 == 0 or right - 1 == 0){
		cout<<"Yes"<<endl;
	}else if(left == 0 or right == 0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}