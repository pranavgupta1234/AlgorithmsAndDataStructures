#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n;
int arr[100100];
ll sumpos;
int maxneg = -INT_MAX;
int minpos = INT_MAX;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0 ; i<n ; i++)    { cin>>arr[i]; if(arr[i] > 0) sumpos+= arr[i]; if(arr[i] < 0 and arr[i] > maxneg and arr[i]&1) maxneg = arr[i]; if(arr[i] >0 and arr[i] < minpos and arr[i]&1) minpos = arr[i];}
    if(sumpos & 1) cout<<sumpos<<endl;
    else if(maxneg&1 or minpos&1) cout<<sumpos-min(minpos,-maxneg)<<endl;
    else cout<<-1<<endl;
    return 0;
}