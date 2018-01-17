#include <bits/stdc++.h>
#include <numeric>

#define ll long long
#define ull unsigned long long

using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    vector<int> players(n);
    iota(players.begin(),players.end(),1);
    int curr = 0;
    while(k--){
        int a;
        cin>>a;
        curr = (curr + a)%players.size();
        cout<<players[curr]<<" ";
        players.erase(players.begin()+curr);
        curr = curr % players.size();
    }
    cout<<"\n";
    return 0;
}