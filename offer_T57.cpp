#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int sum = nums[left] + nums[right];
			if (sum == target)	return vector<int>{nums[left], nums[right]};
			else if (sum > target)	right--;
			else left++;
		}

		return vector<int>{target / 2, target / 2};
	}
};