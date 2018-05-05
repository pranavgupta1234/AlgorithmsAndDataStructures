#include <bits/stdc++.h>
#include <iomanip>

#define ll long long
#define dll long double

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(12);
    int t;
    cin>>t;
    while(t--){
        ll n,c,d,s;
        cin>>n;
        ll a[n];
        for(int i=0 ; i<n ; i++) cin>>a[i];
        cin>>c>>d>>s;
        dll fst = a[0],lst = c*a[0];
        ll mxa = a[0];
        for(int i=1 ; i<n ; i++){
            if(a[i] > mxa){
                fst += double(d)/s + a[i];
                lst = fst + (c-1)*a[i];
                mxa = a[i];
            }
        }
        cout<<lst-fst<<endl;
    }
    return 0;
}