#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll n;
ll arr[11000];

bool is_perfect_square(ll n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=n-1 ; i>=0 ; i--){
        if(!is_perfect_square(arr[i])){
            cout<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}