#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    string str;
    cin>>str;

    string ans = "";

    int i=0, c = 0;

    while(c < n){
        ans += str[c];
        i++;
        c += i;
    }

    cout<<ans<<endl;



    return 0;
}