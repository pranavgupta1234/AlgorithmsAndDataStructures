#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin>>str;
    set<deque<char> > s;
    deque<char> dq(str.begin(),str.end());

    for(int i=0 ; i<str.length() ; i++){
        char a = dq.back();
        dq.pop_back();
        dq.push_front(a);
        s.insert(dq);
    }

    cout<<s.size()<<endl;


    return 0;
}