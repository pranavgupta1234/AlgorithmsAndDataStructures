#include <bits/stdc++.h>

using namespace std;

#define maxn 10000000

string str;
int f[260] = {maxn};
int done[260];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>str;
    n = str.length();
    for(int i=0 ; i<n ; i++) f[str[i]] = min(f[str[i]],i);
    int ans = INT_MAX;
    for(char y='a'; y<='z' ; y++){
        int mx = 1;
        if(f[y] != maxn and done[y] == 0){
            int l=f[y],r=f[y];
            while(l<n){
                char x = str[l]; 
                while(r<n){
                    if(str[r] == x) break;
                    r++;
                }
                mx = max(mx,r-l);
                l = r;
                if(str[r] == x) r++;
            }
            ans = min(ans,mx);
            done[y] = 1;
        }
    }
    if(ans == n) cout<<n/2 +1<<endl;
    else cout<<ans<<endl;
    return 0;
}