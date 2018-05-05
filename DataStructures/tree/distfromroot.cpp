#include <bits/stdc++.h>

using namespace std;

int n;
int dist[100000];
vector<int> tree[100000];
bool visited[100000];

void bfs(int s){
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0 ; i<tree[p].size() ; i++){
            if(!visited[tree[p][i]]){
                q.push(tree[p][i]);
                visited[tree[p][i]] = true;
                dist[tree[p][i]] = dist[p] + 1;
            }
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
    memset(visited,false,sizeof(visited));
    bfs(1);
    for(int i=1 ; i<=n ; i++) cout<<dist[i]<<" ";
    cout<<endl;
}
