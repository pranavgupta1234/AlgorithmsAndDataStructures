#include <bits/stdc++.h>
#include <iomanip>

#define ll long long
#define dll long double

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    When floatfield is set to fixed, floating-point values are written using fixed-point notation:
    the value is represented with exactly as many digits in the decimal part as specified by the 
    precision field (precision) and with no exponent part.
    */
    cout<<fixed;     
    cout<<setprecision(12);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n,0);
        for(int i=0 ; i<n ; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll sum = 0;
        for(int i=k ; i<arr.size()-k ; i++){
            sum += arr[i];
        } 
        cout<<sum*1.0/(arr.size()-2*k)<<endl;
    }
    return 0;
}