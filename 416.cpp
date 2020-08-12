//0-1�������⣬��̬�滮

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
		//dp���麬�壬ǰi�����������飬���ܷ�Ϊsum
		vector<vector<bool>> dp(len, vector<bool>(sum + 1, false));
		//��Ϊ0����Զ����
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