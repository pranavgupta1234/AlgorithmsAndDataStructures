#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll compute_hash(string& s){
    ll p=31;
    ll m = 1e9 + 9;
    ll hash_value = 0;
    ll pow_p = 1;
    for(char c : s){
        hash_value = (hash_value + (c-'a'+1)*pow_p) % m;
        pow_p = (pow_p*p)%m;
    }
    return hash_value;
}

vector<int> rabin_carp(string& s, string& t){   
    const ll p = 31;
    const ll m = 1e9 + 9;  // large prime
    int s1 = s.length(), t1 = t.length();
    vector<ll> p_pow(max(s1,t1));
    p_pow[0] = 1;
    for(int i=1 ; i<max(s1,t1) ; i++){
        p_pow[i] = (p_pow[i-1]*p)%m;
    }
    vector<ll> h(t1+1, 0);
    for(int i=0 ; i<t1 ; i++){
        h[i+1] = (h[i] + (t[i]-'a'+1)*p_pow[i])%m;
    }
    ll h_s = 0;
    for(int i=0 ; i<s1 ; i++){
        h_s = (h_s + (s[i]-'a'+1)*p_pow[i]) % m;
    }
    vector<int> occ;
    for(int i=0 ; i<t1-s1+1 ; i++){
        ll curr_h = (h[i+s1] + m - h[i])%m;
        if(curr_h == h_s*p_pow[i]%m){
            occ.push_back(i);
        }
    }
    return occ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // s -> pattern , t -> text 
    string s,t;
    cin>>s>>t;
    vector<int> occ = rabin_carp(s,t);
    for(int i : occ) cout<<i<<" ";
    cout<<endl;
    return 0;
}