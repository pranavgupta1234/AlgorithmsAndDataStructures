#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>

using namespace std;

class compare{
public:
	bool operator() (pair<int,int> a,pair<int,int> b){
		return a.second > b.second;
	}
};

int dijkstra(vector<vector<pair<int,int> > >& graph,int source,int dest){

	priority_queue<pair<int,int>, vector<pair<int,int> >,compare >  q;
	int n = graph.size();
	int distance[n];
	for(int i=0 ; i<n ; i++){
		distance[i] = INT_MAX;
	}
	distance[source] = 0;
	q.push(make_pair(source,0));
	while(!q.empty()){
		int v = q.top().first;
		q.pop();
		for(int i=0 ; i<graph[v].size() ; i++){
			int nd = graph[v][i].first;
			int wt = graph[v][i].second;
			if(distance[nd] > distance[v] + wt){
				distance[nd] = distance[v] + wt;
				q.push(make_pair(nd,distance[nd]));
			}
		}
	}
	if(distance[dest] != INT_MAX){
		return distance[dest];
	}else{
		return -1;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,s,d;
		cin>>n>>m>>s>>d;
		vector<vector<pair<int,int> > > graph(n+1);
		for(int i=0 ; i<m ; i++){
			int a,b,w;
			cin>>a>>b>>w;
			graph[a].push_back(make_pair(b,w));
			graph[b].push_back(make_pair(a,w));
		}
		int mindist = dijkstra(graph,s,d);
		if(mindist != -1){
			cout<<mindist<<endl;
		}else{
			cout<<"NONE"<<endl;
		}
	}
	return 0;
}