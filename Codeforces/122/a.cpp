    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    bool lucky(ll n){
        string num = to_string(n);
        for(int i=0 ; i<num.length() ; i++){
            if(num[i] != '4' and num[i] != '7') return false;
        }
        return true;
    }

    int main(){ 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        ll n;
        cin>>n;
        for(int i=1 ; i*i<=n ; i++){
            if(n%i == 0){
                if(lucky(i) or lucky(n/i)){
                    cout<<"YES"<<endl;
                    exit(0);
                }
            } 
        }

        cout<<"NO"<<endl;

        return 0;
    }