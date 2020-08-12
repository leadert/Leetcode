#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int getFirstIndex(vector<int>& nums, int targetNum, int left, int right) {
		if (left > right)	return -1;
		int mid = left + (right - left) / 2;
		int midData = nums[mid];
		if (midData == targetNum) {
			if ((mid > 0 && nums[mid - 1] != targetNum) || mid == 0)	return mid;
			else right = mid - 1;
		}
		else if (midData > targetNum)	right = mid - 1;
		else left = mid + 1;
		return getFirstIndex(nums, targetNum, left, right);
	}

	int getLastIndex(vector<int>& nums, int targetNum, int left, int right) {
		if (left > right)	return -1;
		int mid = left + (right - left) / 2;
		int midData = nums[mid];
		if (midData == targetNum) {
			if ((mid < nums.size() - 1 && nums[mid + 1] != targetNum) || mid == nums.size() - 1)	return mid;
			else left = mid + 1;
		}
		else if (midData > targetNum)	right = mid - 1;
		else left = mid + 1;
		return getLastIndex(nums, targetNum, left, right);
	}

	int getTargetNumTimes(vector<int>& nums, int targetNum) {
		if (nums.empty())	return 0;
		int n = nums.size();
		int left = getFirstIndex(nums, targetNum, 0, n-1);
		int right = getLastIndex(nums, targetNum, 0, n-1);

		if (left != -1 && right != -1)	return right - left + 1;
		else return 0;
	}
};