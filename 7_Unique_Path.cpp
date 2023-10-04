#include <bits/stdc++.h>
using namespace std;
// RECURRENCE RELATION
int f(int i, int j, int a, int b, vector<vector<int>> &dp)
{

    if (i >= a || j >= b)
        return 0;
    if (i == (a - 1) && j == (b - 1))
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = f(i, j + 1, a, b, dp);
    int down = f(i + 1, j, a, b, dp);
    return dp[i][j] = right + down;
}
int NumberOfPath(int a, int b)
{
    vector<vector<int>> v(a, vector<int>(b, -1));
    return f(0, 0, a, b, v);
}
// MEMOIZATION
int NumberOfpath(int a, int b)
{
    int dp[a + 1][b + 1];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[a - 1][b - 1];
}
int main()
{
    cout << NumberOfPath(2, 2);
    cout << NumberOfpath(2, 2);
    return 0;
}