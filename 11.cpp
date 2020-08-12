#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size()-1;
		int maxVolume = 0;
		while (left < right) {
			int tmpVolume = (right - left) * min(height[left], height[right]);
			maxVolume = tmpVolume > maxVolume ? tmpVolume : maxVolume;
			if (height[left] < height[right]) left++;
			else right--;
		}
		return maxVolume;
	}
};

//int main() {
//	vector<int> height;
//	height.push_back(1);
//	height.push_back(8);
//	height.push_back(6);
//	height.push_back(2);
//	height.push_back(5);
//	height.push_back(4);
//	height.push_back(8);
//	height.push_back(3);
//	height.push_back(7);
//
//	int res = Solution().maxArea(height);
//	cout << res;
//}