#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

#define ll long long

using namespace std;

int main(){

	int n,m;
	cin>>n>>m;	
	ll dist[n+1][n+1];
	vector<vector<int > > graph(n+1,vector<int>(0));
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(i==j){
				dist[i][j] = 0;
			}else{
				dist[i][j] = INT_MAX;//put this a large value but not be careful with INT_MAX as adding even
			}						//1 to it will come out of range 			
		}
	}

	for(int i=0 ; i<m ; i++){
		int s,d,w;
		cin>>s>>d>>w;;
		graph[s].push_back(d);
		dist[s][d] = w;
	}

	for(int k=1 ; k<=n ; k++){
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					//cout<<dist[i][j]<<endl;
				}
			}
		}
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(dist[i][j] == INT_MAX){
				cout<<"X"<<" ";
			}else{
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}
