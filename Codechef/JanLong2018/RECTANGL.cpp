#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;
unordered_map<int,int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		cin>>a>>b>>c>>d;
		bool f = true;
		s[a]++,s[b]++,s[c]++,s[d]++;
		for(auto x : s){
			if(x.second % 2 != 0)	{ f = false ; break; }
		} 
		cout<<(f ? "YES" : "NO")<<endl;
		s.clear();
	}
	return 0;
}

