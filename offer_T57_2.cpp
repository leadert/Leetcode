#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>	ans;
		if (target < 3) {
			ans.push_back({ target });
			return ans;
		}

		for (int left = 1, right = 2; left < right && left < (target / 2);) {
			int sum = (left + right) * (right - left + 1) / 2;
			if (sum == target) {
				vector<int>	res;
				for (int i = left; i <= right; i++) {
					res.push_back(i);
				}
				ans.push_back(res);
				left++;
			}
			else if (sum < target) right++;
			else left++;
		}

		return ans;
	}
};