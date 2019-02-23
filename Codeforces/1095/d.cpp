#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin>>n;
    
    vector<ll> ans(n+1, 0);
    
    map<ll, pair<ll,ll> > m;
    
    for(int i=1 ; i<=n ; i++){
        cin>>m[i].F>>m[i].S;   
    }

    int i=1;
    bool f=true;

    while(i != 1 and f){
        int poss1 = m[i].F;
        int poss2 = m[i].S;

        if(m[poss1].F == poss2 or m[poss1].S == poss2){
            
        }

    }


    return 0;
}