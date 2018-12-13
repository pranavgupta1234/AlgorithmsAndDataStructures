#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    string s,t;
    cin>>s>>t;
    
    for(int x=0 ; x<q ; x++){
        int a,b;
        cin>>a>>b;
        int i=a-1,j=a-1;
        int ans = 0;
        while(i<b){
            int c=0;
            if(j <= i) j = i;
            while(j<b and s[j] == t[c]){
                c++;
                j++;
            }
            if(c == t.length()) ans++;
            i++;
        }       
        cout<<ans<<endl; 
    }


    return 0;
}