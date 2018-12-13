#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m,k,sum = 0, each, ks = 1;
ll s = 0;
ll total;
vector<vector<int> > mat(1100,vector<int>(1100,0));
vector<vector<int> > ans(1100,vector<int>(1100,0));
vector<vector<bool> > vis(1100,vector<bool>(1100,false));

void dfs(int i,int j){
    if(s >= each or total == k-ks) {
        ks++;
        s = 0;
    }
    s += mat[i][j];
    ans[i][j] = ks;
    vis[i][j] = true;
    total--;
    if(i+1 <= n and !vis[i+1][j]) dfs(i+1,j);
    if(j+1 <= m and !vis[i][j+1]) dfs(i,j+1);
    if(i-1 >= 1 and !vis[i-1][j]) dfs(i-1,j);
    if(j-1 >= 1 and !vis[i][j-1]) dfs(i,j-1);

    if(i+1 <= n and j+1 <=m and !vis[i+1][j+1]) dfs(i+1,j+1);
    if(i+1 <= n and j-1 >=1 and !vis[i+1][j-1]) dfs(i+1,j-1);
    if(i-1 >= 1 and j-1 >=1 and !vis[i-1][j-1]) dfs(i-1,j-1);
    if(i-1 >= 1 and j+1 <=m and !vis[i-1][j+1]) dfs(i-1,j+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) cin>>mat[i][j], sum += mat[i][j];
    each = sum/k;
    total = n*m;
    dfs(1,1);

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}