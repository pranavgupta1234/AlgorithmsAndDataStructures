#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,k;
ll sec;
int arr[100100];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    int m = INT_MAX;
    for(int i=0 ; i<n ; i++)cin>>arr[i],m=min(m,arr[i]);
    for(int i=0 ; i<n ; i++){
        if((arr[i] - m) % k != 0) cout<<-1<<endl,exit(0);
        else sec += (arr[i]-m)/k;
    }   
    cout<<sec<<endl;
    return 0;
}
