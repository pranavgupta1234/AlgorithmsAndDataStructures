#include <bits/stdc++.h>

using namespace std;

int n;
int parent[1100];
int deg[1100];
int sons[1100];

int main(){
	cin>>n;
	for(int i=1 ; i<n ; i++) { cin>>parent[i+1]; deg[parent[i+1]]++; }
	for(int i=0 ; i<n ; i++) if(deg[i+1] == 0)	sons[parent[i+1]]++;
	for(int i=0 ; i<n ; i++) if(deg[i+1] > 0 and sons[i+1] < 3) { cout<<"No"<<endl; return 0; }
	cout<<"Yes"<<endl;
}
