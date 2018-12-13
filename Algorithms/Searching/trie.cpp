#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define maxx 100100

ll trie[maxx][26];
ll finish[maxx];
ll nxt = 1;

void add(string s){
    ll node = 0;
    for(ll i = 0; i<s.length() ; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        }
    }
    finish[nxt - 1] = 1;
}

ll find(string s) {
    ll idx = 0;
    for (ll i = 0; i < s.size(); i++)
        if (trie[idx][s[i] - 'a'] == 0)
            return 0;
        else
            idx = trie[idx][s[i] - 'a'];
    return finish[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    



    return 0;
}