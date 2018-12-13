#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,a,b,p,e;
    cin>>n>>a>>b;
    string str;
    cin>>str;
    p = min(a,b);
    e = max(a,b)-min(a,b);
    int ans = 0;  
    for(int i=0 ; i<str.length() ; ){
        if(str[i] == '*'){
            i++;
            continue;
        }else{
            int c = 0;
            while(i<n and str[i] != '*') {
                c++;
                i++;
            }
            if(c&1) {
                if(p >= (c-1)/2 and (c-1)/2 != 0) p -= (c-1)/2,ans+=2;
                if(e >= 1) e--,ans++;
                if(p == 0 and e == 0) break;
            }else{
                if(p >= c/2) p -= c/2,ans+=2;
                if(e >= 1) e--,ans++;
                if(p == 0 and e == 0) break;
            }     
        }
    }
    cout<<ans<<endl;
    return 0;
}