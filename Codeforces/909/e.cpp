#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n,m;
int type[100100];
vector<int> graph[101000];
bool visited[101000];
vector<int> topos;
int s,d;

void dfsUtil(int s){
	visited[s] = true;
	for(int i=0 ; i<graph[s].size() ; i++){
		if(!visited[graph[s][i]]){
			dfsUtil(graph[s][i]);
		}
	}
	topos.push_back(s);
}

void dfs(){
	for(int i=0 ; i<n ; i++){
		visited[i] = false;
	}

	for(int i=0; i<n ; i++){
		if(!visited[i]){
			dfsUtil(i);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0 ; i<n ; i++)		cin>>type[i];
	for(int i=0 ; i<m ; i++)		cin>>s>>d ,	graph[s].push_back(d);

	dfs();

	for(int i=0; i<topos.size() ; i++){
		topos[i] = type[topos[i]];
	}	

	int i = 0;
	ll ans = 0;
	while(i<topos.size()){
		while(topos[i] == 1){
			i++;
		}
		ans++;
		i++;	
	}

	cout<<ans<<endl;
	return 0;
}	