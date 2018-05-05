#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int n;
int a[2200];
int cnt1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    bool f = false;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        if(a[i] == 1) cnt1++;
    }
    if(cnt1 > 0) cout<<n-cnt1<<endl, exit(0);
    int minl = INT_MAX;
    for(int i=1 ; i<=n ; i++){
        int gcd = a[i];
        for(int j=i ; j<=n ; j++){
            gcd = __gcd(gcd,a[j]);
            if(gcd == 1) minl = min(minl,j-i);
        }
    }    
    if(minl == INT_MAX) cout<<-1<<endl;
    else cout<<minl+n-1<<endl;
    return 0;
}