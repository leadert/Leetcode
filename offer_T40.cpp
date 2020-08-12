#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int>	minKNum(vector<int>& nums, int k) {
		if (nums.empty())	return {};

		vector<int> ans(k);
		priority_queue<int, vector<int>, less<int>>	numQueue;

		if (k > nums.size())	return {-1};
		for (int i = 0; i < k; i++) {
			numQueue.push(nums[i]);
		}

		for (int i = k; i < nums.size(); i++) {
			if (nums[i] < numQueue.top()) {
				numQueue.pop();
				numQueue.push(nums[i]);
			}
		}

		for (int i = 0; i < k; i++) {
			ans[i] = numQueue.top();
			numQueue.pop();
		}

		return ans;
	}
};


//int main() {
//	vector<int> nums = { 2,3,4,3,5,3,5,9,1,7,4,8 };
//	vector<int> ans = Solution().minKNum(nums, 5);
//	for (auto num : ans)
//		cout << num << " ";
//	return 0;
//}