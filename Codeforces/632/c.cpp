#include <bits/stdc++.h>

using namespace std;

bool sortit(string a,string b){
    for(int i=0 ; i<min(a.length(),b.length()) ; i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
        else continue;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    sort(a.begin(),a.end(),sortit);

    for(int i=0 ; i<a.size() ; i++) cout<<a[i];
    cout<<endl;

    return 0;
}