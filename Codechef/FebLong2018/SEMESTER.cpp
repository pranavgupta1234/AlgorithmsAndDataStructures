#include <bits/stdc++.h>

#define ll long long

using namespace std;

map<int,string> d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll days[8];
        ll tot = 0;
        d[1] = "Monday",d[2] = "Tuesday",d[3] = "Wednesday",d[4] = "Thursday",d[5] = "Friday",d[6] = "Saturday",d[7] = "Sunday";
        for(int i=1 ; i<=7 ; i++) cin>>days[i], tot += days[i];
        if(k%tot == 0 and k/tot != 1) k = tot;
        else if(k % tot == 0) k = k;
        else k = k%tot;  
        for(int i=1 ; i<=7 ; i++){
            k -= days[i];
            if(k<=0) { cout<<d[i]<<endl ; break; } 
        }
    }
    return 0;
}