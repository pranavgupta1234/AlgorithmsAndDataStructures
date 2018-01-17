#include <bits/stdc++.h>

#define ll long long 
#define ull unsigned long long
using namespace std;

int n,pos,l,r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>pos>>l>>r;
    if(l==1 and r == n)   cout<<0<<endl;
    else if(l == r and  r == pos){
        if(l==1 or r == n)    cout<<1<<endl;
        else cout<<2<<endl;
    }
    else if(l==1)        cout<<abs(pos-r)+1<<endl;
    else if(r == n)      cout<<abs(pos-l)+1<<endl;
    else if(pos > r)      cout<<(pos-l+2)<<endl;
    else if(pos < l)    cout<<(r-pos+2)<<endl;
    else {
        int dl = pos - l;
        int dr = r - pos;
        if(dl == 0 and dr==0)  cout<<0<<endl;
        else if(dl == 0) cout<<abs(pos-r)+1<<endl;
        else if(dr == 0) cout<<abs(pos-l)+1<<endl;
        else if(dl < dr) cout<<abs(pos-l)+1+abs(r-l)+1<<endl;
        else if(dl > dr) cout<<abs(r-pos)+1+abs(r-l)+1<<endl;
        else cout<<abs(pos-l)+1+abs(r-l)+1<<endl;
    }
}