#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sale;
int n,f;
vector<pair<ll,ll> > opt;

int comp(pair<ll,ll> a,pair<ll,ll> b) { return (min(2*a.first,a.second)-min(a.first,a.second)) > min(2*b.first,b.second)-min(b.first,b.second); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>f;
	for(int i=0 ; i<n ; i++){
		int a,b;
		cin>>a>>b;
		if(a >= b)	sale += b;
		else opt.push_back(make_pair(a,b));
	}
	sort(opt.begin(),opt.end(),comp);
	int m = min(f,(int)opt.size());
	for(int i=0 ; i<m ; i++) sale += min(2*opt[i].first,opt[i].second);
	if(f < opt.size())	for(int i=f ; i<opt.size() ; i++) sale += min(opt[i].first,opt[i].second);
	cout<<sale<<endl;
	return 0;
}