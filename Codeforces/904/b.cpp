#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int res = 1;
	int parent[n+1];
	int color[n+1];
	for(int i=2 ; i<=n ; i++){
		//parent[i] is parent of i
		cin>>parent[i];
	}
	for(int i=1 ; i<=n ; i++){
		cin>>color[i];
	}

	for(int i=2 ; i<=n ; i++){
		if(color[i] != color[parent[i]]){
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}