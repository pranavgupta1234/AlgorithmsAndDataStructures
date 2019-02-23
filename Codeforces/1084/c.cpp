#include <bits/stdc++.h>

using namespace std;

#define m 1000000007

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    string ref = "";
    int n = str.length();
    int i=0, j=0;
    for(int i=0 ; i<n ; i++){
        if(str[i] == 'a' or str[i] == 'b') ref += str[i];
    }
    ll ans = 1;
    n = ref.length();
    while(i < n){
        if(ref[i] == 'b'){
            i++;
            continue;
        }
        j = i+1;
        while(j < n and ref[j] == 'a'){
            j++;
        }
        ans = (ans*(j-i+1))%m;
        ans = ans%m;
        while(j < n and ref[j] == 'b'){
            j++;
        }
        i = j;
    }
    cout<<ans-1<<endl;
    return 0;
}
