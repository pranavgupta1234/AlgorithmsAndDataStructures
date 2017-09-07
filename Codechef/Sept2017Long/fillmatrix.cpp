#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <utility>

using namespace std;

// This function returns true if graph G[V][V] is Bipartite,
// else false
bool isBipartiteUtil(vector< set<int> >& G, int src, int colorArr[]){
	colorArr[src] = 1;

	queue <int> q;
	q.push(src);

   
	while (!q.empty()){
        
		int u = q.front();
		q.pop();

		
		for (set<int> :: iterator it = G[u].begin(); it != G[u].end() ; it++){
            
			if (colorArr[*it] == -1){
                
				colorArr[*it] = 1 - colorArr[u];
				q.push(*it);
			}
            
			else if (colorArr[*it] == colorArr[u]){
				return false;
			}
		}
	}

	return true;
}

// Returns true if G[][] is Bipartite, else false
bool isBipartite(vector<set<int> >& G,int V){


	int colorArr[V];
	for (int i = 0; i < V; ++i){
		colorArr[i] = -1;
	}

    // This code is to handle disconnected graoh
	for (int i = 0; i < V; i++){
		if (colorArr[i] == -1){
			if (isBipartiteUtil(G, i, colorArr) == false){
				return false;
			}
		}
	}

	return true;
}


int main(){

	int t;
	cin>>t;

	while(t--){

		int n,q;
		cin>>n>>q;

		bool ans = true;

		map<pair<int,int>,int> hash;
		vector< set<int> > graph(n,set<int>());
		map<pair<int,int>,int> :: iterator it;

		for(int i=0 ; i<q ; i++){

			int a,b,c;
			cin>>a>>b>>c;
			pair<int,int> p = make_pair(a,b);
			hash[p] = c;

		}

		for(it = hash.begin() ; it!= hash.end() ; it++){

			pair<int,int> temp = it -> first;

			if(temp.first == temp.second){
				if(hash[temp] != 0){
					ans = false;
					break;
				}
			}else{

				pair<int,int> rev_pair = make_pair(temp.second,temp.first);

				if(hash.find(rev_pair) != hash.end()){
					if(hash[rev_pair] != hash[temp]){
						ans = false;
						break;
					}
				}
			}
		}

		for(it = hash.begin() ; it != hash.end() ; it++){

			pair<int,int> p = it -> first;

			if(p.first != p.second){

				if(hash[p] != 0){

					//add to graph
					graph[p.first-1].insert(p.second-1);
					graph[p.second-1].insert(p.first-1);			

				}else{
					//merge nodes
					//unite two nodes 
					for(set<int> :: iterator it = graph[p.first-1].begin() ; it != graph[p.first-1].end() ; it++){
						graph[p.second - 1].insert(*it);
					}

					for(set<int> :: iterator it = graph[p.second - 1].begin() ; it != graph[p.second - 1].end() ; it++){
						graph[p.first - 1].insert(*it);
					}

				}	
			}
		}


		//for(int i=0 ; i<n ; i++){
		//	for(set<int> :: iterator it=graph[i].begin() ; it != graph[i].end() ; it++){
		//		cout<<*it<<" ";
		//	}
		//	cout<<endl;
		//}	 

		if(!isBipartite(graph,n)){
			ans = false;
		}

		cout<<(ans ? "yes" : "no");

		cout<<endl;
	}


	return 0;
}