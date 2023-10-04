#include <bits/stdc++.h>
using namespace std;
// O(N) O(N) Approach
int stairs(int n, int *dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// O(N) O(1) Approach
int stairs2(int n)
{
    int prev = 1, prev2 = 1, cur = 0;
    for (int i = 2; i <= n; i++)
    {
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int climbStairs(int n)
{
    int *dp = new int[n + 1];
    return stairs2(n);
}

int main()
{
    cout << climbStairs(5);
    return 0;
}