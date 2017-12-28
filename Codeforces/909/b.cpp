#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	int dep[n];
	for(int i=0 ; i<n ; i++){
		dep[i] = 0;
	}
	int m = -1;;
	for(int i=1 ; i<=n ; i++){
		for(int j=0 ; j<i ; j++){
			for(int k=j ; k<i ; k++){
				dep[k]++;
				m = max(m,dep[k]);
			}
		}
	}

	cout<<m<<endl;

	return 0;
}