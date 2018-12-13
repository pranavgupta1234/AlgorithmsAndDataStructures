#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b,c;
    cin>>a>>b>>c;

    if(c % __gcd(a,b) != 0) cout<<-1<<endl;
    else{
        int x,y;
        int g = gcd(a,b,x,y);
        cout<<(-1)*x*(c/g)<<" "<<(-1)*y*(c/g)<<endl;
    }

    return 0;
}