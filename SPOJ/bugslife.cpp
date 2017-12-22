#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

//for each disconnected component
bool bfsUtil(vector<vector<int> >& graph,int* color,int source){
	queue<int> q;
	q.push(source);
	color[source] = 0;
	while(!q.empty()){
		int vis = q.front();
		q.pop();
		for(int j=0 ; j<graph[vis].size() ; j++){
			if(color[graph[vis][j]] == -1){
				color[graph[vis][j]] = 1 - color[vis];
				q.push(graph[vis][j]);
			}else{
				if(color[graph[vis][j]] == color[vis]){
					return false;
				}
			}
		}
	}
	return true;
}

bool disconnectedBipartite(vector<vector<int> >& graph){
	bool isBipartite = true;

	int nodes = graph.size();						// this includes +1 to maintain 1 based indexing 
	int color[nodes];

	memset(color,-1,sizeof(color[0])*nodes);

	for(int i=1 ; i<=nodes-1 ; i++){
		if(color[i] == -1){
			isBipartite = isBipartite and bfsUtil(graph,color,i);
		}
	}
	return isBipartite;
}

int main(){

	int t;
	cin>>t;
	int c = 1;
	while(c<=t){
		int n,m;
		cin>>n>>m;
		vector<vector<int> > graph(n+1);
		for(int i=0 ; i<m ; i++){
			int s,d;
			cin>>s>>d;
			graph[s].push_back(d);
			graph[d].push_back(s);
		}

		bool ans = disconnectedBipartite(graph);

		if(ans){
			cout<<"Scenario #"<<c<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}else{
			cout<<"Scenario #"<<c<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
		c++;
	}

	return 0;
}