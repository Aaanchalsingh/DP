#include <bits/stdc++.h>
using namespace std;
int findMaxSum(vector<int> arr)
{
    int n = arr.size();
    int prev = arr[0], prev2 = 0, cur = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i] + prev2;
        int unpick = prev;
        cur = max(pick, unpick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int rob(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    vector<int> t1;
    vector<int> t2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            t1.push_back(arr[i]);
        if (i != n - 1)
            t2.push_back(arr[i]);
    }
    return max(findMaxSum(t1), findMaxSum(t2));
}
int main()
{
    vector<int> h = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << rob(h);
    return 0;
}