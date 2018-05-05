#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int w;
        string s;
        vector<string> days;
        vector<int> freq(8,4);
        cin>>w>>s;
        days.push_back("null");
        days.push_back("mon");
        days.push_back("tues");
        days.push_back("wed");
        days.push_back("thurs");
        days.push_back("fri");
        days.push_back("sat");
        days.push_back("sun");
        int extra = w - 28;
        for(int i=1 ; i<=7 ; i++){
            if(days[i] == s){
                for(int j=i ; j<i+extra ; j++){
                    freq[j%8 + j/8]++;
                }
                break;
            }
        }
        for(int i=1 ; i<=7 ; i++) cout<<freq[i]<<" ";
        cout<<endl;
    }
    return 0;
}
