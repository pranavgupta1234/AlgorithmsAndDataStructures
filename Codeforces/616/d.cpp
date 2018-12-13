#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000009;
int a[maxn], f[maxn], n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1 ; i<=n ; i++) cin>>a[i];   
    int l=1,r=1;
    int x = -1,y = -1;
    int c = 0;
    while(l <= n){
        //r = rest;
        while(r <= n){
            if(++f[a[r]] == 1) c++;
            if(c > k) {
                if(--f[a[r]] == 0) c--;
                break;
            }
            r++;
        }
        //rest = r;
        if(r-l > y-x){
            x = l, y = r;
        }
        if(--f[a[l]] == 0) c--;
        l++;
    }
    if(x < 0 or y < 0) cout<<-1<<endl,exit(0);
    cout<<x<<" "<<y-1<<endl;
    return 0;
}