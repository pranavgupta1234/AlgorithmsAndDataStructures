#include <bits/stdc++.h>

using namespace std;

int k;
int arr[26];
int m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    for(int i=0 ; i<k ; i++){
        cin>>arr[i];
        m = max(m,arr[i]);
    }   

    if(m <= 25) cout<<0<<endl;    
    else cout<<m-25<<endl;
}