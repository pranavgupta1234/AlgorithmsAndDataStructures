#include <bits/stdc++.h>

using namespace std;

int n;
string s[55];
int m,p;
int c = INT_MAX;

bool equal(deque<char>& a,string& b){
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int convert(string& a,string& b){
    deque<char> p(a.length());
    for(int i=0 ; i<a.length() ; i++) p[i] = a[i];
    int sizet = a.length();
    int i = 0;
    while(i<sizet){
        if(equal(p,b)) return i;
        i++;
        char frnt = p.front();
        p.pop_front();
        p.push_back(frnt);
    }
    return -1;
}

int main(){
    cin>>n;
    for(int i=0 ; i<n ; i++) cin>>s[i];
    for(int i=0 ; i<n ; i++){
        m = 0;
        for(int j=0 ; j<n ; j++){
            if(i!=j){   
                p = convert(s[j],s[i]);
                if(p!=-1) m+=p;
                else break;
            }   
        } 
        if(p==-1) break;
        else c = min(m,c);
    } 
    cout<<(p !=-1 ? c : -1)<<endl;
    return 0;
}