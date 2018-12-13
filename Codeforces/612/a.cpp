#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,p,q;
    cin>>n>>p>>q;
    string str;
    cin>>str;
    int x = -1,y = -1;
    bool f = false;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++){
            if(p*i + q*j == n) {
                x = i;
                y = j;
                f = true;
                break;
            }
        }
        if(f) break;
    }
    vector<string> ans;
    if(x < 0 or y < 0) cout<<"-1"<<endl,exit(0);
    string p1(str.begin(),str.begin()+p*x);
    string p2(str.begin()+p*x,str.end());
    //cout<<x<<" "<<y<<endl;
    for(int i=0 ; i<p1.length() ; i+=p){
        string temp(p1.begin()+i,p1.begin()+i+p);
        ans.push_back(temp);
    }

    for(int i=0 ; i<p2.length() ; i+=q){
        string temp(p2.begin()+i,p2.begin()+i+q);
        ans.push_back(temp);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}