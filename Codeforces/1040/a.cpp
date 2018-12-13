#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin>>n>>a>>b;
    int c[2];
    c[0] = a;
    c[1] = b;
    vector<int> arr(n,0);
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    int i=0,j=n-1;
    int cost = 0;
    
    while(i <= j){
        if((arr[i] == 1 and arr[j] == 0 ) or (arr[i] == 0 and arr[j] == 1)){
            cout<<-1<<endl;
            exit(0);
        }
        if(arr[i] == 2 and arr[j] == 2){
            if(i == j) cost += min(c[0],c[1]);
            else cost += 2*min(c[0],c[1]);
        }
        else if(arr[i] == 2) cost += c[arr[j]];
        else if(arr[j] == 2) cost += c[arr[i]];
        i++,j--;
    }

    cout<<cost<<endl;

    return 0;
}