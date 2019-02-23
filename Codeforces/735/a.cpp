#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    string str;
    cin>>str;
    int n = str.length();
    int p, q;
    for(int i=0 ; i<n ; i++){
        if(str[i] == 'T'){
            p = i;
        }
        if(str[i] == 'G'){
            q = i;
        }
    }

    if(abs(p-q) % k == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}