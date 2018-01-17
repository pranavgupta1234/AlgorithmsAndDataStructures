#include <bits/stdc++.h>
using namespace std;
int n,k;
int narr[250];
int karr[250];
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0 ; i<n ; i++)	cin>>narr[i];
	for(int i=0 ; i<k ; i++)	cin>>karr[i];

	if(k >= 2)	{ cout<<"Yes"<<endl; return 0 ; }
	else for(int i=0 ; i<n ; i++) if(narr[i] == 0) narr[i] = karr[0];
	bool f = true;
	for(int i=0 ; i<n-1 ; i++) if(narr[i+1] - narr[i] < 0) { cout<<"Yes"<<endl; f = false; break; }
	if(f) cout<<"No"<<endl;
	return 0;
}