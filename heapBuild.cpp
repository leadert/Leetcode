#include<iostream>
#include<vector>
using namespace std;

void AdjustDown(vector<int>& nums, int k, int len) {
	nums[0] = nums[k];
	for (int i = 2 * k; i <= len; i = i * 2) {
		if (i < len&& nums[i] < nums[i + 1])
			i++;
		if (nums[0] > nums[i])
			break;
		else {
			nums[k] = nums[i];
			k = i;
		}
	}
	nums[k] = nums[0];
}

void BuildMaxHeap(vector<int>& nums) {
	int len = nums.size();
	for (int i = len / 2; i > 0; i--) {
		AdjustDown(nums, i, len);
	}
}

void HeapSort(vector<int>& nums) {
	BuildMaxHeap(nums);
	int len = nums.size();
	for (int i = len-1; i > 0; i--) {
		swap(nums[i], nums[0]);
		AdjustDown(nums, 1, i-1);
	}
}