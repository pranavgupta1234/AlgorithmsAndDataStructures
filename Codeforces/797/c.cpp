#include <bits/stdc++.h>

#define ll long long

using namespace std;

deque<char> t;
string u="";
int h[26];

int main(){
    string s;
    cin>>s;
    for(int i=0 ; i<s.length() ; i++) h[s[i]-'a']++;
    for(int i=0 ; i<s.length() ; i++)   {
        t.push_front(s[i]);
        bool f = false;
        int j;
        while()
    }
    cout<<u<<endl;
    return 0;
}