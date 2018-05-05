#include <bits/stdc++.h>

#define ll long long 

int n;
int arr[100500];
int h[100500];

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0 ; i<n ; i++) { cin>>arr[i] ; h[arr[i]]++; } 
    sort(arr,arr+n);
    for(int i=n-1 ; i>=0 ; i--){
        if(h[arr[i]]&1) { cout<<"Conan"<<endl; exit(0); }
    }
    cout<<"Agasa"<<endl;
    return 0;
}