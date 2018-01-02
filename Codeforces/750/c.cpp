#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > res;

	for(int i=0 ; i<n ; i++){
		int c,d;
		cin>>c>>d;
		res.push_back(make_pair(c,d));
	}

	int upbound = INT_MAX;
	int lobound = -INT_MAX;
	res[0].second == 1 ? lobound = 1900 : upbound = 1899;
	for(int i=1 ; i<n ; i++){
		if(res[i].second == 1){
			lobound = 1900;
		}else{
			upbound = 1899;
		}
	}


	return 0;
}