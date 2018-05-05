#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool sumhalf(vector<int>& s,int sum){
    bool dp[s.size()+1][sum+1];
    for(int i=0 ; i<=s.size() ; i++) for(int j=0 ; j<=sum ; j++) dp[i][j] = false;
    for(int i=0 ; i<=s.size() ; i++) dp[i][0] = true;
    for(int i=1 ; i<=s.size() ; i++){
        for(int j=1 ; j<=sum ; j++){
            if(s[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] or dp[i-1][j-s[i-1]]; 
        }
    }
    return dp[s.size()][sum];
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    string str;
    while(getline(cin,str)){
        if(str=="0 0 0 0 0 0") break;
        vector<int> hash;
        vector<int> s;
        int sum = 0;
        for(int i=0 ; i<str.size() ; i++)   if(str[i] != ' ') hash.push_back(str[i]-'0');
        for(int i=0 ; i<hash.size() ; i++) for(int j=0 ; j<hash[i] ; j++) s.push_back(i+1);
        for(int i=0 ; i<s.size() ; i++) sum+=s[i];
        cout<<"Collection #"<<t++<<":"<<endl;
        if(sum&1) cout<<"Can't be divided."<<endl<<endl;
        else cout<<(sumhalf(s,sum/2) ? "Can be divided." : "Can't be divided.")<<endl<<endl;
    }       

    return 0;
}