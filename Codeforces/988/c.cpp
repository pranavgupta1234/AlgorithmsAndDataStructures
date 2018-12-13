#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cust(tuple<ll,int,int> a,tuple<ll,int,int> b){
    return ( get<0>(a) < get<0>(b) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    cin>>k;
    vector<vector<int> > mat(k,vector<int>());
    vector<ll> sum(k,0);
    for(int i=0 ; i<k ; i++){
        int n;
        cin>>n;
        for(int j=0 ; j<n ; j++){
            int temp;
            cin>>temp;
            mat[i].push_back(temp);
            sum[i] += temp;
        }
    }

    vector<tuple<ll,int,int> > list;

    for(int i=0 ; i<mat.size() ; i++){
        for(int j=0 ; j<mat[i].size() ; j++){
            list.push_back(make_tuple(sum[i]-mat[i][j],i+1,j+1));
        }
    }

    sort(list.begin(),list.end(),cust);

    for(int i=0 ; i<list.size()-1 ; i++){
        if(get<0>(list[i]) == get<0>(list[i+1]) and get<1>(list[i]) != get<1>(list[i+1])){
            cout<<"YES"<<endl;
            cout<<get<1>(list[i])<<" "<<get<2>(list[i])<<endl;
            cout<<get<1>(list[i+1])<<" "<<get<2>(list[i+1])<<endl;
            exit(0);
        }
    }

    cout<<"NO"<<endl;

    return 0;
}