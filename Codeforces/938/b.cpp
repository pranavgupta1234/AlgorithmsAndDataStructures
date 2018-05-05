#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
set<int> val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    cin>>n;
    int i=1;
    int j = 1000000;
    for(int i=1; i<=n ; i++){
        int pos;
        cin>>pos;
        val.insert(pos);
    }
    int t=0;
    while(i<=j){
        t++;
        i++;
        j--;
        auto it = val.find(i) ;
        if(it != val.end()) val.erase(it);
        it = val.find(j);
        if(it != val.end()) val.erase(it);
        if(val.empty())  break;
    }
    cout<<t<<endl;
    return 0;
}