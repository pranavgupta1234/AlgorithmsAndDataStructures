#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;

    int b = __builtin_popcount(n);
    map<int,int> m;
    
    if(k > n or k < b) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        deque<ll> f;
        int i=0;
        while(n){
            if(n&1){
                if(i > 0) f.push_back(1<<i);
                m[1<<i]++;
            }
            n>>=1;  
            i++;
        }   
        int c = m.size();
        while(c < k and !f.empty()){
            int l = f.front();
            f.pop_front();
            m[l]--;
            m[l/2]+=2;
            if(l/2 > 1){
                f.push_back(l/2);
                f.push_back(l/2);
            }
            c++;
        }
        for(auto x : m){
            for(int j=0 ; j<x.second ; j++){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}