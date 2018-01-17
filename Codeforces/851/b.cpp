#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long 
#define ld long double

using namespace std;

long double ax,ay,bx,by,cx,cy;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>ax>>ay>>bx>>by>>cx>>cy;    
    ax -= bx,ay-=by,cy-=by,cx-=bx;
    cout<<((cy*ax != ay*cx and ax*ax+ay*ay==cx*cx+cy*cy) ? "Yes" : "No")<<endl;
}
