#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n;
vector<int> tree[100500];
int a[100500];
int dp[100500];

void dfs(int s,int p){
    dp[s] = a[s];
    int mx = 0;
    for(int i=0 ; i<tree[s].size() ; i++){
        if(tree[s][i] != p){
            dfs(tree[s][i],s);
            mx = max(mx,dp[tree[s][i]]); 
        }
    }
    dp[s] += mx;
}

int main(){
    cin>>n;
    int s,d;
    for(int i=2 ; i<=n ; i++) cin >> s >> d,tree[s].push_back(d),tree[d].push_back(s);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    dfs(1,0);
    cout<<dp[1]<<endl;
    return 0;
}