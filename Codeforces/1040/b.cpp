#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> ans;
    int s = min(n,k+1);
    ans.push_back(s);
    while(s < n){
        s += 2*k+1;
        ans.push_back(s);
        if(s >= n) break;
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
    if(ans[ans.size()-1] > n){
        int d = min(ans[ans.size()-1] - n,ans[0]-1);
        for(int i=0 ; i<ans.size() ; i++){
            ans[i] = ans[i] - d;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}