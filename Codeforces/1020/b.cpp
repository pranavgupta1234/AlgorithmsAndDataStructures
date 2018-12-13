#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[1100];
vector<int> color(1100,0);

void dfs(int u,int& cs){
    color[u] = 1;
    for(auto i : g[u]){
        if(color[i] == 0){
            dfs(i,cs);
        }else if(color[i] == 1){
            cs = i;
            return;
        }
    }
    color[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;

    for(int i=1 ; i<=n ; i++){
        int d;
        cin>>d;
        g[i].push_back(d);
    }   

    for(int i=1 ; i<=n ; i++){
        int ans;
        color.assign(1100,0);
        dfs(i,ans);
        cout<<ans<<" ";
    }

    cout<<endl;
    
    return 0;
}