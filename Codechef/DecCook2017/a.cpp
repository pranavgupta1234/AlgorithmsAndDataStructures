#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		unordered_map<string,int> m;
		for(int i=0 ; i<n ; i++){
			string team;
			cin>>team;
			m[team]++;
		}
		string t1;
		string t2;
		int k = 0;
		for(auto it = m.begin() ; it != m.end() ; it++){
			if(k==0){
				t1 = it -> first;
			}else{
				t2 = it -> first;
			}
			k++;
		}

		if(m[t1] > m[t2]){
			cout<<t1<<endl;
		}else if(m[t1] < m[t2]){
			cout<<t2<<endl;
		}else{
			cout<<"Draw"<<endl;
		}
	}	

	return 0;
}