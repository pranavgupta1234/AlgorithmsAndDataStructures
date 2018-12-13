#include <bits/stdc++.h>

using namespace std;

vector<int> g[100100];
vector<bool> vis(100100,false);
vector<int> col(100100,0);

void dfs(int s){
    col[s] = 1;
    for(auto i : g[s]){
        if(col[i] == 0){
            dfs(i);
        }else if(col[i] == 1){
               
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
    }

    dfs(1);



    return 0;
}