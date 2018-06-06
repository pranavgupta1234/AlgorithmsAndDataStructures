#include <bits/stdc++.h>

using namespace std;


int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    vector<int> les(arr.begin(),arr.begin()+k);
    for(int i=0 ; i<les.size() ; i++){
        if(binary_search(arr.begin()+k,arr.end(),les[i])){
            cout<<"-1"<<endl;
            exit(0);
        } 
    }
    if(k == 0){
        if(arr[0] == 1) cout<<-1<<endl;
        else cout<<arr[0]-1<<endl;
    }else cout<<les[les.size()-1]<<endl;
    return 0;
}