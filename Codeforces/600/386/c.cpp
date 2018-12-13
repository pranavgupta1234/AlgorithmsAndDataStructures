#include <bits/stdc++.h>

using namespace std;

int f[30];
int cnt[30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin>>str;
    int n = str.length();
    for(int i=1 ; i<=26 ; i++){
        int l=0,r=0;
        int c = 0, sub = 0;
        for(int j=0 ; j<30 ; j++) f[j] = 0;
        while(l < n){
            int cnt = 0;
            while(r < n){
                if(++f[str[r]-'a'] == 1) c++;
                if(c == i) cnt++;
                if(c > i){
                    if(--f[str[r]-'a'] == 0) c--;
                    break;
                }
                r++;
            }            
            if(c == i) sub += cnt;
            if(--f[str[l]-'a'] == 0) c--;
            l++;
        }
        cnt[i] = sub;
    }

    for(int i=0 ; i<=26 ; i++) cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}