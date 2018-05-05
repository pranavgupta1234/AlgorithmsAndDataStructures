#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<vector<map<int,set<int> > >, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> sds;
typedef long long ll;

const ll INF=LONG_LONG_MAX;
#define MAXN 110000
// stores smallest prime factor for every number
int spf[MAXN];
 
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)  spf[j] = i;
        }
    }
}

set<int> getFactorization(ll x){
    set<int> ret;
    while (x != 1){
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int bsearch(int arr[],int l,int h,int val){
    while(l<=h){
        int m = l + (h-l)/2;
        if(arr[m] == val) return m;     
        else if(arr[m] < val) h = m-1;
        else l = m+1; 
    }
    return -1;
}


map<int,set<int> > primehash(ll val){
    set<int> dprimes = getFactorization(val);
    map<int,set<int> > m;
    for(auto it=dprimes.begin() ; it!=dprimes.end() ; it++){
        m[*it].insert(val);
    }
    return m;
}

void build(sds t[],int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v].insert(map<int,set<int> >(primehash(a[tl])));
    } else { 
        int tm = (tl + tr) / 2;
        build(t,a, v*2, tl, tm);
        build(t,a, v*2+1, tm+1, tr);
        for(int i=0 ; i<t[v*2].size() ; i++) t[v].insert(*t[v*2].find_by_order(i));
        for(int i=0 ; i<t[v*2+1].size() ; i++) t[v].insert(*t[v*2+1].find_by_order(i));
        //merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),t[v].begin());
    }
}

ll query(sds t[],int v, int tl, int tr, int l, int r) {
    if(tl > r or tr < l) return INF;
    if(l <= tl and r >= tr){
        for(int i=0 ; i<t[v].size() ; i++){
            cout<<*t[v].find_by_order(i)<<" ";
        }
        cout<<endl;   
        return INF;
    }
    int tm = (tl + tr) / 2;
    return max(query(t,v*2,tl,tm,l,r),query(t,v*2+1, tm+1,tr,l,r));
}

void update(sds t[],int a[],int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t,a,v*2, tl, tm, pos, new_val);
        else
            update(t,a,v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    arr[0]=0;
    for(int i=1 ; i<=n ; i++) cin>>arr[i];
    sieve();
    sds tree[3*n];
    build(tree,arr,1,1,n);
/*     for(int i=1 ; i<=2*n ; i++){
        for(int j=0 ; j<tree[i].size() ; j++){
            cout<<*tree[i].find_by_order(j)<<" ";
        }
        cout<<endl;
    } */
    while(q--){
        int typ;
        cin>>typ;
        if(typ == 1){
            int x,y;
            cin>>x>>y;
            update(tree,arr,1,1,n,x,y);
        }else{
            int l,r;
            cin>>l>>r;
            query(tree,1,1,n,l,r);
        }
    }
    return 0;
} 
