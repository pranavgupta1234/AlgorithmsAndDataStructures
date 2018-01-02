#include <bits/stdc++.h>

using namespace std;

int arr1[200010];
int arr2[200010];

void dfs(vector<int> graph[],int p,int s,int d,int *arr){
	arr[s] = d;
	for(int i=0 ; i<graph[s].size() ; i++){
		if(graph[s][i] != p){							//only this is enough
			dfs(graph,s,graph[s][i],d+1,arr);
		}
	}
}

int main(){
	int n,x;
	cin>>n>>x;
	vector<int> graph[n+1];
	int ans = -1;
	for(int i=0 ; i<n-1 ; i++){
		int s,d;
		cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);		
	}

	//no need of visited array for dfs on tree only check for child != parent 
	dfs(graph,0,1,0,arr1);
	dfs(graph,0,x,0,arr2);

	for(int i=1 ; i<=n ; i++){
		if(arr1[i] > arr2[i]){
			ans = max(ans,arr1[i]);
		}
	}

	cout<<2*ans<<endl;
	
	return 0;
}