#include <iostream>
#include <cmath>
#include <iomanip>

#define ll long long 

using namespace std;


int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(13);
    long double r;
    int n;
    cin>>r>>n;
    cout<<pow(r,n)<<endl;
    return 0;
}