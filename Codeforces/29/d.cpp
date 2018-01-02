#include <bits/stdc++.h>

using namespace std;

int n;
int leaves = 0;
vector<int> graph[310];
int leaf[310];
vector<int> euler;

bool dfs(int s,int dest,int p){
	if(s == dest) { return true ;}
	for(int i=0 ; i<graph[s].size() ; i++){
		if(graph[s][i] != p and dfs(graph[s][i],dest,s)){
			euler.push_back(s);
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0 ; i<n-1 ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}

	for(int i=2 ; i<=n ; i++)	if(graph[i].size() == 1) 	leaves++;
	for(int i=0 ; i<leaves ; i++) 	cin>>leaf[i];

	euler.push_back(1);
	int prev = 1;
	for(int i=0 ; i<leaves ; i++){
		dfs(leaf[i],prev,0);
		prev = leaf[i];
	}

	dfs(1,leaf[leaves-1],0);
	//cout<<euler.size()<<endl;
	if(euler.size() != 2*n-1){
		cout<<"-1";
	}else{
		for(int i=0 ; i<euler.size() ; i++) 	cout<<euler[i]<<" ";
	}	
	
	cout<<endl;

	return 0;
}

