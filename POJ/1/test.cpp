#include <cstdio>
#include <algorithm>
using namespace std;
int dp[6*20001];
int main()
{
    int n[7], Case = 1;
    while (1) {
        // Input
        int sum = 0;
        for (int i = 1; i <= 6; ++i) {
            scanf("%d", &n[i]);
            sum += (i*n[i]);
        }
        if (!sum) break;
        printf("Collection #%d:\n", Case++);

        // Knapsack
        if (sum & 1) puts("Can't be divided.\n");
        else {
            sum /= 2;
            fill(dp, dp+sum+1, 0);
            for (int i = 1; i <= 6; ++i) {
                int left = n[i];
                for (int j = 1; j <= left; left -= j, j *= 2)
                    for (int k = sum; k - i*j >= 0; --k)
                        dp[k] = max(dp[k], dp[k-i*j] + i*j);
                for (int j = 0; j < left; ++j)
                    for (int k = sum; k - i >= 0; --k)
                        dp[k] = max(dp[k], dp[k-i] + i);
            }
            if (dp[sum] == sum) puts("Can be divided.\n");
            else puts("Can't be divided.\n");
        }
    }
}