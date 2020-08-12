// 不修改数组找出重复的数字
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int countRange(vector<int>& nums, int length, int begin, int end){
		if (nums.empty()) return 0;
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (nums[i] >= begin && nums[i] <= end)
				count++;
		}
		return count;
	}

	int duplicateNum(vector<int>& nums) {
		if (nums.empty())	return -1;

		int length = nums.size();
		for (int i = 0; i < length; i++) {
			if (nums[i]<1 || nums[i]>length - 1)
				return -1;
		}

		int begin = 1, end = length - 1;
		while (begin <= end) {
			int mid = (begin + end) >> 1;
			int count = countRange(nums, length, begin, mid);
			if (end > begin) {
				if (count > (mid - begin + 1))
					end = mid;
				else begin = mid + 1;
			}
			else {
				if (count > 1)
					return begin;
				else break;
			}
		}
		return -1;
	}
};

//int main() {
//	vector<int> nums{ 2,3,5,4,6,7,1,3 };
//	int ans = Solution().duplicateNum(nums);
//	cout << ans << endl;
//	return 0;
//}