#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){

		bool nums[200002];
		memset(nums,false,200002);
		int n,k;
		cin>>n>>k;
		int index;

		for(int i=0 ; i<n ; i++){
			int temp;
			cin>>temp;
			nums[temp] = true;
		}

		if(k==0){
			for(int i=0 ; i<=200000 ; i++){
				if(nums[i] == false){
					index = i;
					break;
				}
			}
		}else{
			for(int i=0 ; i<=200000 ; i++){
				if(nums[i] == false){
					if(k==0){
						index = i;
						break;
					}
					k--;
				}
			}
		}
		cout<<index<<endl;
	}
}