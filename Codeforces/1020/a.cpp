#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,h,a,b,k;
ll cost;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h>>a>>b>>k;

    for(int i=0 ; i<k ; i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cost = 0;
        if(x1 == x2) cost += abs(y1-y2);
        else{
            cost += abs(x1-x2);
            if(abs(y1-a) <= abs(y1-b)){
                cost += abs(y1-a);
                cost += abs(y2-a);
            }else{
                cost += abs(y1-b);
                cost += abs(y2-b);
            }
        }
        cout<<cost<<endl;
    }

    return 0;
}