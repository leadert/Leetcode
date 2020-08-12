#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())   return 0;
        int len = nums.size();

        vector<int> dp(len);
        for (int i = 0; i < len; i++) {
            if (i == 0)
                dp[i] = nums[0];
            else if (i == 1)
                dp[i] = max(nums[0], nums[1]);
            else
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[len - 1];
    }
};