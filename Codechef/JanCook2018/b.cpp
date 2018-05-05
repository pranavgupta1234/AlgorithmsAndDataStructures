#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll k,sum1= 0,sum2 =0;
        int d0,d1,d,h[15];
        cin>>k>>d0>>d1;
        deque<int> str;
        for(int i=0 ; i<15 ; i++) h[i] = 0;
        ll sum = d0 + d1;
        d = sum % 10;
        str.push_back(d0);
        str.push_back(d1);
        int numdig = 2;
        while(h[d] == 0){
            str.push_back(d);
            numdig++;  
            h[d] = 1;
            sum += d;
            d = sum % 10;
            if(numdig == k){ break;}
        }   
        if(numdig == k){
            cout<<(sum%3 ? "NO" : "YES")<<endl;
        }else{
            sum1= d0+d1 , sum2 = 0;
            bool vis = false;
            ll i;
            for(i=2 ; i<str.size() ; i++){
                if(str[i] == d) break;
                sum1 += str[i];
            }
            sum2 = sum - sum1;
            int blk = (k-i)/(str.size()-i);
            int ext = (k-i)%(str.size()-i);
            sum2 = blk*sum2;
            for(int k=i ; k<i+ext ; k++) sum2 += str[k];
            cout<<((sum1 + sum2) %3 ? "NO" : "YES")<<endl;
        }
    }
    return 0;
}