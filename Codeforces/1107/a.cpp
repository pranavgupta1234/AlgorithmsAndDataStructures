#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string str;
        cin>>str;

        if(n == 2){
            if(str[0] >= str[1]){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
                cout<<2<<endl;
                cout<<str[0]<<" "<<str[1]<<endl;
            }
            continue;
        }

        cout<<"YES"<<endl;
        cout<<2<<endl;
        string sec(str.begin()+1, str.end());
        cout<<str[0]<<" "<<sec<<endl;
    }

    return 0;
}