#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define endl "\n"
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,rating;
		cin>>n;
		cin>>rating;
		vector<int> query(n,0);
		int upper_cut = 0;
		int lower_cut = 0;
		bool flag = true;
		for(int i=0 ; i<n ; i++){
			cin>>query[i];
			upper_cut = max(upper_cut,query[i]);
		}
		for(int i=0 ; i<n-1 ; i++){
			if(query[i] > rating){
				upper_cut = query[i];
				if(query[i+1] > query[i] or query[i+1] < lower_cut){
					flag = false;
					break;
				}
			}
			if(query[i] < rating){
				lower_cut = query[i];
				if(query[i+1] < query[i] or query[i+1] > upper_cut){
					flag = false;
					break;
				}
			}	
		}
		cout<<(flag ? "YES" : "NO")<<endl;
	}

	return 0;
}