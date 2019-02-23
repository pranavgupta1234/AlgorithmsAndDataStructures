#include <bits/stdc++.h>

using namespace std;

#define N 100100
typedef long long ll;

vector<ll> a(N, 0);
vector<vector<ll> > dp(N, vector<ll>(5, 0));

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);  
    cout.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    


    return 0;
}