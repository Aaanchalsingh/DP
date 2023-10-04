#include <bits/stdc++.h>
using namespace std;
int frogJump(int ind, vector<int> &height)
{
    int cur = 0, prev = 0, prev2 = 0;

    for (int i = 1; i < ind; i++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        cur = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int frogJump2(int ind, vector<int> &height){
    vector<int> dp(ind+1,-1);
    dp[0]=0;
    for(int i=1;i<ind;i++){
         int jumpTwo = INT_MAX;
         int jumpOne= dp[i-1]+ abs(height[i]-height[i-1]);
        if(i>1)
            jumpTwo = dp[i-2]+ abs(height[i]-height[i-2]);
        dp[i]=min(jumpOne, jumpTwo);
    }
    return dp[ind-1];
}

int main()
{
    vector<int> h{1, 2, 3, 4, 5, 6, 7, 8};
    cout << frogJump(8, h);
    cout << frogJump2(8, h);
    return 0;
}