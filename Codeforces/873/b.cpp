#include <bits/stdc++.h>

using namespace std;

char str[100005];

int main(){
	int n;
	cin>>n;
	int cnt1 = 0;
	int cnt0 = 0;
	int bal[n+1];
	int prev[n+1];
	memset(prev,-1,sizeof(prev[0])*(n+1));
	int m = 0;
	bal[0] = 0;
	for(int i=0 ; i<n ; i++){
		cin>>str[i];
		str[i] == '1' ? cnt1++ : cnt0++;
		bal[i+1] = cnt1-cnt0;
	}

	for(int i=0 ; i<=n ; i++){
		if(prev[i] != -1){
			m = max(m,i-prev[i]);
		}else{
			prev[i] = 
		}
	}

	for(int i=0 ; i<=n ; i++){
		cout<<bal[i];
	}
	cout<<endl;
	cout<<m<<endl;

	return 0;
}