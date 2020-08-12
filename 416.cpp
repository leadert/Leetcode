//0-1背包问题，动态规划

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int len = nums.size();

		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += nums[i];
		}

		if (sum % 2 == 1)	return false;
		sum = sum / 2;
		//dp数组含义，前i个数的子数组，和能否为sum
		vector<vector<bool>> dp(len, vector<bool>(sum + 1, false));
		//和为0，永远成立
		for (int i = 0; i < len; i++) {
			dp[i][0] = false;
		}

		for (int i = 1; i < len; i++) {
			for (int j = 1; j <= sum; j++) {
				if (j < nums[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - nums[i]] | dp[i - 1][j];
				}
			}
		}

		return dp[len - 1][sum];
	}
};