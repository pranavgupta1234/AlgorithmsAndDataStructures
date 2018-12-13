#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> g[200100];
vector<bool> vis(200100,false);
vector<int> rel(200100,0);
vector<int> res;

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        res.push_back(v);
        q.pop();
        for(auto i : g[v]){
            if(!vis[i]){
                q.push(i);
                vis[v] = true;
            }
        }
    }
}

bool comp(int a, int b){
    return rel[a] < rel[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1 ; i<n ; i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }

    vector<int> trav(n,0);

    for(int i=0 ; i<n ; i++) {
        cin>>trav[i];
        rel[trav[i]] = i;
    }
    for(int i=0 ; i<=n ; i++){
        sort(g[i].begin(),g[i].end(),comp);
    }
    bfs(1);
    for(int i=0 ; i<n ; i++){
        if(trav[i] != res[i]){
            cout<<"No"<<endl;
            exit(0);
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}