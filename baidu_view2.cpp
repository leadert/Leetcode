#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdlib.h>
#include <time.h>
using namespace std;

class Solution {
public:
	int ans;
	void quickSort(vector<int>& nums, int Vecleft, int Vecright) {
		int privot = nums[Vecleft];
		int left = Vecleft+1, right = Vecright;
		while (left <= right) {
			if (nums[left] > privot && nums[right] < privot) {
				swap(nums[left++], nums[right--]);
			}
			if (nums[left] <= privot)	left++;
			if (nums[right] >= privot)	right--;
		}
		swap(nums[Vecleft], nums[right]);
		if (right == (nums.size() / 2)) {
			ans = nums[right];
		}	
		else if (right > nums.size() / 2)	quickSort(nums, Vecleft, right - 1);
		else quickSort(nums, right + 1, Vecright);
	}

	int getMidNum(vector<int>& nums) {
		if (nums.empty())	return -1;
		int nLength = nums.size();
		quickSort(nums, 0, nLength-1);
		return ans;
	}
};

vector<int> generateVec(int n) {
	vector<int>	nums(n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		nums[i] = rand();
	}
	
	return nums;
}


//int main() {
//	vector<int> nums = generateVec(10);
//	for (auto x : nums) {
//		cout << x << " ";
//	}
//	cout << endl;
//	vector<int> tmpNums = nums;
//	
//	sort(nums.begin(), nums.end());
//	for (auto x : nums) {
//		cout << x << " ";
//	}
//	cout << endl;
//	cout << nums[5] << endl;
//
//	int ans = Solution().getMidNum(tmpNums);
//	cout << ans << endl;
//
//	return 0;
//}