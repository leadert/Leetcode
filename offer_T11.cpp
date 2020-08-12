#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& nums) {
		if (nums.empty())	return -1;
		int start = 0, end = nums.size() - 1;
		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[end])
				end = mid;
			else if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end -= 1;
		}
		return nums[end];
	}
};

//int main() {
//	vector<int> nums{ 2,2,2,0,1 };
//	int ans = Solution().minArray(nums);
//	cout << ans << endl;
//	return 0;
//}