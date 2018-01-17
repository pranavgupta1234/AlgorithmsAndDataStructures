#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

ll m,n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	(n>=30 ? cout<<m : cout<<m%(ll)pow(2,n))<<endl;
	return 0;
}