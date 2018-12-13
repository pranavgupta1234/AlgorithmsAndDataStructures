#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a = "qwertyuiop";
    string b = "asdfghjkl;";
    string c = "zxcvbnm,./";    

    char d;
    cin>>d;
    string str;
    cin>>str;
    string ans = "";
    for(int i=0 ; i<str.length() ; i++){
        auto p1 = a.find(str[i]);
        auto p2 = b.find(str[i]);
        auto p3 = c.find(str[i]);
        cout<<p1<<" "<<p2<<" "<<p3<<endl;
        if(p1 != string::npos){ 
            if(d == 'R') ans += a[p1-1];
            else ans += a[p1+1];
        }
        if(p2 != string::npos){
            if(d == 'R') ans += b[p2-1];
            ans += b[p2+1];
        }
        if(p3 != string::npos){
            if(d == 'R') ans += c[p3-1];
            else ans += c[p3+1];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}