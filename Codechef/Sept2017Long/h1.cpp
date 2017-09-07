#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

		int n;
		cin>>n;
		map<int,int> hash;
		map<int,int> :: iterator it;
		int arr[n];
		bool flag = true;

		for(int i=0 ; i<n ; i++){
			hash[i+1] = 0;
		}

		for(int i=0 ; i<n ; i++){
			int temp;
			cin>>temp;
			arr[i] = temp;				
			if(temp < 1 or temp > n){
				flag = false;
				break;
			}else{
				hash[temp]++;
			}
		}

		for(it = hash.begin() ; it!=hash.end() ; it++){
			if(it -> second != 1){
				flag = false;
				break;
			}
		}

		if(is_sorted(&arr[0],&arr[n-1]){
			flag = false;	
		}

/*		for(int i=0 ; i<n ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

		for(it = hash.begin() ; it!=hash.end() ; it++){
			cout<<it->first<<" "<<it -> second<<endl;
		}

		cout<<endl;
*/
		cout<<(flag ? "Beautiful" : "Ugly");

		cout<<endl;
	}

	return 0;
}