#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m,r,x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>r>>x>>y;
    vector<ll> d(n+10,INT_MAX);
    vector<pair<ll,ll> > g[n+10];   

    for(int i=0 ; i<r ; i++){
        int s,d,w;
        cin>>s>>d>>w;
        g[s].push_back(make_pair(d,w));
        g[d].push_back(make_pair(s,w));
    }

    d[x] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, less<pair<ll,ll> > > pq;
    pq.push(make_pair(0,x));

    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        for(auto i : g[p.second]){
            if(d[i.first] > d[p.second] + i.second){
                d[i.first] = d[p.second] + i.second;
                pq.push(make_pair(d[i.first],i.first));
            }
        }
    }

    if(d[y] <= m) cout<<"alive "<<d[y]<<endl;
    else cout<<"died"<<endl;

    return 0;
}