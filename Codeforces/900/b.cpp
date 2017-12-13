#include <bits/stdc++.h>
using namespace std;
 
long long firstOccurence(int numr, int denr,int search){
    string res;
    long long index = 1;
    map <int, int> mp;
    mp.clear();
    bool flag = false;
    long long rem = numr%denr;
    while (mp.find(rem) == mp.end()){
        mp[rem] = res.length();
        rem = rem*10;
        long long res_part = rem / denr;
        res += to_string(res_part);
        rem = rem % denr;
        if(res_part == search){
            return index;
        }
        index++;
    }
    return -1;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<firstOccurence(a,b,c)<<endl;
    return 0;
}