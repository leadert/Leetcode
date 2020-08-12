#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int getMissNumber(vector<int>& nums, int left, int right) {
		if (left == nums.size())
			return nums.size();

		int mid = left + (right - left) / 2;
		if (nums[mid] != mid) {
			if (mid == 0 || nums[mid - 1] == mid - 1)
				return mid;
			right = mid - 1;
		}
		else left = mid + 1;

		return getMissNumber(nums, left, right);
	}


	int missingNumber(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		int ans = getMissNumber(nums, left, right);
		return ans;
	}
};