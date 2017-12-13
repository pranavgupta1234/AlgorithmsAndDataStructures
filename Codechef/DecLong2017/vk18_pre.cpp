#include <iostream>
#include <string>
#include <cstring>

#define range 2000010

using namespace std;

int extra(long i){
    string num = to_string(i);
    int oddsum = 0;
    int evensum = 0;
    for(int j=0 ; j<num.size() ; j++){
        if(num[j] & 1){
            oddsum += num[j] - '0';
        }else{
            evensum += num[j] -  '0';
        }
    }
    return abs(i - abs(oddsum-evensum));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int hash[range];
    memset(hash,0,sizeof(0)*range);
    for(int i=range ; i >= 10 ; i--){
        hash[i] = extra(i);
    }
    while(t--){
        long long n;
        cin>>n;
        long long sum = n*n*(n+1);
        bool flag = true;
        for(long i=2*n,j=1 ; i>=10 ; i--){
    			//cout<<j<<" "<<extra(i)<<endl;
            sum = sum- j*hash[i];
            if(j < n and flag){
                j++;
            }else{
                flag = false;
            }
            if(!flag){
                j--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;	
} 