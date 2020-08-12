// 数组中重复的数字
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int duplicateNum(vector<int>& nums) {
		int n = nums.size();
		for (auto num : nums) {
			if (num<0 || num>n - 1) {
				return -1;
			}
		}

		for (int i = 0; i < n; i++) {
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) {
					return nums[i];
				}
				swap(nums[i], nums[nums[i]]);
			}
		}
		return -1;
	}
};

//int main() {
//	vector<int> nums{ 2, 3, 1, 0, 2, 5, 3 };
//	int ans = Solution().duplicateNum(nums);
//	cout << ans << endl;
//	return 0;
//}
