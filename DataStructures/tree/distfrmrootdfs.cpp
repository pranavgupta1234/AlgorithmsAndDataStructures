#include <bits/stdc++.h>

using namespace std;

int n;
int dist[100000];
vector<int> tree[100000];

void dfs(int s,int p,int d){
    dist[s] = d;
    for(int i=0 ; i<tree[s].size() ; i++){
        if(tree[s][i] != p){
            dfs(tree[s][i],s,d+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1 ; i<=n-1 ; i++){
        int s,d;
        cin>>s>>d;
        tree[s].push_back(d);
        tree[d].push_back(s);
    }

    dfs(1,1,0);
    for(int i=1 ; i<=n ; i++) cout<<dist[i]<<" ";
    cout<<endl;
}
