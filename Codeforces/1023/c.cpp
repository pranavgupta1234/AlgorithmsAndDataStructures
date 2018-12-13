#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,cnt = 0;
    cin>>n>>m;
    string str,ans="";
    cin>>str;
    m>>=1;
    for(int i=0 ; i<n ; i++){
        if(str[i] == '('){
            cnt++;
            ans += '(';
            if(cnt >= m){
                while(ans.length() < 2*m) ans += ')';
                break;
            }
        }else{
            ans += ')';
        }
    }
    cout<<ans<<endl;
    return 0;
}