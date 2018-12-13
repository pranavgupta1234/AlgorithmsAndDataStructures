#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll,vector<ll> > g;
ll val[100100];
map<ll,bool> vis;
map<ll,ll> m;
vector<deque<ll> >ans; 

void dfs(ll u,ll& cnt,deque<ll>& a){
    vis[u] = true;
    cnt++;
    a.push_back(m[u]);
    for(auto i : g[u]){
        if(!vis[i]){
            dfs(i,cnt,a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin>>n;
    vector<ll> cpy(n+1,0);
    for(int i=1 ; i<=n ; i++) cin>>val[i],cpy[i] = val[i],m[val[i]] = i;
    sort(cpy.begin()+1,cpy.end());
    for(int i=1 ; i<=n ; i++){
        g[val[i]].push_back(cpy[i]);
    }
    for(int i=1 ; i<=n ; i++) vis[val[i]] = false;
    for(int i=1 ; i<=n ; i++){
        if(!vis[val[i]]){
            ll cnt = 0;
            deque<ll> a;
            dfs(val[i],cnt,a);
            a.push_front(cnt);
            ans.push_back(a);
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}