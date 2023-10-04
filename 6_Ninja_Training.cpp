// NINJA'S TRAINING
#include <bits/stdc++.h>
using namespace std;
int f1(int n, int last, vector<vector<int>> &dp, vector<vector<int>> &p)
{
    int maxi = 0;
    if (p[n][last] != -1)
        return p[n][last];
    if (n == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, dp[0][i]);
            }
        }
        return p[n][last] = maxi;
    }
    maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int points = dp[n][i] + f1(n - 1, i, dp, p);
            maxi = max(maxi, points);
        }
    }
    return p[n][last] = maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> p(n, vector<int>(4, -1));
    return f1(n - 1, 3, points, p);
}
int f(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(p[0][1], p[0][2]);
    dp[0][1] = max(p[0][0], p[0][2]);
    dp[0][2] = max(p[0][1], p[0][0]);
    dp[0][3] = max(p[0][1], max(p[0][2], p[0][0]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = p[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int f2(int n, vector<vector<int>> &p)
{
    vector<int> prev(4, 0);
    prev[0] = max(p[0][1], p[0][2]);
    prev[1] = max(p[0][0], p[0][2]);
    prev[2] = max(p[0][1], p[0][0]);
    prev[3] = max(p[0][1], max(p[0][2], p[0][0]));
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = p[day][task] + prev[task];
                    temp[last] = max(temp[last], points);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    cout << maximumPoints(points, n) << " ";
    cout << f(n, points) << " ";
    cout << f2(n, points) << " ";

    return 0;
}