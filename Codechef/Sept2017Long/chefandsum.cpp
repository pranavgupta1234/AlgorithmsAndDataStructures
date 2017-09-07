#include <iostream>
#include <vector>
 
using namespace std;
 
 
int main(){
 
	int t;
	cin>>t;
	while(t--){
		int n;
		//vector<int> arr;
		cin>>n;
		int temp;
		int minimum = 100000;
		int index;
		for(int i=0 ; i<n ; i++){
			cin>>temp;			
			//arr.push_back(temp);
			if(temp < minimum){
				index = i+1;
				minimum = temp;
			}
		}
		cout<<index<<endl;
	}
}