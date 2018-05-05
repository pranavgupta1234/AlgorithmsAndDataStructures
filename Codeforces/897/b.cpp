#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll k,p;
ll sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>p;
    for(int i=1 ; i<=k ; i++){
        string str = to_string(i);
        string rev(str);
        reverse(rev.begin(),rev.end());
        string con = str + rev;
        stringstream ss;
        ss<<con;
        ll num;
        ss>>num;
        sum = sum%p;
        sum = (sum+num%p)%p;
    }
    cout<<sum<<endl;
    return 0;
}