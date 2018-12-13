#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    vector<int> a(6,0);
    for(int i=0 ; i<6 ; i++) cin>>a[i],sum += a[i];
    if(sum & 1) cout<<"NO"<<endl,exit(0);
    for(int i=0 ; i<6 ; i++){
        for(int j=i+1 ; j<6 ; j++){
            for(int k=j+1 ; k<6 ; k++){
                if(a[i] + a[j] + a[k] == sum>>1){
                    cout<<"YES"<<endl;
                    exit(0);
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}