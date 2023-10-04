#include <bits/stdc++.h>
using namespace std;
// Approach O(n^2)
int solve(int *arr, int n, vector<int> &dp)
{
    if (n == 0)
        return arr[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int pick = arr[n] + solve(arr, n - 2, dp);
    int unpick = solve(arr, n - 1, dp);
    return dp[n] = max(pick, unpick);
}
// Approach O(n) O(n)
int findMaxSum2(int *arr, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int unpick = dp[i - 1];
        dp[i] = max(pick, unpick);
    }
    return dp[n - 1];
}
// Approach O(n) O(1)
int findMaxSum3(int *arr, int n)
{
    int prev = arr[0], prev2 = 0, cur = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int unpick = prev;
        cur = max(pick, unpick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int findMaxSum(int *arr, int n)
{
    vector<int> dp(n + 1, -1);
    return solve(arr, n - 1, dp);
}
int main()
{
    int h[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << findMaxSum(h, 8);
    cout << findMaxSum2(h, 8);
    cout << findMaxSum3(h, 8);

    return 0;
}