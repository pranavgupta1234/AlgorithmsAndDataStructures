#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int disconnectedComponentsUtil(unordered_map<int,vector<int> >& graph,unordered_map<int,bool>& visited,int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		//cout<<f<<" ";
		for(auto it = graph[f].begin() ; it != graph[f].end() ; it++){
			if(!visited[*it]){
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
}

int disconnectedComponents(unordered_map<int,vector<int> >& graph,int V){

	unordered_map<int,bool> visited;
	int components = 0;

	for(auto it = graph.begin() ; it != graph.end() ; it++){
		visited[it->first] = false;
	}

	for(auto it=graph.begin() ; it != graph.end() ; it++){
		if(!visited[it -> first]){
			disconnectedComponentsUtil(graph,visited,it->first);
			components++;
		}
	}

	return components;
}

int noOfIslands(int** mat,int n,int m){

	unordered_map<int,vector<int> > graph;
	int singleton = 0;
	int V=0;

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(mat[i][j] == 1){
				V++;
				bool flag = true;
				int vertex = i*n + j;
				if(i>=1 and j>=1 and mat[i-1][j-1] == 1){
					graph[vertex].push_back((i-1)*n + j-1);
					flag = false;					
				}
				if(i>=1 and mat[i-1][j] == 1){
					graph[vertex].push_back((i-1)*n + j);
					flag = false;
				}
				if(i>=1 and j+1 < m and mat[i-1][j+1] == 1){
					graph[vertex].push_back((i-1)*n + j+1);
					flag = false;
				}
				if(j>=1 and mat[i][j-1] == 1){
					graph[vertex].push_back((i)*n + j-1);
					flag = false;
				}
				if(j+1 < m and mat[i][j+1] == 1){
					graph[vertex].push_back((i)*n + j+1);
					flag = false;
				}
				if(j>=1 and i+1 < n and mat[i+1][j-1] == 1){
					graph[vertex].push_back((i+1)*n + j-1);
					flag = false;
				}
				if(i+1 < n and mat[i+1][j] == 1){
					graph[vertex].push_back((i+1)*n + j);
					flag = false;
				}
				if(i+1 < n and j+1 < m and mat[i+1][j+1] == 1){
					graph[vertex].push_back((i+1)*n + j+1);
					flag = false;
				}
				if(flag == true){
					//graph[vertex].push_back(-1);
					singleton++;
				}
			}
		}
	}

	return disconnectedComponents(graph,V-singleton)+singleton;

	//for(auto it = graph.begin() ; it != graph.end() ; it++){
	//	int v = it -> first;
	//	vector<int> vec = it -> second;
	//	cout<<v<<" :: "<<endl;
	//	for(int k=0 ; k<vec.size() ; k++){
	//		cout<<vec[k]<<" ";
	//	}
	//	cout<<endl;
	//}

}

int main(){
	
	int n,m;
	cin>>n>>m;

	int** mat = (int**)malloc(n*sizeof(int*));

	for(int i=0 ; i<n ; i++){
		mat[i] = new int[m];
	}

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			cin>>mat[i][j];
		}
	}

	cout<<noOfIslands(mat,n,m)<<endl;

	return 0;
}