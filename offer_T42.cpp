#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int subArraySum(vector<int>& nums) {
		int maxSum = 0;

		int tmpCount = nums[0];
		int nLength = nums.size();
		for (int i = 1; i < nLength; i++) {
			if (tmpCount <= 0) {
				if (nums[i] > tmpCount) {
					tmpCount = nums[i];
					maxSum = max(maxSum, tmpCount);
				}
				else
				{
					tmpCount = nums[i];
				}
			}

			else {
				tmpCount += nums[i];
				maxSum = max(maxSum, tmpCount);
			}
		}

		return maxSum;
	}
};


//int main() {
//	vector<int> nums{ 1,-2,3,10,-4,7,2,-5 };
//	int ans = Solution().subArraySum(nums);
//	cout << ans;
//
//	return 0;
//}