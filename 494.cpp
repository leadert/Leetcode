#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int len = nums.size();

		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += nums[i];
		}
		if (sum < S)    return 0;
		if ((sum + S) % 2 == 1)	return 0;
		//数组中负号元素的和为target，找到数组中和为target的子数组的个数
		int target = (sum + S) / 2;
		//dp数组含义，前i个元素其和为j的子数组个数
		vector<vector<int>> dp(len, vector<int>(target + 1, 0));
		for (int i = 0; i < len; i++) {
			dp[i][0] = 1;
		}

		for (int j = 1; j <= target; j++) {
			dp[0][j] = (nums[0] == j ? 1 : 0);
		}

		if (nums[0] == 0)
			dp[0][0] = 2;

		for (int i = 1; i < len; i++) {
			for (int j = 0; j <= target; j++) {
				if (j < nums[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					if (nums[i] == 0) {
						dp[i][j] = dp[i - 1][j] * 2;
					}
					else {
						dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
					}
				}
			}
		}
		return dp[len - 1][target];
	}
};