#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll n,k;
vector<ll> pows;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    bitset<100> bitn(n);
    for(int i=0 ; i<100 ; i++) if(bitn[i] == 1) pows.push_back(i);
    bool poss = false;
    for(int i=0 ; i<pows.size() ; i++) cout<<pows[i]<<" ";
    cout<<endl;
    //cout<<bitn<<endl;
    if(pows.size() == k) poss = true;
    if(pows.size() < k){
        for(int i=pows.size()-1 ; i>=0 ; i--){
            ll addt = pows[i];
            pows.erase(pows.begin()+i);
            pows.push_back(addt-1);
            pows.push_back(addt-1);
            if(pows.size() == k){
                poss = true;
                break;
            }
        }
    }
    cout<<pows.size()<<endl;
    sort(pows.begin(),pows.end());
    if(poss){
        cout<<"Yes"<<endl;
        for(int i=pows.size()-1 ; i>=0 ; i--) cout<<pows[i]<<" ";
        cout<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}