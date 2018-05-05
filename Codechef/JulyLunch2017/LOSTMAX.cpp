#include <bits/stdc++.h>

using namespace std;

int comp(int a,int b){ return a>b ; }

int main(){
    int t;
    cin>>t;
    int num;
    while(t--){
        string str;
        getline(cin,str);
        istringstream ss(str);
        vector<int> arr;
        while(ss >> num) { arr.push_back(num); } 
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1 ; i>=0 ; i--){
            if(arr[i] == arr.size()-1) continue;
            cout<<arr[i]<<endl;
            break;
        }
    }    
    return 0;
}