#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

const int MAXN = 303;

int N;

vector<int> ways[MAXN];
vector<int> wr;

bool dfs( int nd, int end, int dad )
{
    if( nd==end )   return true;
    for( int i=0 ; i<sz(ways[nd]) ; i++ )
        if( ways[nd][i] != dad && dfs( ways[nd][i], end, nd ) ){
            wr.pb(nd);
            return true;
        }
    return false;
}

int main()
{
    cin >> N;
    
    for( int i=1,a,b ; i<N ; i++ ){
        scanf(" %d %d",&a,&b);
        ways[a].pb(b);
        ways[b].pb(a);
    }
    
    int prev=1,now;
    wr.pb(1);
    while( scanf(" %d",&now) != EOF ){
        dfs( now, prev, 0 );
        prev = now;
    }
    
    dfs( 1, now, 0 );
    
    if( sz(wr) != 2*N-1 )
        printf("-1");
    else
        for( int i=0 ; i<sz(wr) ; i++ )
            printf("%d ",wr[i]);
    
    puts("");
    
    return 0;
}