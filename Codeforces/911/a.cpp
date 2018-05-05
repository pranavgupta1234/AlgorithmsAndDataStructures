#include <bits/stdc++.h>

#define ll long long 
using namespace std;

int n;
int arr[100500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int m = INT_MAX;
    cin>>n;
    for(int i=0 ; i<n ; i++) cin>>arr[i], m = min(m,arr[i]);
    vector<int> pos;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == m) pos.push_back(i+1);
    }
    m = INT_MAX;
    for(int i=0 ; i<pos.size()-1 ; i++) m = min(m,pos[i+1]-pos[i]);
    cout<<m<<endl;
    return 0;
}