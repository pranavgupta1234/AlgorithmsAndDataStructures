#include <bits/stdc++.h>

using namespace std;
int n, poz, l , r;
int main()
{
    cin >> n >> poz >> l >> r;
    if(l - 1 > 0 && n - r > 0)
        cout << min(abs(poz - l), abs(poz - r)) + (r - l) + 1 + 1;
    else if(l - 1 > 0)
        cout << abs(poz - l) + 1;
    else if(n - r > 0)cout << abs(poz - r) + 1;
    else cout << 0;
    return 0;
}