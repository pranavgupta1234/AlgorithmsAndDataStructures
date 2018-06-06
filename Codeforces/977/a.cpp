#include <bits/stdc++.h>

using namespace std;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1 ; i<=k ; i++){
        string str = to_string(n);
        if(str[str.length()-1] == '0') n /= 10;
        else n--;
    }
    cout<<n<<endl;
    return 0;
}