#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int bfs(vector<int> g[],int n){
    vector<ll> dist(n+10,INT_MAX);
    vector<bool> vis(n+10,false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i=0 ; i<g[f].size() ; i++){
            if(!vis[g[f][i]]){
                vis[g[f][i]] = true;
                dist[g[f][i]] = dist[f] + 1;
                q.push(g[f][i]);
            }
        }
    }
    return dist[n];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> rail[n+10];
    vector<int> bus[n+10];
    vector<bool> pres(n+10,false);
    int s,d;
    for(int i=1 ; i<=m ; i++)   cin>>s>>d,rail[s].push_back(d),rail[d].push_back(s),pres[s]=true,pres[d]=true;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i != j and find(rail[i].begin(),rail[i].end(),j) == rail[i].end()){
                bus[i].push_back(j);
                bus[j].push_back(i);
            }
        }
    }
    int d1 = bfs(rail,n);
    int d2 = bfs(bus,n);
    if(max(d1,d2) == INT_MAX) cout<<-1<<endl;
    else cout<<max(d1,d2)<<endl;
    return 0;
}